#include "wordcounter.h"
#include "ui_wordcounter.h"

WordCounter::WordCounter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WordCounter)
{
    ui->setupUi(this);

    connect (ui->userInput, &QTextEdit::textChanged, this, &WordCounter::userInputChange);
}

WordCounter::~WordCounter()
{
    delete ui;
}

void WordCounter::userInputChange()
{
    QString text = ui->userInput->toPlainText();
    ui->wordsInfo->setText(QString("Words: %1").arg( countWords(text) ));
}

bool WordCounter::isLetter(QChar ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int WordCounter::countWords(QString text)
{
    int charCounter = 0, wordCounter = 0;
    for (int i = 0; i < text.length(); i++) {
        if (isLetter( text.at(i) )) {
            charCounter++;
            continue;
        }
        if (charCounter > 0) {
            charCounter = 0;
            wordCounter++;
        }
    }
    if (charCounter > 0) {
        charCounter = 0;
        wordCounter++;
    }
    return wordCounter;
}
