#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public Q_SLOTS:
    void lineEdit_valueChanged(const QString &);

Q_SIGNALS:
    void mySignal( int );

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
