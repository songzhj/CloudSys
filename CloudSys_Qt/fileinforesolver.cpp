#include "fileinforesolver.h"
#include "iconprovider.h"
#include <QDebug>

FileInfoResolver::FileInfoResolver(QList<QString> fileInfos)
{
    this->fileInfos = fileInfos;
}

void FileInfoResolver::addIconToQListWidget(QListWidget * listWidget)
{
    IconProvider provider;
    //遍历fileInfos
    for (QList<QString>::iterator ite = fileInfos.begin(); ite != fileInfos.end(); ++ite) {
        //将文件后缀通过文件名解析出来
       QString tempFileName = *ite;
       //将文件名通过IconProvider的对象转换成对应的图片文件
       listWidget->addItem(new QListWidgetItem(provider.fileExtensionIcon(tempFileName), tempFileName));
    }
}

