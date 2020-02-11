#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Windows.h>
#include "mydata.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static DWORD WINAPI ThreadFunc( LPVOID lpParam );
    static DWORD WINAPI ThreadCs( LPVOID lpParam );
    static DWORD WINAPI MutexFunc( LPVOID lpParam );
    static DWORD WINAPI SemaFunc( LPVOID lpParam );
    static DWORD WINAPI ManualEventFunc( LPVOID lpParam );
    static DWORD WINAPI AutoEventFunc( LPVOID lpParam );

    void prepareThreads( LPTHREAD_START_ROUTINE lpStartAddr, HANDLE hObject=NULL);

private:
    static volatile int m_X;
    static CRITICAL_SECTION cs;
    QVector<MyData*> ar;

    Ui::MainWindow *ui;

    HANDLE hMutex;
    HANDLE hSema;
    HANDLE hNamedMutex;
    HANDLE hNamedSema;
    HANDLE hManualEvent;
    HANDLE hAutoEvent;
    HANDLE hNamedManualEvent;

public slots:
    void ThreadsGo();
    void CriticalSection();
    void Mutex();
    void Semaphore();
    void SystemMutex();
    void SystemSemaphore();
    void ManualEvent();
    void ManualStop();
    void ManualContinue();
    void AutoEvent();
    void NamedManualEvent();
    void NamedManualStop();
    void NamedManualContinue();
};

#endif // MAINWINDOW_H
