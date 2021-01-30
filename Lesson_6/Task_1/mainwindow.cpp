#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (ui->firstNum, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::firstNumValueChange);
    connect (ui->secondNum, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::secondNumValueChange);

    ui->firstNum->setMinimum(-100);
    ui->firstNum->setMaximum(100);

    ui->secondNum->setMinimum(-100);
    ui->secondNum->setMaximum(100);

    ui->result->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::firstNumValueChange()
{
    ui->result->setText(QString::number( ui->firstNum->value() + ui->secondNum->value() ));
}

void MainWindow::secondNumValueChange()
{
    ui->result->setText(QString::number( ui->firstNum->value() + ui->secondNum->value() ));
}
