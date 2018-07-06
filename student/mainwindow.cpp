#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //create a connection for Mysql database
    //QSqlDatabase qsql=QSqlDatabase::addDatabase("QMYSQL");

    //model to display directory
    QString rp("D:\\");
    files.setRootPath(rp);
    files.setFilter(QDir::AllEntries|QDir::NoDotAndDotDot);
    //qDebug()<<"root path:"<<files.rootPath()<<".size:"<<a;
    //qDebug()<<filesystem->rootDirectory().currentPath();
    ui->treeView->setModel(&files);
    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeView_customContextMenuRequested(const QPoint &pos)
{
    QModelIndex qmi= ui->treeView->currentIndex();
    QString qs=files.filePath(qmi);
    qDebug()<<qs;
    QDir dir(qs);
    qDebug()<<"the official result is"<<files.size(qmi);
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    qDebug()<<"clicked!";
}


