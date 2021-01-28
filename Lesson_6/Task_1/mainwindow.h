#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_firstNum_valueChanged(int arg1);

    void on_secondNum_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
