#include "login.h"
#include "mainwindow.h"
#include "ui_login.h"
#include <QKeyEvent>
#include <QLineEdit>
#include <qmessagebox.h>
#include "global.h"

QString KEY;
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    //禁用鼠标右键
    ui->pwd->setContextMenuPolicy(Qt::NoContextMenu);
    ui->key->setContextMenuPolicy(Qt::NoContextMenu);
    ui->confirmKey->setContextMenuPolicy(Qt::NoContextMenu);

    //文字提示
    ui->user->setPlaceholderText(QString("用户名"));
    ui->pwd->setPlaceholderText(QString("密码"));
    ui->key->setPlaceholderText(QString("文件加密口令"));
    ui->confirmKey->setPlaceholderText(QString("确认文件加密口令"));
}

Login::~Login()
{
    delete ui;
}

void Login::on_okButton_clicked()
{
    QString user;
    QString pwd;
    QString key;
    QString confirmKey;

    user = ui->user->text();
    pwd = ui->pwd->text();
    key = ui->key->text();
    confirmKey = ui->confirmKey->text();

    if(key.isEmpty()){
        QMessageBox::information(this, "Information", "口令不能为空！");
        return;
    }
    if(key != confirmKey) {
        QMessageBox::information(this, "Information", "口令不一致！");
        return;
    }

    if(login(user, pwd)) {
        this->close();
        Global::KEY = key;
        MainWindow* mainWindow = new MainWindow();
        mainWindow->show();
        QMessageBox::information(this, "信息", "登录成功！");
    } else {
        QMessageBox::information(this, "信息", "用户名或密码错误");
    }
}

bool Login::login(QString user, QString pwd)
{
    if(user == "sss" && pwd == "123"){
        return true;
    } else {
        return false;
    }

    /*
     * TODO: user and pwd 应该传值到服务器.
     *
     */
}
