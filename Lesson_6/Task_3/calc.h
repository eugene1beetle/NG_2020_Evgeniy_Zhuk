#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calc; }
QT_END_NAMESPACE

class Calc : public QMainWindow
{
    Q_OBJECT

public:
    Calc(QWidget *parent = nullptr);
    ~Calc();
    QVector<double> values;
    double firstNumber = 0;
    QString strNumber = "";
    char lastOperation;

private slots:
    void updateLineInput();

    void on_btn_0_clicked();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_equals_clicked();

    void on_btn_multiple_clicked();

    void on_btn_divide_clicked();

    void on_btn_plus_clicked();

    void on_btn_minus_clicked();

    void on_btn_back_clicked();

    void on_btn_equals_3_clicked();

private:
    Ui::Calc *ui;
    void mathAction();
    void mathButtonClicked(char action);
};
#endif // CALC_H
