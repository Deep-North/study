#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    //translator.load("designer_ru.qm", ".");
    //translator.load(QLocale::system(), "designer_ru.qm", "_");
    QString filespec = QString("designer_");
    filespec += QLocale::system().name();
    translator.load(filespec,".");

    a.installTranslator(&translator);

    QTranslator translator2;
    QString filespec2 = QString("qt_")+QLocale::system().name();
    QString directory = QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    translator2.load(filespec2, directory);
    QApplication ::installTranslator(&translator2);

    MainWindow w;
    w.show();

    return a.exec();
}
