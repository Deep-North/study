#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "1";
    UINT nMsg =::RegisterWindowMessage(L"Test msg");
    qDebug() << nMsg;
    PostMessage(HWND_BROADCAST, nMsg, 1000, NULL);
    qDebug() << "3";
}
