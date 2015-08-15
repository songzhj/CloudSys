#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
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
<<<<<<< HEAD
    void on_okButton_clicked();

=======

    void on_okButton_clicked();

    bool login(QString user, QString pwd);

>>>>>>> origin/master
private:
    Ui::Login *ui;
};



#endif // LOGIN_H
