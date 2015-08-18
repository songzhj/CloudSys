#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QTcpSocket>
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_okButton_clicked();
    void readMsg(); //读取套接字中的信息, 信号readyRead()的槽

private:
    Ui::Login *ui;
    QTcpSocket *tcpSocket; //TCP服务

    void login(QString user, QString pwd); //向服务端发送信息验证用户身份
    void setEditLine(); //设置输入框属性(禁用鼠标右键, 输入提示)
    bool newConnect(); //新建TCP连接
};



#endif // LOGIN_H
