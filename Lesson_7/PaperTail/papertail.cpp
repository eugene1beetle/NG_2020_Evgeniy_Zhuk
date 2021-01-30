#include "papertail.h"
#include "ui_papertail.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QColorDialog>

#include <QDebug>

PaperTail::PaperTail(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PaperTail)
{
    ui->setupUi(this);
    connect (ui->b_save, &QPushButton::clicked, this, &PaperTail::save);
    connect (ui->b_load, &QPushButton::clicked, this, &PaperTail::load);
    connect (ui->fontComboBox, &QFontComboBox::currentFontChanged, this, &PaperTail::setFont);
    connect (ui->fontSize, QOverload<int>::of(&QSpinBox::valueChanged), this, &PaperTail::changeFontSize);
    connect (ui->fontWeight, &QComboBox::currentTextChanged, this, &PaperTail::changeFontWeight);
    connect (ui->b_italic, &QPushButton::toggled, this, &PaperTail::changeFontItalic);
    connect (ui->b_underline, &QPushButton::toggled, this, &PaperTail::changeFontUnderline);
    connect (ui->b_changeColor, &QPushButton::clicked, this, &PaperTail::changeColor);


    ui->fontWeight->addItem("Normal");
    ui->fontWeight->addItem("DemiBold");
    ui->fontWeight->addItem("Bold");


    ui->fontSize->setValue(12);
}

PaperTail::~PaperTail()
{
    delete ui;
}

void PaperTail::save()
{
    QString path = QFileDialog::getSaveFileName(this, "Сюда подошел",
                                              "/",
                                              "Всякая хрень (*);;Text files (*.txt)");
    if (path.isEmpty())
        return;

    QFile fileToSave(path);

    // In case if upper part seems to be complicated, you are free to use
    // just
    //
    // QFile fileToSave("/whatewer/path/you/want");
    //
    // and remove all code below
    //

    if (fileToSave.open(QIODevice::WriteOnly)) {

        QTextStream to(&fileToSave);
        to << ui->data->toHtml();

        fileToSave.close();
    } else {
        QMessageBox::warning(this, "Wow, we can't open the file!", fileToSave.errorString());
    }
}

void PaperTail::load()
{
    QString path = QFileDialog::getOpenFileName(this, "Откуда грузить",
                                                "/",
                                                "Всякая хрень (*);;Text files (*.txt)");
    if (path.isEmpty())
        return;

    QFile fileToLoad(path);
    if (fileToLoad.open(QIODevice::ReadOnly)) {

        QTextStream from(&fileToLoad);
        ui->data->setHtml(from.readAll());

        fileToLoad.close();
    } else {
        QMessageBox::warning(this, "Wow, we can't open the file!", fileToLoad.errorString());
    }
}

void PaperTail::setFont()
{
    QFont existingFont = ui->fontComboBox->currentFont();
    existingFont.setPixelSize(ui->fontSize->value());
    ui->data->setCurrentFont(existingFont);
}

void PaperTail::changeFontSize()
{
    QFont existingFont = ui->data->currentFont();
    existingFont.setPixelSize(ui->fontSize->value());
    ui->data->setCurrentFont(existingFont);
}

void PaperTail::changeFontWeight()
{
    QFont existingFont = ui->data->currentFont();

    QString text = ui->fontWeight->currentText();

    if (text == "Normal") existingFont.setWeight(QFont::Normal);
    else if (text == "DemiBold") existingFont.setWeight(QFont::DemiBold);
    else if (text == "Bold") existingFont.setWeight(QFont::Bold);

    ui->data->setCurrentFont(existingFont);
}

void PaperTail::changeFontItalic()
{
    QFont existingFont = ui->data->currentFont();

    existingFont.setItalic(!existingFont.italic());

    ui->data->setCurrentFont(existingFont);
}

void PaperTail::changeFontUnderline()
{
    QFont existingFont = ui->data->currentFont();

    existingFont.setUnderline(!existingFont.underline());

    ui->data->setCurrentFont(existingFont);
}

void PaperTail::changeColor()
{
    int rgba = QColorDialog::getColor().rgba();
    int red = (rgba >> 16) & 0x000000FF;
    int green = (rgba >> 8) & 0x000000FF;
    int blue = rgba & 0x000000FF;

    QString rgbStr = QString("%1, %2, %3").arg(red).arg(green).arg(blue);

    ui->b_changeColor->setStyleSheet(QString("background-color: rgb(%1); border: none;").arg(rgbStr));

    QFont existingFont = ui->data->currentFont();

    ui->data->setStyleSheet(QString("color: rgb(%1)").arg(rgbStr));
}
