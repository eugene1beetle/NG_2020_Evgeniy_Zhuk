#include "calc.h"
#include "ui_calc.h"
#include "QDebug"
#include "math.h"


Calc::Calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calc)
{
    ui->setupUi(this);
}

Calc::~Calc()
{
    delete ui;
}

void Calc::updateLineInput()
{
    ui->line_input->setText(this->strNumber);
}

void Calc::mathAction()
{
    if (values.size() > 1) {
        switch (lastOperation) {
            case '+':
                values.push_front(values.takeFirst() + values.takeFirst());
                break;
            case '-':
                values.push_front(values.takeFirst() - values.takeFirst());
                break;
            case '*':
                values.push_front(values.takeFirst() * values.takeFirst());
                break;
            case '/':
                values.push_front(values.takeFirst() / values.takeFirst());
                break;
        }
    }
}

void Calc::mathButtonClicked(char action)
{
    values.push_back(strNumber.toDouble());
    strNumber = "";

    lastOperation = action;
    mathAction();
    updateLineInput();
}


void Calc::on_btn_0_clicked()
{
    this->strNumber += "0";

    updateLineInput();
}

void Calc::on_btn_1_clicked()
{
    this->strNumber += "1";

    updateLineInput();
}

void Calc::on_btn_2_clicked()
{
    this->strNumber += "2";

    updateLineInput();
}

void Calc::on_btn_3_clicked()
{
    this->strNumber += "3";

    updateLineInput();
}

void Calc::on_btn_4_clicked()
{
    this->strNumber += "4";

    updateLineInput();
}

void Calc::on_btn_5_clicked()
{
    this->strNumber += "5";

    updateLineInput();
}

void Calc::on_btn_6_clicked()
{
    this->strNumber += "6";

    updateLineInput();
}

void Calc::on_btn_7_clicked()
{
    this->strNumber += "7";

    updateLineInput();
}

void Calc::on_btn_8_clicked()
{
    this->strNumber += "8";

    updateLineInput();
}

void Calc::on_btn_9_clicked()
{
    this->strNumber += "9";

    updateLineInput();
}

void Calc::on_btn_equals_clicked()
{
    values.push_back(strNumber.toDouble());

    mathAction();

    lastOperation = '=';

    this->strNumber = QString::number(values.takeLast());

    updateLineInput();
}

void Calc::on_btn_multiple_clicked()
{
    mathButtonClicked('*');
}

void Calc::on_btn_divide_clicked()
{
    mathButtonClicked('/');
}

void Calc::on_btn_plus_clicked()
{
    mathButtonClicked('+');
}

void Calc::on_btn_minus_clicked()
{
    mathButtonClicked('-');
}

void Calc::on_btn_back_clicked()
{
    this->strNumber.resize(strNumber.size() - 1);

    updateLineInput();
}

void Calc::on_btn_equals_3_clicked()
{
    this->strNumber = "";
    this->firstNumber = 0;
    values.clear();

    updateLineInput();
}
