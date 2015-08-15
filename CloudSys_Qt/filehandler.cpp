#include "filehandler.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>

FileHandler::FileHandler()
{

}

int FileHandler::ReadFile(QString filePath)
{
    const int MAX = 100;
    QString str;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Warning", "文件打开错误");
        return -1;
    }
    QTextStream in(&file);
    str = in.readLine();
    QString str2[MAX];
    for (int i = 0; i < MAX; ++i)
    {
        str2[i] = in.readLine();
    }
    file.close();
    return 1;
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
    out << content << "\n";
    file.close();
    return 1;
}


int FileHandler::DeleteFile(QString filePath)
{
     QFile file;
     file.remove(filePath);
     return 1;
}

