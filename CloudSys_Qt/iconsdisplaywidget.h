#ifndef ICONSDISPLAYWIDGET_H
#define ICONSDISPLAYWIDGET_H

#include <QWidget>
#include <QListWidget>

class IconsDisplayWidget: public QWidget
{
public:
    IconsDisplayWidget();
    IconsDisplayWidget(QListWidget * iconInfos);
private:
    QListWidget * list;
};

#endif // ICONSDISPLAYWIDGET_H
