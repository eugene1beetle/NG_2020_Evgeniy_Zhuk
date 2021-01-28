#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WordCounter; }
QT_END_NAMESPACE

class WordCounter : public QMainWindow
{
    Q_OBJECT

public:
    WordCounter(QWidget *parent = nullptr);
    ~WordCounter();

private slots:
    void on_userInput_textChanged();

private:
    Ui::WordCounter *ui;
};
#endif // WORDCOUNTER_H
