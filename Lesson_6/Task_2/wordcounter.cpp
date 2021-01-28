#include "wordcounter.h"
#include "ui_wordcounter.h"

WordCounter::WordCounter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WordCounter)
{
    ui->setupUi(this);
}

WordCounter::~WordCounter()
{
    delete ui;
}


void WordCounter::on_userInput_textChanged()
{
    QString text = ui->userInput->toPlainText();
    int charCounter = 0;
    int wordCounter = 0;
    for (int i = 0; i < text.length(); i++)
    {
        QChar charAt = text.at(i);
        if ((charAt >= 'A' && charAt <= 'Z') || (charAt >= 'a' && charAt <= 'z'))
        {
            charCounter++;
            continue;
        }
        if (charCounter > 0)
        {
            charCounter = 0;
            wordCounter++;
        }
    }
    if (charCounter > 0)
    {
        charCounter = 0;
        wordCounter++;
    }
    ui->wordsInfo->setText(QString("Words: %1").arg(wordCounter));
}
