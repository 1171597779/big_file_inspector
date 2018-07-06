#include "myqfilesystemmodel.h"

MyQFileSystemModel::MyQFileSystemModel()
{
    DirAnalyser da();
}
qint64 MyQFileSystemModel::size(const QModelIndex &index)const{
    QModelIndex idex=index;
    QString qs=this->filePath(idex);
    QDir qd(qs);
    double ret=0;
    ret=this->da.Analys(qd);
    return (qint64)ret;
}
