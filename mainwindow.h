#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "windows.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    LPVOID pMap;
    LPVOID pMap_wf;
    HANDLE hfile;
    HANDLE hfile_wf;
    HANDLE hfilemap;
    HANDLE hfilemap_wf;
    int sizeFMapping = 512;

protected:
    virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;

signals:
    void CopyData(const QString & data);

private slots:
    void on_pushButton_create_file_mapping_clicked();
    void on_pushButton_read_file_mapping_clicked();
    void on_pushButton_close_file_mapping_clicked();
    void on_pushButton_create_file_mapping_wf_clicked();
    void on_pushButton_write_file_mapping_wf_clicked();
    void on_pushButton_read_file_mapping_wf_clicked();
    void on_pushButton_close_file_mapping_wf_clicked();
    void on_lineEdit_file_mapping_wf_textChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
