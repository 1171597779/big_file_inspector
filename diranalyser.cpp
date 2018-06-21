#include "diranalyser.h"

DirAnalyser::DirAnalyser()
{
    QString str="D:\\";
    QDir *dir=new QDir(str);
    qDebug()<<Analys(*dir);
}

double DirAnalyser::Analys(QDir &dir){

    double size=0;
    QStringList filters;
    QFileInfoList filelist=dir.entryInfoList(filters,QDir::Files,QDir::Name);

    for(QFileInfoList::Iterator fi=filelist.begin();fi!=filelist.end();fi++){
       // qDebug()<<"File:  "<<fi->absoluteFilePath()<<endl<<fi->size();
      //  size+=fi->size();
        QString tempstring=fi->absoluteFilePath();
        const wchar_t * wc= reinterpret_cast<const wchar_t *>(tempstring.utf16());

        HANDLE h=CreateFile(wc,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
        LARGE_INTEGER LI;
        PLARGE_INTEGER Pi=&LI;
        GetFileSizeEx(h,Pi);
        size+=Pi->QuadPart;
       // qDebug()<<"Filesize from win API"<<LI<<endl;
    }

    filelist=dir.entryInfoList(filters,QDir::Dirs,QDir::Name);

    for(QFileInfoList::Iterator fi=filelist.begin();fi!=filelist.end();fi++){
        QFileInfo tempfi=*fi;
        //qDebug()<<"Dir: "<<fi->absoluteFilePath()<<fi->size()<<tempfi.fileName()<<endl;
        if((tempfi.fileName()!=".")&& (tempfi.fileName()!="..")){
            QString temp=tempfi.absoluteFilePath();
            QDir tempdir(temp);
            size+=Analys(tempdir);
        }
    }

    return size;
}
