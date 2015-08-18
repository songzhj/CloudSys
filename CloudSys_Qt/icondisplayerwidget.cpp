#include "filehandler.h"
#include "icondisplayerwidget.h"
#include "ui_icondisplayerwidget.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

IconDisplayerWidget::IconDisplayerWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IconDisplayerWidget)
{
    ui->setupUi(this);
    //文字提示
    ui->searchLineEdit->setContextMenuPolicy(Qt::NoContextMenu);
    ui->searchLineEdit->setPlaceholderText(QString("请输入搜索内容"));
    connect(ui->searchLineEdit, &QLineEdit::textEdited, this, &IconDisplayerWidget::searchListByName);
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


void IconDisplayerWidget::searchListByName()
{
    QString searchContent = ui->searchLineEdit->text();
    QList<QString> * list = fileInfoResolver->getFileInfosContains(searchContent);
//    for (QList<QString>::iterator ite = list->begin(); ite != list->end(); ++ite) {
//        qDebug() << (*ite);
//    }
    ui->iconPlayerWidget->clear();
    FileInfoResolver * resolver = new FileInfoResolver(*list);
    resolver->addIconToQListWidget(this->getListWidget());
    delete(resolver);
}

void IconDisplayerWidget::show()
{
    /*
     * 获得通过服务器传过来的图标信息,并在ListWidget进行添加图标信息
     */
    // 测试--------------------------
    QList<QString> fileInfoList;
    fileInfoList.push_back("2.txt");
    fileInfoList.push_back("2.doc");
    fileInfoList.push_back("2.jpg");
    fileInfoList.push_back("2.zip");
    fileInfoList.push_back("2.ppt");
    //==================================
    fileInfoResolver = new FileInfoResolver(fileInfoList);
    fileInfoResolver->addIconToQListWidget(this->getListWidget());
    QMainWindow::show();
}

void IconDisplayerWidget::on_backButton_clicked()
{
    ui->iconPlayerWidget->clear();
    fileInfoResolver->addIconToQListWidget(this->getListWidget());
}

void IconDisplayerWidget::on_uploadButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(0, tr("选择上传文件"), ".", tr("所有文件(*)"));
    if(path.length() == 0) {
        QMessageBox::information(NULL, tr("提示"), tr("你没有选择任何文件!"));
    } else {
        qDebug() << path;
        //将文件通过socket传至服务器端然后刷新QListWidget



    }
}

void IconDisplayerWidget::on_downLoadButton_clicked()
{
    QList<QListWidgetItem*> list = ui->iconPlayerWidget->selectedItems();
    if (list.isEmpty()){
        QMessageBox::warning(this, "警告", "你没有选中任何文件");
        return;
    }
    QString selectedFileName = list.front()->text();
    qDebug() << selectedFileName;
    QString path = QFileDialog::getExistingDirectory(NULL, tr("选择下载路径"),"D:\\",QFileDialog::ShowDirsOnly);
    //TODO 将选中的文件通过socket存储到通过文件选择器获得的文件夹目录下


}

void IconDisplayerWidget::on_searchLineEdit_returnPressed()
{

}
