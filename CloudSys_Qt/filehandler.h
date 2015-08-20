#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QString>
#include <qwidget.h>


/**
 * 该类主要实现文件读,写,删除的操作
*/
class FileHandler:public QWidget
{
public:
    FileHandler();
    /**
     * 读文件到指定路径
     * @param filePath,读文件的文件路径
     * @return 1成功执行,-1执行失败文件打开失败
    */
    QByteArray readFile(QString filePath);
    /**
     * 写文件到指定路径
     * @param filePath,写文件的文件路径
     * @return 1成功执行,-1执行失败文件打开失败
    */
    int writeFile(QString filePath, QString content);
    /**
     * 进行删除文件操作
     * @param filePath,删除文件的文件的文件路径
     * @return 1操作正确
    */
    int deleteFile(QString filePath);
    /**
     * 通过文件路径获得文件名
     * @param
     * @return
    */
    QString getFileNameByFilePath(QString filePath);
};


#endif // FILEHANDLER_H
