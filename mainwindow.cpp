#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

#define BUF_SIZE 256

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

void MainWindow::on_pushButtonNotepad_clicked()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    wchar_t nm[] = L"notepadd";

    if (!CreateProcess (
                0,
                nm,
                NULL,
                NULL,
                FALSE,
                0,
                NULL,
                NULL,
                &si,
                &pi))
        {
        //QMessageBox::information(this, QString("Info"), QString("CreateProcess failed."), MB_OK );
        QMessageBox::warning(this, QString("Info"), QString("CreateProcess failed."), MB_OK, MB_OK);
        return;
        }

    CloseHandle( pi.hThread );


    // Wait until child process exits.
    if(WaitForSingleObject( pi.hProcess, INFINITE )!=WAIT_FAILED){

        DWORD dwExitCode;
        GetExitCodeProcess(pi.hProcess, &dwExitCode);

        FILETIME    lpCreationTime;
        FILETIME    lpExitTime;
        FILETIME    lpKernelTime;
        FILETIME    lpUserTime;
        SYSTEMTIME  systime;

        GetProcessTimes(pi.hProcess, &lpCreationTime, &lpExitTime, &lpKernelTime, &lpUserTime);//заполняем эти четыре переменные данными процесса pi.hProcess
        qlonglong time = *reinterpret_cast<qlonglong*>(&lpExitTime) - *reinterpret_cast<qlonglong*>(&lpCreationTime);// вычисляем время жизни процесса
        FileTimeToSystemTime(reinterpret_cast<FILETIME*>(&time), &systime);//преобразуем переменную time типа FILETIME в системное время UTC.
        //Это структура вида:
        //typedef struct _SYSTEMTIME {    WORD wYear;    WORD wMonth;    WORD wDayOfWeek;    WORD wDay;    WORD wHour;    WORD wMinute;    WORD wSecond;    WORD wMilliseconds;
        //} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

        //QString str;
        //QMessageBox msg;
        //msg.setText(QString("Exit code: ") + QString::number(dwExitCode) +
        //            QString("\nProcess life time: ") + str.setNum(systime.wMinute) + QString(" minutes, ")
        //            + str.setNum(systime.wSecond) + QString(" seconds."));
        //msg.exec();
        QMessageBox::information(this, QString("Process Life Time"), (QString("Exit code: ") + QString::number(dwExitCode) +
                                  QString("\nProcess was alive: ") + QString::number(systime.wSecond) + QString(" seconds, ")
                                  + QString::number(systime.wMilliseconds) + QString(" milliseconds.")));
    }
    // Close process and thread handles.
    CloseHandle( pi.hProcess );

}

void MainWindow::on_pushButtonnotepadsuspended_clicked()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    wchar_t nm[] = L"notepad";

    if (!CreateProcess (0, nm, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi))
    {
        QMessageBox::warning(this, QString("Info"), QString("CreateProcess failed."), MB_OK, MB_OK);
        return;
    }


    CloseHandle( pi.hProcess );


    Sleep(5000);
    ResumeThread(pi.hThread);

    // Wait until child process exits.
    if (WaitForSingleObject( pi.hProcess, INFINITE )!=WAIT_FAILED){
        DWORD dwExitCode;
        GetExitCodeProcess(pi.hProcess, &dwExitCode);

        FILETIME    lpCreationTime;
        FILETIME    lpExitTime;
        FILETIME    lpKernelTime;
        FILETIME    lpUserTime;
        SYSTEMTIME  systime;

        GetProcessTimes(pi.hProcess, &lpCreationTime, &lpExitTime, &lpKernelTime, &lpUserTime);
        qlonglong time = *reinterpret_cast<qlonglong*>(&lpExitTime) - *reinterpret_cast<qlonglong*>(&lpCreationTime);
        FileTimeToSystemTime(reinterpret_cast<FILETIME*>(&time), &systime);

        QMessageBox::information(this, QString("Process Life Time"), (QString("Exit code: ") + QString::number(dwExitCode) +
                              QString("\nProcess was alive: ") + QString::number(systime.wSecond) + QString(" seconds, ")
                              + QString::number(systime.wMilliseconds) + QString(" milliseconds.")));
    }
    // Close process and thread handles.

    CloseHandle( pi.hThread );
}

void MainWindow::on_pushButton3processes_clicked()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi[3];

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    for (int i=0; i<3; i++){
        ZeroMemory( &pi, sizeof(pi[i]));
    }

    wchar_t nm[][8] = {L"notepad", L"cmd", L"mspaint"};

    HANDLE handle_arr[3];
    for (int i=0; i<3; i++){
        if (CreateProcess (0, nm[i], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi[i]))
        {
            handle_arr[i] = pi[i].hProcess;
            CloseHandle( pi[i].hThread );
        }
        else
        {
            QMessageBox::warning(this, QString("Info"), QString("CreateProcess failed."), MB_OK, MB_OK);
            return;
        }
    }

    while(true) {
        DWORD res = MsgWaitForMultipleObjects(3, handle_arr, FALSE, INFINITE, QS_ALLEVENTS);
        if(res>=WAIT_OBJECT_0 && res<WAIT_OBJECT_0+3) { break;}

        MSG m;
        while(PeekMessage(&m,0,0,0,PM_REMOVE)) {
            DispatchMessage(&m);//"обрабатываем" сообщение
        }
    }
    DWORD dwExitCode[3];
    int pid;

    for (int i=0; i<3; i++) {
        GetExitCodeProcess(pi[i].hProcess, &dwExitCode[i]);
        if (dwExitCode[i] == STILL_ACTIVE) {
            TerminateProcess(pi[i].hProcess, 10);
        }
        else pid = i;
        CloseHandle( pi[i].hProcess );
    }

    QString msg_3;
    switch (pid) {
    case 0:
        msg_3 = "notepad was closed\ncmd and paint was terminated"; break;
    case 1:
        msg_3 = "cmd was closed\nnotepad and paint was terminated"; break;
    case 2:
        msg_3 = "paint was closed\ncmd and notepad was terminated"; break;
    default:
        msg_3 = "error"; break;
    }

    QMessageBox:: information(this, QString("Who was killed"), (QString(msg_3)));
}

void MainWindow::on_pushButtonMinimized_clicked()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_MINIMIZE;
    ZeroMemory( &pi, sizeof(pi) );

    wchar_t nm[] = L"notepad";

    if (!CreateProcess (0, nm, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        QMessageBox::warning(this, QString("Info"), QString("CreateProcess failed."), MB_OK, MB_OK);
        return;
    }

    // Wait until child process exits.
    if(WaitForSingleObject( pi.hProcess, INFINITE )!=WAIT_FAILED)
    {

        DWORD dwExitCode;
        GetExitCodeProcess(pi.hProcess, &dwExitCode);

        FILETIME    lpCreationTime;
        FILETIME    lpExitTime;
        FILETIME    lpKernelTime;
        FILETIME    lpUserTime;
        SYSTEMTIME  systime;

        GetProcessTimes(pi.hProcess, &lpCreationTime, &lpExitTime, &lpKernelTime, &lpUserTime);//заполняем эти четыре переменные данными процесса pi.hProcess
        qlonglong time = *reinterpret_cast<qlonglong*>(&lpExitTime) - *reinterpret_cast<qlonglong*>(&lpCreationTime);// вычисляем время жизни процесса
        FileTimeToSystemTime(reinterpret_cast<FILETIME*>(&time), &systime);//преобразуем переменную time типа FILETIME в системное время UTC.

        QMessageBox::information(this, QString("Process Life Time"), (QString("Exit code: ") + QString::number(dwExitCode) +
                                  QString("\nProcess was alive: ") + QString::number(systime.wSecond) + QString(" seconds, ")
                                  + QString::number(systime.wMilliseconds) + QString(" milliseconds.")));
    }
    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );//убить их нужно раньше
}

void MainWindow::on_pushButton_Maximized_clicked()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_MAXIMIZE;
    ZeroMemory( &pi, sizeof(pi));

    wchar_t nm[] = L"notepad";

    if (!CreateProcess (0, nm, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        QMessageBox::warning(this, QString("Info"), QString("CreateProcess failed."), MB_OK, MB_OK);
        return;
    }

    // Wait until child process exits.
    if(WaitForSingleObject( pi.hProcess, INFINITE )!=WAIT_FAILED)
    {

        DWORD dwExitCode;
        GetExitCodeProcess(pi.hProcess, &dwExitCode);

        FILETIME    lpCreationTime;
        FILETIME    lpExitTime;
        FILETIME    lpKernelTime;
        FILETIME    lpUserTime;
        SYSTEMTIME  systime;

        GetProcessTimes(pi.hProcess, &lpCreationTime, &lpExitTime, &lpKernelTime, &lpUserTime);//заполняем эти четыре переменные данными процесса pi.hProcess
        qlonglong time = *reinterpret_cast<qlonglong*>(&lpExitTime) - *reinterpret_cast<qlonglong*>(&lpCreationTime);// вычисляем время жизни процесса
        FileTimeToSystemTime(reinterpret_cast<FILETIME*>(&time), &systime);//преобразуем переменную time типа FILETIME в системное время UTC.

        QMessageBox::information(this, QString("Process Life Time"), (QString("Exit code: ") + QString::number(dwExitCode) +
                                  QString("\nProcess was alive: ") + QString::number(systime.wSecond) + QString(" seconds, ")
                                  + QString::number(systime.wMilliseconds) + QString(" milliseconds.")));
    }
    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );

}

void MainWindow::on_pushButton_poz_size_clicked()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);

    si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE | STARTF_USEFILLATTRIBUTE;
    si.dwX = 1000;
    si.dwY = 800;

//    si.dwFlags = STARTF_USESIZE;
    si.dwXSize = 200;
    si.dwYSize = 200;

//    si.dwFlags = STARTF_USEFILLATTRIBUTE;
    si.dwFillAttribute = FOREGROUND_RED| BACKGROUND_GREEN;

    ZeroMemory( &pi, sizeof(pi) );

    wchar_t nm[] = L"cmd";

    if (!CreateProcess (0, nm, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        QMessageBox::warning(this, QString("Info"), QString("CreateProcess failed."), MB_OK, MB_OK);
        return;
    }

    // Wait until child process exits.
    if(WaitForSingleObject( pi.hProcess, INFINITE )!=WAIT_FAILED)
    {

        DWORD dwExitCode;
        GetExitCodeProcess(pi.hProcess, &dwExitCode);

        FILETIME    lpCreationTime;
        FILETIME    lpExitTime;
        FILETIME    lpKernelTime;
        FILETIME    lpUserTime;
        SYSTEMTIME  systime;

        GetProcessTimes(pi.hProcess, &lpCreationTime, &lpExitTime, &lpKernelTime, &lpUserTime);//заполняем эти четыре переменные данными процесса pi.hProcess
        qlonglong time = *reinterpret_cast<qlonglong*>(&lpExitTime) - *reinterpret_cast<qlonglong*>(&lpCreationTime);// вычисляем время жизни процесса
        FileTimeToSystemTime(reinterpret_cast<FILETIME*>(&time), &systime);//преобразуем переменную time типа FILETIME в системное время UTC.

        QMessageBox::information(this, QString("Process Life Time"), (QString("Exit code: ") + QString::number(dwExitCode) +
                                  QString("\nProcess was alive: ") + QString::number(systime.wSecond) + QString(" seconds, ")
                                  + QString::number(systime.wMilliseconds) + QString(" milliseconds.")));
    }
    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );

}

void MainWindow::on_pushButton_chiProFromFoldr_clicked()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);

    wchar_t nm[] = L"C:\\Program Files (x86)\\Microsoft Office\\Office12\\WINWORD.exe";

    if (!CreateProcess (0, nm, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        QMessageBox::warning(this, QString("Info"), QString("CreateProcess failed."), MB_OK, MB_OK);
        return;
    }

    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}

void MainWindow::on_pushButton_task_1_5_clicked()
{
    const TCHAR fileName[] = L"task_1_5.txt";

    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;

    HANDLE hFile = CreateFile(fileName,
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_WRITE | FILE_SHARE_READ,
        &sa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if(hFile == INVALID_HANDLE_VALUE)
    {
        QMessageBox::warning(this, QString("Info"), QString("Create file failed."), MB_OK, MB_OK);
        return;
    }

    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdOutput = hFile;

    PROCESS_INFORMATION pi;
    TCHAR czCommandLine[] = L"C:\\Users\\Deep-North\\YandexDisk\\Avalon 2\\Semestr 4\\Process_Interconnection\\test_out\\debug\\test_out";
    int res =  CreateProcess( 0, czCommandLine, 0, 0, TRUE, 0, 0, 0, &si, &pi);

    if((BOOL)res) {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread) ;
    } else {
        QMessageBox::warning(this, QString("Info"), QString("Create process failed."), MB_OK, MB_OK);
    }
    CloseHandle(hFile);
}

void MainWindow::on_pushButton_task_2_clicked()
{
    TCHAR czCommandLine[] = L"C:\\Users\\Deep-North\\YandexDisk\\Avalon 2\\Semestr 4\\Process_Interconnection\\receiver\\debug\\receiver.exe";
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);

    int res =  CreateProcess( 0, czCommandLine, 0, 0, TRUE, 0, 0, 0, &si, &pi);
    if(!(BOOL)res) {
         QMessageBox::warning(this, QString("Info"), QString("Create process failed."), MB_OK, MB_OK);
    }
    Sleep(1000);

    int eventId = 1000;
    qDebug() << "1";
    static DWORD nMsg = RegisterWindowMessage(L"Test msg");
    qDebug() << nMsg;
    PostMessage(HWND_BROADCAST, nMsg, NULL, NULL);
    qDebug() << "3";
}

void MainWindow::on_pushButton_call_a_child_clicked()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);

    si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
    si. dwX =1000;
    si. dwY =800;
    si.dwXSize = 500;
    si.dwYSize = 1000;

//    wchar_t nm[] = L"C:\\Users\\Deep-North\\YandexDisk\\Avalon 2\\Semestr 4\\Process_Interconnection\\receiver\\debug\\receiver.exe";
    wchar_t nm[] = L"..\\receiver\\debug\\receiver.exe";

    if (!CreateProcess (0, nm, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        QMessageBox::warning(this, QString("Info"), QString("CreateProcess failed."), MB_OK, MB_OK);
        return;
    }

    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}

void MainWindow::on_lineEdit__WM_COPYDATA_textChanged(const QString &arg1)
{
    HWND hChild  = FindWindowA(0, "Child window for message");
    HWND hParent = FindWindowA(0, "Lab_1_Processes");

    if(hParent == 0) {
        QMessageBox::critical(0,"Fail", "Cannot find window 'Parent process'!");
        return;
    }
    if(hChild == 0) {
        QMessageBox::critical(0,"Fail", "Cannot find window 'Child process'!");
        return;
    }

    QString msgText = ui->lineEdit__WM_COPYDATA->text();
    std::string strMsgText = msgText.toStdString();
    int countBytesStrMsgText = (int)strMsgText.length() + 1;
    const char* chMsgText = strMsgText.c_str();

    COPYDATASTRUCT data;
    data.dwData = 33;
    data.cbData = (DWORD)countBytesStrMsgText;
    data.lpData = (LPVOID)chMsgText;

    SendMessageA(hChild, WM_COPYDATA, (WPARAM)hParent, (LPARAM) &data);
}

void MainWindow::on_pushButton_create_file_mapping_clicked()
{
    hfilemap = CreateFileMapping(
                INVALID_HANDLE_VALUE,       // hFile
                0,                          // lpFileMappingAttributes
                PAGE_READWRITE,             // flProtect
                0,                          // dwMaximumSizeHigh
                sizeFMapping,               // dwMaximumSizeLow
                L"MyFileMapping"             // lpName
                );
    if (hfilemap == 0){
        QMessageBox::critical(0, "Fail", "Cannot create filemapping!");
        return;
    }

    // CREATE MAP VIEW OF FILE
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

void MainWindow::on_pushButton_write_file_mapping_clicked()
{
    QString file_mapping_text = ui->lineEdit_file_mapping->text();
    qDebug() << "fmText:" << file_mapping_text;

    QByteArray bytes_file_mapping_text = file_mapping_text.toUtf8();
    char* p = bytes_file_mapping_text.data();
    strcpy(static_cast<char*>(MapViewOfFile(hfilemap,FILE_MAP_WRITE,0,0,0)), p);
    qDebug() << "p:" << p;

    ui->label_file_mapping->setText("INFO: File mapping saved");
    qDebug() << "File mapping saved";
}

void MainWindow::on_pushButton_close_file_mapping_clicked()
{
    UnmapViewOfFile(pMap);
    CloseHandle(hfilemap);
    ui->label_file_mapping->setText("INFO: File mapping closed");
}

void MainWindow::on_lineEdit_file_mapping_textChanged(const QString &arg1)
{
    UINT MyFileMappingMsg = RegisterWindowMessageA("FileMappingChangedParent");
    WPARAM wParam = 0;
    LPARAM lParam = 0;
    PostMessageA(HWND_BROADCAST, MyFileMappingMsg, wParam, lParam);
}




//______________________________________________________________________________________________________________________







void MainWindow::on_pushButton_create_file_mapping_with_file_clicked()
{
        hfile_wf = CreateFileA("test.txt",
                    GENERIC_READ | GENERIC_WRITE,         //полный доступ для своего процесса
                    FILE_SHARE_READ | FILE_SHARE_WRITE,   //полный доступ для других процессов
                    NULL,
                    OPEN_ALWAYS,
                    FILE_ATTRIBUTE_NORMAL,
                    0);
        if (hfile_wf == INVALID_HANDLE_VALUE){
            QMessageBox::critical(0, "Fail", "INVALID_HANDLE_VALUE");
            return;
        }
        else {
            ui->label_file_mapping_with_file->setText("INFO: File created or opened.");
            qDebug() << "File created or opened.";
        }

        hfilemap_wf = CreateFileMappingA(
                    hfile_wf,                   // hfile_wf
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
                       hfilemap_wf,    // hfileMappingObject
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



        ui->label_file_mapping_with_file->setText("INFO: File mapping created");
}

void MainWindow::on_pushButton_write__file_mapping_with_file_clicked()
{
    QString file_mapping_text_wf = ui->lineEdit_file_mapping_with_file->text();
    qDebug() << "fm_wf_Text:" << file_mapping_text_wf;

    QByteArray bytes_file_mapping_text_wf = file_mapping_text_wf.toUtf8();
    char* p = bytes_file_mapping_text_wf.data();
    strcpy(static_cast<char*>(pMap_wf), p);
    qDebug() << "p:" << p;

    ui->label_file_mapping_with_file->setText("INFO: File mapping saved");
    qDebug() << "File mapping saved";
}

void MainWindow::on_pushButton_read_file_mapping_with_file_clicked()
{
    hfilemap_wf = OpenFileMapping(FILE_MAP_READ, 0, L"MyFileMapping_wf");
    qDebug() << hfilemap_wf;

    char* p = static_cast<char*>(MapViewOfFile(hfilemap_wf, FILE_MAP_READ, 0, 0, 0));
    qDebug() << "p:" << p;

    ui->lineEdit_file_mapping_with_file->setText(p);
    ui->label_file_mapping_with_file->setText("INFO: File mapping loaded");

//    char* p = static_cast<char*>(ReadFile(hfile_wf, lpBuffer, &nNumberOfBytesToRead, 0, NULL));
//    ui->lineEdit_file_mapping_with_file->setText(p);

}

void MainWindow::on_pushButton_close__file_mapping_with_file_clicked()
{
    //Освобождение ресурсов
    UnmapViewOfFile(pMap_wf);
    CloseHandle(hfilemap_wf);
    CloseHandle(hfile_wf);
    ui->label_file_mapping_with_file->setText("INFO: File mapping closed");
}

void MainWindow::on_lineEdit_file_mapping_with_file_textChanged(const QString &arg1)
{
    UINT MyFileMappingMsg_wf = RegisterWindowMessageA("FileMappingChangedParent_wf");
    WPARAM wParam = 0;
    LPARAM lParam = 0;
    PostMessageA(HWND_BROADCAST, MyFileMappingMsg_wf, wParam, lParam);
}
