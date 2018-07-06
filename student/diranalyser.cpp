/********************************************************************************
 * calculate the size of one specified directory
 * input: the string representing the directory
 ********************************************************************************/
#include "diranalyser.h"
DirAnalyser::DirAnalyser()
{

}

double DirAnalyser::Analys(QDir &dir)const{

    QDir andir(dir);
    double size=0;
    QStringList filters;
    QFileInfoList filelist=andir.entryInfoList(filters,QDir::Files,QDir::Name);

    for(QFileInfoList::Iterator fi=filelist.begin();fi!=filelist.end();fi++){

        QString tempstring=fi->absoluteFilePath();
        const wchar_t * wc= reinterpret_cast<const wchar_t *>(tempstring.utf16());

        HANDLE h=CreateFile(wc,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
        LARGE_INTEGER LI;
        PLARGE_INTEGER Pi=&LI;
        GetFileSizeEx(h,Pi);
        size+=Pi->QuadPart;
    }

    filelist=andir.entryInfoList(filters,QDir::Dirs,QDir::Name);
    for(QFileInfoList::Iterator fi=filelist.begin();fi!=filelist.end();fi++){
        QFileInfo tempfi=*fi;
        if((tempfi.fileName()!=".")&& (tempfi.fileName()!="..")){
            QString temp=tempfi.absoluteFilePath();
            QDir tempdir(temp);
            size+=Analys(tempdir);
        }
    }
    return size;
}
double DirAnalyser::Analys()const{return 0;}
