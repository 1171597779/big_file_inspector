#ifndef MYQFILESYSTEMMODEL_H
#define MYQFILESYSTEMMODEL_H

#include <QFileSystemModel>  //class QFileSystemModel-> class QFileSystemModelPrivate-> method
    //inline qint64 size() const { if (info && !info->isDir()) return info->size(); return 0; }

#include <QString>
#include <QFileSystemModel>
#include <diranalyser.h>
class MyQFileSystemModel : public QFileSystemModel
{
public:
    MyQFileSystemModel();
    DirAnalyser da;
    qint64 size(const QModelIndex &index)const;
};

#endif // MYQFILESYSTEMMODEL_H
