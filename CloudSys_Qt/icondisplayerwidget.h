#ifndef ICONDISPLAYERWIDGET_H
#define ICONDISPLAYERWIDGET_H

#include <QMainWindow>
#include <QListWidget>
#include <QIcon>
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
private slots:

    void on_uploadButton_clicked();

private:
    Ui::IconDisplayerWidget *ui;
};

#endif // ICONDISPLAYERWIDGET_H
