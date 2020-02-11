#include "salary.h"
#include <QApplication>
#include <QIcon>
#include <QString>
#include <QTranslator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("salary_ru.qm", ".");
    a.installTranslator(&translator);

    QTranslator translator2;
    QString filespec2 = QString("qt_")+QLocale::system().name();
    QString directory = QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    translator2.load(filespec2, directory);
    QApplication ::installTranslator(&translator2);

    salary w;
    w.setFixedSize(650, 500);

    QString title = QObject::tr("Do you like your salary?");
    w.setWindowTitle(title);

    QIcon icon("icon.ico");
    w.setWindowIcon(icon);

    w.show();

    return a.exec();
}
