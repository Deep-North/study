#include "spider2.h"
#include <QApplication>
#include <QIcon>
#include <QPalette>
#include <QPixmap>
#include <QDesktopWidget>
#include <QBitmap>
#include <QColorDialog>
#include <QFileDialog>
#include <QString>
#include <QTranslator>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //перводчик
    QTranslator translator;
    //translator.load("spider_ru.qm", ".");
    //translator.load(QLocale::system(), "spider_ru.qm", "_");

    QString filespec = QString("spider_");
    filespec += QLocale::system().name();  //spider_ru_RU
    translator.load(filespec,".");

    a.installTranslator(&translator);

    //переводчик2
    QTranslator translator2;
    QString filespec2 = QString("qt_")+QLocale::system().name();
    QString directory = QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    translator2.load(filespec2, directory);
    QApplication ::installTranslator(&translator2);


    spider2 w;

    w.showNormal();

    //заголовок окна
    QString title = QObject::tr("spider");
    w.setWindowTitle(title);

    //иконка
    QIcon icon("icon2.ico");
    w.setWindowIcon(icon);

    w.show();

    return a.exec();
}
