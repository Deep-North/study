#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydata.h"
#include "mypoint.h"
#include <QColor>
#include <QPoint>
#include <qDebug>
#include <QMessageBox>

volatile int MainWindow::m_X=0;

CRITICAL_SECTION MainWindow::cs;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<QVector<int>>("QVector<DWORD>");
    hMutex=CreateMutex(0, FALSE, 0);
    hSema=CreateSemaphore(0, 2, 2,0);
    hManualEvent=CreateEvent(0, TRUE, TRUE, 0);
    hAutoEvent=CreateEvent(0, FALSE, TRUE, 0);
    hNamedMutex=CreateMutex(0, FALSE, L"myMutex");
    hNamedSema=CreateSemaphore(0, 2, 2, L"mySemaphore");
    hNamedManualEvent=CreateEvent(0, TRUE, TRUE, L"myManualEvent");
    InitializeCriticalSection(&cs);
}

MainWindow::~MainWindow()
{
    CloseHandle(hMutex);
    CloseHandle(hSema);
    CloseHandle(hManualEvent);
    CloseHandle(hAutoEvent);
    CloseHandle(hNamedMutex);
    CloseHandle(hNamedSema);
    CloseHandle(hNamedManualEvent);
    DeleteCriticalSection(&cs);
    for (int i = 0; i < ar.count(); ++i) {delete ar[i];}
    delete ui;
}


DWORD WINAPI MainWindow::ThreadFunc( LPVOID lpParam ){
    MyData* data = reinterpret_cast<MyData*>(lpParam);
    int y = data->getY();
    QColor col = data->getCol();
    int max = data->getMax();

    for(int i = 1; i < max/3; i++){
        MyPoint p = MyPoint(QPoint(m_X, y), col);
        emit data->signalAddPoint(p);
        m_X+=1;
        int c=0;
        for (int i=0; i<1000000; ++i) {c++;}
    }
    return 0;
}

void MainWindow::ThreadsGo(){
    m_X=0;
    prepareThreads(ThreadFunc);
}

void MainWindow::prepareThreads( LPTHREAD_START_ROUTINE lpStartAddr, HANDLE hObject){
    for (int i = 0; i < ar.count(); ++i) {delete ar[i];}
    ar.clear();
    ar.push_back(new MyData(this, 10, Qt::red,   hObject));
    ar.push_back(new MyData(this, 40, Qt::green, hObject));
    ar.push_back(new MyData(this, 70, Qt::blue,  hObject));

    HANDLE handle_ar[3]; //создаем потоки
    for (int i = 0; i < 3; ++i) {
        handle_ar[i] = CreateThread(0, 0, lpStartAddr, ar[i], CREATE_SUSPENDED, NULL);
        if(!handle_ar[i]){
             QMessageBox::information(this, "Info", "CreateThread failed for thread #"+i);
             for (int j=0; j<i; j++){CloseHandle(handle_ar[j]);} // если один из потоков не запустился корректно, то закрываем остальные и выходим
             return;
         }
        SetThreadAffinityMask (handle_ar[i], 1);
        QObject::connect(ar[i], SIGNAL(signalAddPoint(MyPoint)), ui->widget, SLOT(slotAddPoint(MyPoint)), Qt::QueuedConnection);
    }
    //задаем приоритеты
    int redPriority, greenPriority, bluePriority;
    int high =   THREAD_PRIORITY_ABOVE_NORMAL;
    int normal = THREAD_PRIORITY_NORMAL;
    int low =    THREAD_PRIORITY_BELOW_NORMAL;

    if(ui->radioButton->isChecked()) {redPriority = high;}
    else if(ui->radioButton_2->isChecked()) {redPriority = normal;}
    else {redPriority = low;}

    if(ui->radioButton_4->isChecked()) {greenPriority = high;}
    else if(ui->radioButton_5->isChecked()) {greenPriority = normal;}
    else {greenPriority = low;}

    if(ui->radioButton_7->isChecked()) {bluePriority = high;}
    else if(ui->radioButton_8->isChecked()) {bluePriority = normal;}
    else {bluePriority = low;}

    SetThreadPriority(handle_ar[0], redPriority);
    SetThreadPriority(handle_ar[1], greenPriority);
    SetThreadPriority(handle_ar[2], bluePriority);

    qDebug() << "Red priority = "   << redPriority;
    qDebug() << "Green priority = " << greenPriority;
    qDebug() << "Blue priority = "  << bluePriority;

    for (int i = 0; i < 3; ++i) {ResumeThread (handle_ar[i]);}
    for (int i = 0; i < 3; ++i) {CloseHandle  (handle_ar[i]);}
}


void MainWindow::CriticalSection(){
    m_X=0;
    prepareThreads(ThreadCs);
}

DWORD WINAPI MainWindow::ThreadCs( LPVOID lpParam ){
    EnterCriticalSection(&cs);
    MyData* data= reinterpret_cast<MyData*>(lpParam);
    int y=data->getY();
    QColor col=data->getCol();
    int max=data->getMax();

    for(int i=1; i<max/3; ++i){
        MyPoint p = MyPoint(QPoint(m_X, y), col);
        emit data->signalAddPoint(p);
        m_X+=1;
      Sleep(5);
    }
    qDebug()<<"thread function finished";
    LeaveCriticalSection(&cs);
    return 0;
}

void MainWindow::Mutex(){
    m_X=0;
    if(!hMutex){
        QMessageBox::information(this, "Info", "Mutex creation failed");
        return;
    }
    prepareThreads(MutexFunc, hMutex);
}

void MainWindow::SystemMutex(){
  m_X=0;
  if(!hNamedMutex){
       QMessageBox::information(this, "Info", "Named mutex creation failed");
       return;
  }
  prepareThreads(MutexFunc, hNamedMutex);
}

DWORD WINAPI MainWindow::MutexFunc( LPVOID lpParam ){
    MyData* data= reinterpret_cast<MyData*>(lpParam);
    int y=data->getY();
    QColor col=data->getCol();
    int max=data->getMax();
    HANDLE h=data->getHandle();
    WaitForSingleObject(h, INFINITE);

    for(int i=1; i<max/3; ++i){
        MyPoint p = MyPoint(QPoint(m_X, y), col);
        emit data->signalAddPoint(p);
        m_X+=1;
        //Sleep(5);
        for (volatile int i=0; i<1000000; i++) {;}
    }
    qDebug()<<"thread function finished";
    ReleaseMutex(h);
    return 0;
}

void MainWindow::Semaphore(){
    m_X=0;
    if(!hSema){
        QMessageBox::information(this, "Info", "Semaphore creation failed");
        return;
    }
    prepareThreads(SemaFunc, hSema);
}

void MainWindow::SystemSemaphore(){
    m_X=0;
    if(!hNamedSema){
         QMessageBox::information(this, "Info", "Named semaphore creation failed");
         return;
    }
    prepareThreads(SemaFunc, hNamedSema);
}

DWORD WINAPI MainWindow::SemaFunc( LPVOID lpParam ){
    MyData* data= reinterpret_cast<MyData*>(lpParam);
    int y=data->getY();
    QColor col=data->getCol();
    int max=data->getMax();
    HANDLE h=data->getHandle();
    WaitForSingleObject(h, INFINITE);

    for(int i=1; i<max/3; ++i){
        MyPoint p = MyPoint(QPoint(m_X, y), col);
        emit data->signalAddPoint(p);
        m_X+=1;
        //Sleep(5);
        for (volatile int i=0; i<1000000; i++) {;}
    }
    qDebug()<<"thread function finished";
    ReleaseSemaphore(h,1,0);
    return 0;
}


void MainWindow::ManualEvent(){
    m_X=0;
    if(!hManualEvent){
         QMessageBox::information(this, "Info", "Manual event creation failed");
         return;
    }
    prepareThreads(ManualEventFunc, hManualEvent);
}

DWORD WINAPI MainWindow::ManualEventFunc( LPVOID lpParam ){
    MyData* data= reinterpret_cast<MyData*>(lpParam);
    int y=data->getY();
    QColor col=data->getCol();
    int max=data->getMax();
    HANDLE h=data->getHandle();

    for(int i=1; i<max/3; ++i){
        WaitForSingleObject(h, INFINITE);
        MyPoint p = MyPoint(QPoint(m_X, y), col);
        emit data->signalAddPoint(p);
        m_X+=1;
        //Sleep(100);
        for (volatile int i=0; i<1000000; i++) {;}
    }
    return 0;
}

void MainWindow::ManualStop(){
    qDebug()<<"entered manualStop";
    ResetEvent(hManualEvent);
}

void MainWindow::ManualContinue(){
    qDebug()<<"entered manualContinue";
    SetEvent(hManualEvent);
}


void MainWindow::NamedManualEvent(){
    m_X=0;
    if(!hNamedManualEvent){
        QMessageBox::information(this, "Info", "Named manual event creation failed");
        return;
    }
    prepareThreads(ManualEventFunc, hNamedManualEvent);
}

void MainWindow::NamedManualStop(){
    qDebug()<<"entered manualStop";
    ResetEvent(hNamedManualEvent);
}

void MainWindow::NamedManualContinue(){
    qDebug()<<"entered manualContinue";
    SetEvent(hNamedManualEvent);
}


void MainWindow::AutoEvent(){
    m_X=0;
    if(!hAutoEvent){
        QMessageBox::information(this, "Info", "Auto event creation failed");
        return;
      }
      prepareThreads(AutoEventFunc, hAutoEvent);
}

DWORD WINAPI MainWindow::AutoEventFunc( LPVOID lpParam ){
    MyData* data= reinterpret_cast<MyData*>(lpParam);
    int y=data->getY();
    QColor col=data->getCol();
    int max=data->getMax();
    HANDLE h=data->getHandle();

    WaitForSingleObject(h, INFINITE);
    for(int i=1; i<max/3; ++i){
        MyPoint p = MyPoint(QPoint(m_X, y), col);
        emit data->signalAddPoint(p);
        m_X+=1;
        //Sleep(5);
        for (volatile int i=0; i<1000000; i++) {;}
   }
    SetEvent(h);
    return 0;
}
