#-------------------------------------------------
#
# Project created by QtCreator 2018-06-09T02:28:42
#
#-------------------------------------------------

QT       += core gui sql

#对于Qt来说，模块的加载是通过这条命令来实现的。在Qt安装目录下，有mingw53_32和Src这两个
#目录，进入mingw53_32下面，bin、include和lib这三个目录是最重要的。如果使用了Qt+=sql，
#意味着使用了QtSql模块，也就是在include下面的QtSql这个文件夹下的头文件可以起作用了。
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = student
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS+= -"LC:\Program Files (x86)\Microsoft SDKs\Windows\v5.0\Include" -lkernel32

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    diranalyser.cpp

HEADERS += \
        mainwindow.h \
    diranalyser.h

FORMS += \
        mainwindow.ui
