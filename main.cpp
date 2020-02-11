#include "rects.h"
#include <QApplication>
#include <QIcon>
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

    QString filespec = QString("rects_");
    filespec += QLocale::system().name();  //rects_ru_RU
    translator.load(filespec,".");

    a.installTranslator(&translator);

    //переводчик2
    QTranslator translator2;
    QString filespec2 = QString("qt_")+QLocale::system().name();
    QString directory = QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    translator2.load(filespec2, directory);
    QApplication ::installTranslator(&translator2);


    rects w;

    w.showNormal();

    //заголовок окна
    QString title = QObject::tr("rects");
    w.setWindowTitle(title);

    //иконка
    QIcon icon("icon.ico");
    w.setWindowIcon(icon);

    w.show();

    return a.exec();
}
