#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonNotepad_clicked();

    void on_pushButtonnotepadsuspended_clicked();

    void on_pushButton3processes_clicked();

    void on_pushButtonMinimized_clicked();

    void on_pushButton_Maximized_clicked();

    void on_pushButton_poz_size_clicked();

    void on_pushButton_chiProFromFoldr_clicked();

    void on_pushButton_task_1_5_clicked();

    void on_pushButton_task_2_clicked();

    void on_pushButton_call_a_child_clicked();

    void on_lineEdit__WM_COPYDATA_textChanged(const QString &arg1);

    void on_pushButton_create_file_mapping_clicked();

    void on_pushButton_write_file_mapping_clicked();

    void on_pushButton_close_file_mapping_clicked();

    void on_lineEdit_file_mapping_textChanged(const QString &arg1);

    void on_pushButton_create_file_mapping_with_file_clicked();

    void on_pushButton_write__file_mapping_with_file_clicked();

    void on_pushButton_read_file_mapping_with_file_clicked();

    void on_pushButton_close__file_mapping_with_file_clicked();

    void on_lineEdit_file_mapping_with_file_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    LPVOID pMap;
    LPVOID pMap_wf;
    LPVOID lpBuffer;

    DWORD nNumberOfBytesToRead = 100;

    HANDLE hfile;
    HANDLE hfile_wf;
    HANDLE hfilemap;
    HANDLE hfilemap_wf;
    int sizeFMapping = 1024;

};

#endif // MAINWINDOW_H
