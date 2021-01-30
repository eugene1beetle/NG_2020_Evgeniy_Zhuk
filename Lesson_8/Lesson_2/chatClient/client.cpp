#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);

    socket = new QTcpSocket();
    ui->sb_port->setRange(0, 65535);

    ui->e_address->setText("127.0.0.1");
    ui->sb_port->setValue(8080);

    connect (ui->b_connect, &QPushButton::clicked, this, &Client::connectToServer);
    connect (ui->b_send, &QPushButton::clicked, this, &Client::send);

    connect (socket, &QTcpSocket::connected, this, &Client::connectedToServer);
    connect (socket, &QTcpSocket::readyRead, this, &Client::receive);

}

Client::~Client()
{
    delete ui;
}

void Client::connectToServer()
{
    QString ip = ui->e_address->text();
    int port = ui->sb_port->value();
    socket->connectToHost(ip, port);

    sendCryptedData(QString("%1 is connected!").arg(ui->e_nickname->text()).toUtf8());
}

void Client::connectedToServer()
{
    ui->stackedWidget->setCurrentWidget(ui->messages);
    ui->statusbar->showMessage("Connected to " + ui->e_address->text());
}

void Client::send()
{
    QString message = ui->e_nickname->text();
    message += ": ";
    message += ui->t_message->toPlainText();
    sendCryptedData(message.toUtf8());
}

void Client::receive()
{
    QString message = QString::fromUtf8(socket->readAll());

    if (message.contains("//NICKS={")) {
        ui->t_messages->setHtml(ui->t_messages->toHtml() + message.split(",}")[1]);
        parseNicknames(message.split(",}")[0]);
        return;
    }

    ui->t_messages->setHtml(ui->t_messages->toHtml() + message);
}

void Client::parseNicknames(QString nicksMessage)
{
    QString nickWithSplitter = nicksMessage.split("{")[1];
//    qDebug() << "nickWithSplitter:" << nickWithSplitter;

    ui->l_users->clear();
    ui->l_users->addItems(nickWithSplitter.split(","));
}

void Client::sendCryptedData(QByteArray data)
{
//    qDebug() << "Original:" << QString::fromUtf8(data);

    int key = 15;

    int counter = 1;
    bool increment = true;
    int iterator = 0;
    for (int b : data) {
        data[iterator] = b + counter;

        if (counter >= key || counter < 1) increment = !increment;

        increment ? counter++ : counter--;
        iterator++;
    }

//    qDebug() << "Crypted:" <<  QString::fromUtf8(data);

    data.prepend(key);

//    qDebug() << "With key:" << QString::fromUtf8(data);

    socket->write(data);
}

