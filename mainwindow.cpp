#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"

#include <QMessageBox>
#include <iostream>
#include <QDebug>


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

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    static DWORD msg1 = RegisterWindowMessage(L"Test msg");
    MSG* msg = static_cast<MSG*>(message);
    //MSG* mes = static_cast<MSG*>(message);
    WPARAM wp = msg->wParam;
    LPARAM lp = msg->lParam;
    qDebug() << wp;
    qDebug() << lp;
    if(msg1 == msg->message)
    {
        QMessageBox::warning(this, QString("Got"), QString("User message recivied."), MB_OK, MB_OK);
        *result = 0;
        return true;
    }
    else if( msg -> message == WM_COPYDATA )
    {

            COPYDATASTRUCT* data = (COPYDATASTRUCT*)msg->lParam;
            QString msgText((char*)data->lpData);

            ui->label->setText(msgText);
            emit CopyData(msgText);

            *result = 0;
            return true;
        }
        else{
            //qDebug() << "Another message" << ++anotherMsgCounter;
            return false;
        }
}


void MainWindow::on_pushButton_create_file_mapping_clicked()
{
    hfilemap = CreateFileMappingA(
                INVALID_HANDLE_VALUE,       // hFile
                0,                          // lpFileMappingAttributes
                PAGE_READWRITE,             // flProtect
                0,                          // dwMaximumSizeHigh
                sizeFMapping,               // dwMaximumSizeLow
                "MyFileMapping"             // lpName
                );
    if (hfilemap == 0){
        QMessageBox::critical(0, "Fail", "Cannot create filemapping!");
        return;
    }

    LPVOID  pMap = MapViewOfFile(
                   hfilemap,        // hFileMappingObject
                   FILE_MAP_WRITE,  // dwDesiredAccess
                   0,               // dwFileOffsetHigh
                   0,               // dwFileOffserLow
                   0                // dwNumberOfBytesToMap
                   );
    if(pMap == NULL){
        DWORD err = GetLastError();
        QMessageBox::critical(0,"Fail", "Cannot create MapViewOfFile, error: " + QString::number((int)err));
        CloseHandle(hfilemap);
        return;
    }

    ui->label_file_mapping->setText("INFO: File mapping created");
}

void MainWindow::on_pushButton_read_file_mapping_clicked()
{
    hfilemap=OpenFileMapping(FILE_MAP_READ,0,L"MyFileMapping");
    char* p = static_cast<char*>(MapViewOfFile(hfilemap,FILE_MAP_READ,0,0,0));
    ui->lineEdit_file_mapping->setText(p);
    ui->label_file_mapping->setText("INFO: File mapping loaded");

}

void MainWindow::on_pushButton_close_file_mapping_clicked()
{
    UnmapViewOfFile(pMap);
    CloseHandle(hfilemap);
    ui->label_file_mapping->setText("INFO: File mapping closed");
}








void MainWindow::on_pushButton_create_file_mapping_wf_clicked()
{
    hfilemap_wf = CreateFileMappingA(
                INVALID_HANDLE_VALUE,       // hFile
                0,                          // lpFileMappingAttributes
                PAGE_READWRITE,             // flProtect
                0,                          // dwMaximumSizeHigh
                sizeFMapping,               // dwMaximumSizeLow
                "MyFileMapping_wf"          // lpName
                );
    if (hfilemap_wf == 0){
        QMessageBox::critical(0, "Fail", "Cannot create filemapping!");
        return;
    }

    pMap_wf = MapViewOfFile(
                   hfilemap_wf,     // hFileMappingObject
                   FILE_MAP_WRITE,  // dwDesiredAccess
                   0,               // dwFileOffsetHigh
                   0,               // dwFileOffserLow
                   0                // dwNumberOfBytesToMap
                   );
    if(pMap_wf == NULL){
        DWORD err = GetLastError();
        QMessageBox::critical(0,"Fail", "Cannot create MapViewOfFile, error: " + QString::number((int)err));
        CloseHandle(hfilemap_wf);
        return;
    }

    ui->label_file_mapping_wf->setText("INFO: File mapping created");
}

void MainWindow::on_pushButton_write_file_mapping_wf_clicked()
{
    QString file_mapping_text_wf = ui->lineEdit_file_mapping_wf->text();
    qDebug() << "fm_wf_Text:" << file_mapping_text_wf;

    QByteArray bytes_file_mapping_text_wf = file_mapping_text_wf.toUtf8();
    char* p = bytes_file_mapping_text_wf.data();
    strcpy(static_cast<char*>(pMap_wf), p);
    qDebug() << "p:" << p;

    ui->label_file_mapping_wf->setText("INFO: File mapping saved");
    qDebug() << "File mapping saved";
}

void MainWindow::on_pushButton_read_file_mapping_wf_clicked()
{
    hfilemap_wf = OpenFileMapping(FILE_MAP_READ, 0, L"MyFileMapping_wf");
    char* p = static_cast<char*>(MapViewOfFile(hfilemap_wf, FILE_MAP_READ, 0, 0, 0));
    ui->lineEdit_file_mapping_wf->setText(p);
    ui->label_file_mapping_wf->setText("INFO: File mapping loaded");
}

void MainWindow::on_pushButton_close_file_mapping_wf_clicked()
{
    UnmapViewOfFile(pMap_wf);
    CloseHandle(hfilemap_wf);
    ui->label_file_mapping_wf->setText("INFO: File mapping closed");
}

void MainWindow::on_lineEdit_file_mapping_wf_textChanged(const QString &arg1)
{
    UINT MyFileMappingMsg_wf = RegisterWindowMessageA("FileMappingChangedParent_wf");
    WPARAM wParam = 0;
    LPARAM lParam = 0;
    PostMessageA(HWND_BROADCAST, MyFileMappingMsg_wf, wParam, lParam);
}
