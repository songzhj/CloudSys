#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setPlaceholderText();
    ~MainWindow();

private slots:
    void on_register_2_clicked();
    void readMes();

private:
    Ui::MainWindow *ui;
    QTcpSocket* tcpSocket; //tcp对象
    bool newConnect(); //新建TPC连接
    bool isEmpty(); //判断注册信息是否存在未填写
    bool submit(); //向服务端提交数据

};

#endif // MAINWINDOW_H
