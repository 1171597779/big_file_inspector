#ifndef DIRANALYSER_H
#define DIRANALYSER_H

#include "windows.h"
#include "winbase.h"
#include <QObject>
#include <qstring.h>
#include <iostream>
#include <QDebug>
#include <QDir>

class DirAnalyser
{
public:
    //QDir andir;
    DirAnalyser();
    double Analys(QDir & dir)const;
    double Analys()const;
};

#endif // DIRANALYSER_H
