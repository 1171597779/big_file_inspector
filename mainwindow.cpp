#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //create a connection for Mysql database
    QSqlDatabase qsql=QSqlDatabase::addDatabase("QMYSQL");
    DirAnalyser *da=new DirAnalyser();
}

MainWindow::~MainWindow()
{
    delete ui;
}
