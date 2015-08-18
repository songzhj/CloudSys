#ifndef TCP_H
#define TCP_H

#include <QObject>
#include <QTcpSocket>

class TCP : public QObject
{
    Q_OBJECT
public:
    bool send(QString msg); //向服务端发送消息
    QString receive(); //从服务端取回数据
    explicit TCP(QString address, qint16 port);


private:
    explicit TCP(QObject *parent = 0){}
    QTcpSocket *tcp;
    TCP* instance;
    bool readed;
    QString reMsg;

signals:

public slots:
    void readMsg();
};
#endif // TCP_H
