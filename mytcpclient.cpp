#include "mytcpclient.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpClient::MyTcpClient(int argc, char* argv[], QObject *parent) : QObject(parent)
{
    m_hostname = argv[1];
    unsigned short port = 80;
    m_socket = new QTcpSocket(this);

    // Signal ->  Slot-Verbindung
    connect(m_socket, &QTcpSocket::connected, this, &MyTcpClient::connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &MyTcpClient::readyRead);

    m_socket->connectToHost(m_hostname, port); // TCP Connect
    if (!m_socket->waitForConnected(5000)) {
        qDebug() << "Connect failed!";
        exit(1);
    }
}

void MyTcpClient::connected()
{
    // normgerechter HTTP Request zum Server
    m_socket->write("GET / HTTP/1.1\r\nHost:" + m_hostname + "\r\n\r\n");
}

void MyTcpClient::readyRead()
{
    // HTTP-Antwort vom Server
    qDebug() << m_socket->readAll();
    m_socket->disconnectFromHost();
    QCoreApplication::quit();
}
