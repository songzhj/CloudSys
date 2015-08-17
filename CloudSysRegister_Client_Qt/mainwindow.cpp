#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置文本框默认
    setPlaceholderText();
}


/**
*Description: 设置登录框中所有文本框默认值的方法
*
*@param: null
*
*@return: null
*/
void MainWindow::setPlaceholderText()
{
    ui->user->setPlaceholderText("用户名");
    ui->pwd->setPlaceholderText("密码");
    ui->IDCard->setPlaceholderText("身份证");
    ui->address->setPlaceholderText("住址");
    ui->phoneNumber->setPlaceholderText("手机号");
}//setPlaceholderText

MainWindow::~MainWindow()
{
    delete ui;
}

/**
*Description: 注册按钮的槽, 用于提交注册信息, 注册成功提示后关闭注册机, 失败提示后返回注册机并清空用户名
*
*@param: null
*
*@return: null
*/
void MainWindow::on_register_2_clicked()
{
    if(isEmpty()) {
        QMessageBox::information(this, "信息", "请填写完整信息！");
        return;
    }

    //新建TCP, 连接服务器
    if(!newConnect()) {
        QMessageBox::information(this, "信息", "与服务器连接超时！重试.");
        return;
    }

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMes()));
    //向服务器提交数据
    if(!submit()) {
        QMessageBox::information(this, "信息", "信息提交失败, 请重试！");
        return;
    }

    /*
     * 服务器传回数据, 会使信号量readyRead()触发槽readAll(),从而判断注册结果
     */

}//on_register_2_clicked

/**
*Description: 从套接字中读取服务端返回的信息, 判断注册结果
*
*@param: null
*
*@return: null
*/
void MainWindow::readMes()
{
    QByteArray qba = tcpSocket->readAll();
    QString s = QString::fromStdString(qba.toStdString());
    if("Y" == s) {
        QMessageBox::information(this, "信息", "注册成功！");
    } else {
        QMessageBox::information(this, "信息", "注册失败, 用户名已存在！");
    }
}//readMes



/**
*Description: 尝试与服务器新建TCP连接
*
*@param: null
*
*@return: bool
*/
bool MainWindow::newConnect()
{
    tcpSocket = new QTcpSocket;
    tcpSocket->abort(); //清除所有连接(之前连接成功但传输失败且未关闭的连接)
    tcpSocket->connectToHost("49.140.98.76", 23333); //建立连接
    const int timeout = 3 * 1000;
    if(!tcpSocket->waitForConnected(timeout)) {
        return false;
    }

    return true;
}//newConnect

/**
*Description: 判断注册信息是否存在未填写的项
*
*@param: null
*
*@return: bool
*/
bool MainWindow::isEmpty()
{
    if(ui->user->text().isEmpty() || ui->pwd->text().isEmpty() || !(ui->sex_male->isChecked() || ui->sex_female->isChecked()) || ui->address->text().isEmpty() || ui->phoneNumber->text().isEmpty() || ui->IDCard->text().isEmpty()){
        return true;
    } else {
        return false;
    }
}//isEmpty

/**
*Description: 向服务端提交数据
*
*@param: null
*
*@return: bool
*/
bool MainWindow::submit()
{
    QString postfix = "\r\n";
    QString end = "#END#\r\n";

    //user, pwd, IDCard, sex, address, phoneNumber
    QString user = ui->user->text() + postfix;
    QString pwd = ui->pwd->text() + postfix;
    QString IDCard = ui->IDCard->text() + postfix;
    QString sex;
    if(ui->sex_male->isChecked()) {
        sex = "male";
    } else {
        sex = "female";
    }
    sex += postfix;
    QString address = ui->address->text() + postfix;
    QString phoneNumber = ui->phoneNumber->text() + postfix;

    //合并成一条TCP msg
    QString msg = user + pwd + IDCard + sex + address + phoneNumber + end;
    tcpSocket->write(msg.toLatin1());
    //判断是否提交超时
    if(!tcpSocket->waitForBytesWritten(3 * 1000)) {
        return false;
    } else {
        return true;
    }
}
