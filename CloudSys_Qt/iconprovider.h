#ifndef ICONPROVIDER_H
#define ICONPROVIDER_H
#include <QIcon>


class IconProvider
{
public:
    IconProvider();
    /**
     * 通过扩展名extension(.***)构造临时文件QTemporaryFile然后通过QFileProvider获取对应的图标,类型
     * @param extension 后缀名
     * @return QIcon 图标类型
    */
    QIcon fileExtensionIcon(const QString & extension) const;
    /**
     * 获取类型
     * @param extension 文件后缀
     * @return QString 文件类型
    */
    QString fileExtensionType(const QString & extension) const;
};

#endif // ICONPROVIDER_H

