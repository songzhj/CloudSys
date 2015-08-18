#ifndef ICONDISPLAYERWIDGET_H
#define ICONDISPLAYERWIDGET_H

#include <QMainWindow>
#include <QListWidget>
#include <QIcon>
#include "fileinforesolver.h"
namespace Ui {
class IconDisplayerWidget;
}

class IconDisplayerWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit IconDisplayerWidget(QWidget *parent = 0);
    ~IconDisplayerWidget();
    /**
     * 添加图标和图标对应的文件名
     * @param icon 文件图标
     * @param desc 图标对应的文件名
     * @return
    */
    void addIcon(QIcon icon, QString desc);
    /**
     * 获得ui中的ListWidget
     * @param
     * @return
    */
    QListWidget * getListWidget ();
    /**
     * 重载show方法,在show的同时通过socket通信将图标信息获取到,然后通过fileResolver进行解析
     * @param
     * @return
    */
    void show();
private slots:

    void on_uploadButton_clicked();

    void on_searchButton_clicked();

    void on_backButton_clicked();

    void on_downLoadButton_clicked();

private:
    Ui::IconDisplayerWidget *ui;
    FileInfoResolver * fileInfoResolver;
};

#endif // ICONDISPLAYERWIDGET_H
