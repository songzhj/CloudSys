#ifndef ICONDISPLAYERWIDGET_H
#define ICONDISPLAYERWIDGET_H

#include <QMainWindow>

namespace Ui {
class IconDisplayerWidget;
}

class IconDisplayerWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit IconDisplayerWidget(QWidget *parent = 0);
    ~IconDisplayerWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::IconDisplayerWidget *ui;
};

#endif // ICONDISPLAYERWIDGET_H
