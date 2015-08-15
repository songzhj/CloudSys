/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label_3;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *user;
    QLabel *label_2;
    QLineEdit *pwd;
    QLabel *label_4;
    QLineEdit *key;
    QLabel *label_5;
    QLineEdit *confirmKey;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 244);
        Login->setContextMenuPolicy(Qt::DefaultContextMenu);
        Login->setAcceptDrops(false);
        Login->setModal(false);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 20, 121, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        formLayoutWidget = new QWidget(Login);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(60, 70, 291, 131));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        user = new QLineEdit(formLayoutWidget);
        user->setObjectName(QStringLiteral("user"));
        user->setMaxLength(20);

        formLayout->setWidget(0, QFormLayout::FieldRole, user);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        pwd = new QLineEdit(formLayoutWidget);
        pwd->setObjectName(QStringLiteral("pwd"));
        pwd->setEnabled(true);
        pwd->setAutoFillBackground(false);
        pwd->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        pwd->setMaxLength(20);
        pwd->setEchoMode(QLineEdit::Password);
        pwd->setClearButtonEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, pwd);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        key = new QLineEdit(formLayoutWidget);
        key->setObjectName(QStringLiteral("key"));
        key->setMaxLength(20);
        key->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, key);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        confirmKey = new QLineEdit(formLayoutWidget);
        confirmKey->setObjectName(QStringLiteral("confirmKey"));
        confirmKey->setMaxLength(20);
        confirmKey->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, confirmKey);

        cancelButton = new QPushButton(Login);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(200, 210, 75, 23));
        okButton = new QPushButton(Login);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(110, 210, 75, 23));

        retranslateUi(Login);
        QObject::connect(cancelButton, SIGNAL(clicked()), Login, SLOT(close()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225\347\225\214\351\235\242", 0));
        Login->setWindowFilePath(QString());
        label_3->setText(QApplication::translate("Login", "\345\212\240\345\257\206\344\272\221\345\255\230\345\202\250\347\263\273\347\273\237", 0));
        label->setText(QApplication::translate("Login", "\347\224\250\346\210\267\357\274\232", 0));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", 0));
        label_4->setText(QApplication::translate("Login", "\345\217\243\344\273\244\357\274\232", 0));
        label_5->setText(QApplication::translate("Login", "\347\241\256\350\256\244\345\217\243\344\273\244\357\274\232", 0));
        cancelButton->setText(QApplication::translate("Login", "Cancel", 0));
        okButton->setText(QApplication::translate("Login", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
