#include "servak.h"

Servak::Servak()
{

}

void Servak::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    QByteArray data = client->readAll();

    if (!QString::fromUtf8(data).contains(":")) {
        nicknames.append(QString::fromUtf8(data).split(" ")[0]);
        nickArrayChanged();
    }

    for (QTcpSocket *buffer : clients) {
        buffer->write(data);
    }
}

void Servak::disconnected()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    qDebug() << "Client " << client->peerAddress().toString() << " disconnected!";

    disconnect (client, &QTcpSocket::readyRead, this, &Servak::readyRead);
    disconnect (client, &QTcpSocket::disconnected, this, &Servak::disconnected);

    int toRemove = clients.indexOf(client);
    clients.remove(toRemove);
    nicknames.remove(toRemove);
    nickArrayChanged();
}

void Servak::incomingConnection(qintptr handle)
{
    QTcpSocket *client = new QTcpSocket();
    client->setSocketDescriptor(handle);
    clients.append(client);

    qDebug() << "New connection from: " << client->peerAddress().toString();

    connect (client, &QTcpSocket::readyRead, this, &Servak::readyRead);
    connect (client, &QTcpSocket::disconnected, this, &Servak::disconnected);
}

void Servak::nickArrayChanged()
{
    QString nicknamesData = "//NICKS={";
    for (QString nick : nicknames) {
        nicknamesData += nick + ",";
    }
    nicknamesData += "}";
//    qDebug() << nicknamesData;
    for (QTcpSocket *buffer : clients) {
        buffer->write(nicknamesData.toUtf8());
    }
}
