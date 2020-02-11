#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stat_lib.h"
#include "din_lib_vc.h"
#include <QLibrary>
#include "windows.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum operations { plus, minus, mult, div };
    int lib_type = 0;
    //QLibrary dll("din_lib_vc_export.dll");
    HMODULE dll2;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public Q_SLOTS:
    void clickButtonPlus();
    void clickButtonMinus();
    void clickButtonMult();
    void clickButtonDiv();

private slots:
    void on_radioButton_static_clicked();

    void on_radioButton_dll_task_3_clicked();

    void on_radioButton_dll_task__clicked();

    void on_radioButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    void libOperations(operations);
};

#endif // MAINWINDOW_H
