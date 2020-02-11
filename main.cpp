#include "sig_slots_layout.h"
#include <QApplication>
#include <QTranslator>
#include <QString>
#include <QIcon>
#include <QLibraryInfo>
#include <windows.h>
#include <signal.h>

void handler_sigsegv(int signum)    //Отлавливаю ошибку SIGSEGV Error
{
    MessageBoxA(NULL,"SIGSEGV Error!","POSIX Signal",MB_ICONSTOP);
    // открепить обработчик и явно завершить приложение
    signal(signum, SIG_DFL);
    exit(3);
}

int main(int argc, char *argv[])
{
    signal(SIGSEGV, handler_sigsegv);   //Отлавливаю ошибку SIGSEGV Error

    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("sig_slots_layout_ru.qm", ".");
    a.installTranslator(&translator);

    QTranslator translator2;
    QString filespec2 = QString("qt_")+QLocale::system().name();
    QString directory = QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    translator2.load(filespec2, directory);
    QApplication ::installTranslator(&translator2);

    sig_slots_layout w;
    //w.setFixedSize(650, 500);

//    QString title = QObject::tr("Do you like your salary?");
//    w.setWindowTitle(title);

    QIcon icon("icon.ico");
    w.setWindowIcon(icon);
    w.spinBox->setValue(25);
    w.show();

    return a.exec();
}
