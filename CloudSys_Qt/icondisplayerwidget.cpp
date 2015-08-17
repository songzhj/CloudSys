#include "icondisplayerwidget.h"
#include "ui_icondisplayerwidget.h"


IconDisplayerWidget::IconDisplayerWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IconDisplayerWidget)
{
    ui->setupUi(this);

}

IconDisplayerWidget::~IconDisplayerWidget()
{
    delete ui;
}

void IconDisplayerWidget::addIcon(QIcon icon, QString desc)
{
    ui->iconPlayerWidget->addItem(new QListWidgetItem(icon, desc));
}

QListWidget * IconDisplayerWidget::getListWidget()
{
    return ui->iconPlayerWidget;
}

void IconDisplayerWidget::on_uploadButton_clicked()
{

}
