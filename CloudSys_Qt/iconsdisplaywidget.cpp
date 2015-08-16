#include "iconsdisplaywidget.h"
#include "iconprovider.h"
#include <qfileiconprovider.h>
#include <QHBoxLayout>
#include <QIcon>

IconsDisplayWidget::IconsDisplayWidget()
{
    list = new QListWidget;
    IconProvider iconProvider;
    list->addItem(new QListWidgetItem(iconProvider.fileExtensionIcon(".txt"), iconProvider.fileExtensionType(".txt")));
    list->addItem(new QListWidgetItem(iconProvider.fileExtensionIcon(".bmp"), iconProvider.fileExtensionType(".bmp")));
    list->addItem(new QListWidgetItem(iconProvider.fileExtensionIcon(".avi"), iconProvider.fileExtensionType(".avi")));
    list->addItem(new QListWidgetItem(iconProvider.fileExtensionIcon(".7z"),  iconProvider.fileExtensionType(".7z")));
    list->addItem(new QListWidgetItem(iconProvider.fileExtensionIcon(".jjj"), iconProvider.fileExtensionType(".txt")));
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(list);
    list->setViewMode(QListWidget::IconMode);
    list->setMovement(QListView::Static);
    setLayout(layout);
}

IconsDisplayWidget::IconsDisplayWidget(QListWidget *iconInfos)
{
    this->list = iconInfos;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(list);
   // list->setViewMode(QListWidget::IconMode);
    list->setMovement(QListView::Static);
    setLayout(layout);
}

