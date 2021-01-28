#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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




void MainWindow::on_firstNum_valueChanged(int arg1)
{
    ui->result->setText(QString::number(ui->firstNum->value() + ui->secondNum->value()));
}

void MainWindow::on_secondNum_valueChanged(int arg1)
{
    ui->result->setText(QString::number(ui->firstNum->value() + ui->secondNum->value()));
}
