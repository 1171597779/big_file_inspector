#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qsqldatabase.h>
#include <diranalyser.h>
#include "myqfilesystemmodel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    MyQFileSystemModel files;
    ~MainWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_treeView_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
