#ifndef FILEINFORESOLVER_H
#define FILEINFORESOLVER_H
#include <QList>
#include <QListWidget>

class FileInfoResolver
{
public:
    /**
     * 通过QList的构造
     * @param fileInfos将所需转换的文件的信息一次性传到FileInfoResolver类中进行解析
     * @return none
    */
    FileInfoResolver(QList<QString> fileInfos);
    /**
     * 将转换后的文件图标直接放在listWidget上
     * @param
     * @return
    */
    void addIconToQListWidget(QListWidget * listWidget);
private:
    QList<QString> fileInfos; //文件信息链表
};

#endif // FILEINFORESOLVER_H
