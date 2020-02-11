#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0, 100));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lineEdit_valueChanged(const QString & val) {
    emit mySignal(val.toInt());
}
