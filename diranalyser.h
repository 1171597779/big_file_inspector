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
    DirAnalyser();
    double Analys(QDir & dir);
};

#endif // DIRANALYSER_H
