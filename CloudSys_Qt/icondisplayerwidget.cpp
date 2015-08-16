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

void IconDisplayerWidget::on_pushButton_clicked()
{

}
