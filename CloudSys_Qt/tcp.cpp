#include "tcp.h"
#include <QDebug>

/**
*Description: 向服务端发送消息
*
*@param: msg
*
*@return: bool
*/
bool TCP::send(QString msg)
{
    msg += "\r\n";
    tcp->write(msg.toLatin1());
    return true;
}

/**
*Description:从服务端取回数据
*
*@param: null
*
*@return:QString
*/
QString TCP::receive()
{
    while(!readed){qDebug() << "1";}
    readed = false;
    return reMsg;
}

/**
*Description: 服务端取回数据的槽函数
*
*@param: null
*
*@return: void
*/
void TCP::readMsg()
{
    QByteArray qba = tcp->readAll();
    reMsg = QString::fromStdString(qba.toStdString());
    readed = true;
}

TCP::TCP(QString address, qint16 port)
{
    tcp = new QTcpSocket();
    tcp->connectToHost(address, port);

    if(!tcp->waitForConnected(3 * 1000)) {
        qDebug() << "TCP初始化连接超时. TCP::TCP(QString, qint16)";
    }
    connect(tcp, SIGNAL(readyRead()), this, SLOT(readMsg()));
    readed = false;
}
