#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>
#include <QDebug>
#include <QtWin>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_a->setValidator(new QDoubleValidator(this));
    ui->lineEdit_b->setValidator(new QDoubleValidator(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickButtonPlus() {
    //qDebug() << "clickButtonPlus()";
    libOperations(plus);
}

void MainWindow::clickButtonMinus() {
    //qDebug() << "clickButtonMinus()";
    libOperations(minus);
}

void MainWindow::clickButtonMult() {
    //qDebug() << "clickButtonMult()";
    libOperations(mult);
}

void MainWindow::clickButtonDiv() {
    //qDebug() << "clickButtonDiv()";
    libOperations(div);
}

void MainWindow::libOperations(operations o) {
    QString a = ui->lineEdit_a->text();
    QString b = ui->lineEdit_b->text();
    double res = 0;
    switch(o) {
    case plus:
        switch (lib_type) {
        case 0:
            res =  sl_fPlus(a.toDouble(), b.toDouble());
            qDebug() << "static_plus";
            break;
        case 1:
            res = dl_Plus(a.toDouble(), b.toDouble());
            qDebug() << "dll_3_plus";
            break;
        case 2:
        {
            QLibrary dll("din_lib_vc_export.dll");
            dll.load();
            if(dll.isLoaded()) {
                        double(*ph)(double,double) = (double(*)(double,double))dll.resolve("dle_Plus");
                        if(ph) {
                            res = ph(a.toDouble(), b.toDouble());
                        }
               }
            qDebug() << "dll_4_plus";
            break;
        }
        case 3:
        {
            HMODULE dll2 = LoadLibraryW(L"din_dll_def.dll");
            if (dll2) {
                double(*ph)(double,double) = (double(*)(double,double))::GetProcAddress(dll2, "def_Plus");
                res = ph(a.toDouble(), b.toDouble());
                FreeLibrary(dll2);
                qDebug() << "dll_def_plus";
            }
            else {
                qDebug() << "Error to load library";
                res = 0;
            }
            break;
        }
        }
        break;
    case minus:
        switch (lib_type) {
        case 0:
            res =  sl_fMinus(a.toDouble(), b.toDouble());
            qDebug() << "static_minus";
            break;
        case 1:
            res = dl_Minus(a.toDouble(), b.toDouble());
            qDebug() << "dll_3_minus";
            break;
        case 2:
        {
            QLibrary dll("din_lib_vc_export.dll");
            dll.load();
            if(dll.isLoaded()) {
                        double(*ph)(double,double) = (double(*)(double,double))dll.resolve("dle_Minus");
                        if(ph) {
                            res = ph(a.toDouble(), b.toDouble());
                        }
               }
            qDebug() << "dll_4_minus";
            break;
        }
        case 3:
        {
            HMODULE dll2 = LoadLibraryW(L"din_dll_def.dll");
            if (dll2) {
                double(*ph)(double,double) = (double(*)(double,double))::GetProcAddress(dll2, "def_Minus");
                res = ph(a.toDouble(), b.toDouble());
                FreeLibrary(dll2);
                qDebug() << "dll_def_minus";
            }
            else {
                qDebug() << "Error to load library";
                res = 0;
            }
            break;
        }
        }
        break;
    case mult:
        switch (lib_type) {
        case 0:
            res =  sl_fMult(a.toDouble(), b.toDouble());
            qDebug() << "static_mult";
            break;
        case 1:
            res = dl_Mult(a.toDouble(), b.toDouble());
            qDebug() << "dll_3_mult";
            break;
        case 2:
        {
            QLibrary dll("din_lib_vc_export.dll");
            dll.load();
            if(dll.isLoaded()) {
                        double(*ph)(double,double) = (double(*)(double,double))dll.resolve("dle_Mult");
                        if(ph) {
                            res = ph(a.toDouble(), b.toDouble());
                        }
               }
            qDebug() << "dll_4_mult";
            break;
        }
        case 3:
        {
            HMODULE dll2 = LoadLibraryW(L"din_dll_def.dll");
            if (dll2) {
                double(*ph)(double,double) = (double(*)(double,double))::GetProcAddress(dll2, "def_Mult");
                res = ph(a.toDouble(), b.toDouble());
                FreeLibrary(dll2);
                qDebug() << "dll_def_mult";
            }
            else {
                qDebug() << "Error to load library";
                res = 0;
            }
            break;
        }
        }
        break;
    case div:
        if (b.toDouble() == 0){
            res = 0;
            break;
        }
        switch (lib_type) {
        case 0:
            res =  sl_fDiv(a.toDouble(), b.toDouble());
            qDebug() << "static_div";
            break;
        case 1:
            res = dl_Div(a.toDouble(), b.toDouble());
            qDebug() << "dll_3_div";
            break;
        case 2:
        {
            QLibrary dll("din_lib_vc_export.dll");
            dll.load();
            if(dll.isLoaded()) {
                        double(*ph)(double,double) = (double(*)(double,double))dll.resolve("dle_Div");
                        if(ph) {
                            res = ph(a.toDouble(), b.toDouble());
                        }
               }
            qDebug() << "dll_4_div";
            break;
        }
        case 3:
        {
            HMODULE dll2 = LoadLibraryW(L"din_dll_def.dll");
            if (dll2) {
                double(*ph)(double,double) = (double(*)(double,double))::GetProcAddress(dll2, "def_Div");
                res = ph(a.toDouble(), b.toDouble());
                FreeLibrary(dll2);
                qDebug() << "dll_def_div";
            }
            else {
                qDebug() << "Error to load library";
                res = 0;
            }
            break;
        }
        }
        break;
    }
    qDebug() << a;
    qDebug() << b;
    qDebug() << res;
    ui->lineEdit_res->setText(QString::number(res));
}


void MainWindow::on_radioButton_static_clicked()
{
    lib_type = 0;
}

void MainWindow::on_radioButton_dll_task_3_clicked()
{
    lib_type = 1;
}

void MainWindow::on_radioButton_dll_task__clicked()
{
    lib_type = 2;
}

void MainWindow::on_radioButton_clicked()
{
    lib_type = 3;
}

void MainWindow::on_pushButton_clicked()
{
    HMODULE dll3 = LoadLibrary(L"din_dll_res.dll");
    if(dll3) {
        qDebug() << "librarary loaded";
        HICON hic = LoadIconA(dll3, (LPCSTR)MAKEINTRESOURCE(101));
        if(hic) {
            QPixmap qpm = QtWin::fromHICON(hic);
            QIcon icon = QIcon(qpm);
            setWindowIcon(icon);
        }
        else {
            qDebug() << "icon NOT found";
            return;
        }
        FreeLibrary(dll3);
    }
    else {
        qDebug() << "library NOT found";
        return;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    HMODULE dll4 = LoadLibrary(L"din_dll_vocabulary_eng.dll");
    HMODULE dll5 = LoadLibrary(L"din_dll_vocabulary_rus.dll");
    if(dll4) {
        qDebug() << "librarary eng loaded";
        TCHAR mStr[128];
        LoadString(dll4, 101, mStr, 128);
        QString str =  QString::fromWCharArray(mStr);
        ui->label_2->setText(str);
        FreeLibrary(dll4);
    }
    else {
        qDebug() << "library NOT found";
        return;
    }

    if(dll5) {
        qDebug() << "librarary rus loaded";
        TCHAR nStr[128];
        LoadString(dll5, 101, nStr, 128);
        QString str =  QString::fromWCharArray(nStr);
        ui->label_3->setText(str);
        FreeLibrary(dll5);
    }
    else {
        qDebug() << "library NOT found";
        return;
    }
}
