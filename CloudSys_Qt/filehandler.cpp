#include "filehandler.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>

FileHandler::FileHandler()
{

}

QString FileHandler::ReadFile(QString filePath)
{
    QString str;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Warning", "文件打开错误");
    }
    QTextStream in(&file);

    while(!in.atEnd())
    {
        str += in.readAll();
    }
    file.close();
    return str;
}

int FileHandler::WriteFile(QString filePath, QString content)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Warning", "文件打开错误");
        return -1;
    }
    QTextStream out(&file);
    out << content;
    file.close();
    return 1;
}


int FileHandler::DeleteFile(QString filePath)
{
     QFile file;
     file.remove(filePath);
     return 1;
}

