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
    void userInputChange();

private:
    Ui::WordCounter *ui;

    bool isLetter(QChar ch);
    int countWords(QString text);
};
#endif // WORDCOUNTER_H
