/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit__WM_COPYDATA;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_task_2;
    QPushButton *pushButton_call_a_child;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_task_1_5;
    QPushButton *pushButton_poz_size;
    QPushButton *pushButton_chiProFromFoldr;
    QPushButton *pushButtonnotepadsuspended;
    QPushButton *pushButtonMinimized;
    QPushButton *pushButton3processes;
    QPushButton *pushButtonNotepad;
    QPushButton *pushButton_Maximized;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_create_file_mapping;
    QPushButton *pushButton_write_file_mapping;
    QPushButton *pushButton_close_file_mapping;
    QLineEdit *lineEdit_file_mapping;
    QLabel *label_file_mapping;
    QGroupBox *groupBox_5;
    QLineEdit *lineEdit_file_mapping_with_file;
    QPushButton *pushButton_create_file_mapping_with_file;
    QPushButton *pushButton_write__file_mapping_with_file;
    QPushButton *pushButton_read_file_mapping_with_file;
    QPushButton *pushButton_close__file_mapping_with_file;
    QLabel *label_file_mapping_with_file;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 340, 321, 61));
        lineEdit__WM_COPYDATA = new QLineEdit(groupBox);
        lineEdit__WM_COPYDATA->setObjectName(QStringLiteral("lineEdit__WM_COPYDATA"));
        lineEdit__WM_COPYDATA->setGeometry(QRect(10, 30, 261, 22));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 240, 321, 80));
        pushButton_task_2 = new QPushButton(groupBox_2);
        pushButton_task_2->setObjectName(QStringLiteral("pushButton_task_2"));
        pushButton_task_2->setGeometry(QRect(180, 30, 121, 28));
        pushButton_call_a_child = new QPushButton(groupBox_2);
        pushButton_call_a_child->setObjectName(QStringLiteral("pushButton_call_a_child"));
        pushButton_call_a_child->setGeometry(QRect(0, 30, 151, 31));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 10, 321, 211));
        pushButton_task_1_5 = new QPushButton(groupBox_3);
        pushButton_task_1_5->setObjectName(QStringLiteral("pushButton_task_1_5"));
        pushButton_task_1_5->setGeometry(QRect(200, 160, 93, 28));
        pushButton_poz_size = new QPushButton(groupBox_3);
        pushButton_poz_size->setObjectName(QStringLiteral("pushButton_poz_size"));
        pushButton_poz_size->setGeometry(QRect(200, 120, 93, 28));
        pushButton_chiProFromFoldr = new QPushButton(groupBox_3);
        pushButton_chiProFromFoldr->setObjectName(QStringLiteral("pushButton_chiProFromFoldr"));
        pushButton_chiProFromFoldr->setGeometry(QRect(20, 160, 151, 31));
        pushButtonnotepadsuspended = new QPushButton(groupBox_3);
        pushButtonnotepadsuspended->setObjectName(QStringLiteral("pushButtonnotepadsuspended"));
        pushButtonnotepadsuspended->setGeometry(QRect(22, 70, 151, 28));
        pushButtonMinimized = new QPushButton(groupBox_3);
        pushButtonMinimized->setObjectName(QStringLiteral("pushButtonMinimized"));
        pushButtonMinimized->setGeometry(QRect(200, 20, 93, 28));
        pushButton3processes = new QPushButton(groupBox_3);
        pushButton3processes->setObjectName(QStringLiteral("pushButton3processes"));
        pushButton3processes->setGeometry(QRect(22, 120, 151, 28));
        pushButtonNotepad = new QPushButton(groupBox_3);
        pushButtonNotepad->setObjectName(QStringLiteral("pushButtonNotepad"));
        pushButtonNotepad->setGeometry(QRect(22, 20, 151, 28));
        pushButton_Maximized = new QPushButton(groupBox_3);
        pushButton_Maximized->setObjectName(QStringLiteral("pushButton_Maximized"));
        pushButton_Maximized->setGeometry(QRect(200, 70, 93, 28));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(340, 20, 441, 201));
        pushButton_create_file_mapping = new QPushButton(groupBox_4);
        pushButton_create_file_mapping->setObjectName(QStringLiteral("pushButton_create_file_mapping"));
        pushButton_create_file_mapping->setGeometry(QRect(320, 20, 93, 28));
        pushButton_write_file_mapping = new QPushButton(groupBox_4);
        pushButton_write_file_mapping->setObjectName(QStringLiteral("pushButton_write_file_mapping"));
        pushButton_write_file_mapping->setGeometry(QRect(320, 60, 93, 28));
        pushButton_close_file_mapping = new QPushButton(groupBox_4);
        pushButton_close_file_mapping->setObjectName(QStringLiteral("pushButton_close_file_mapping"));
        pushButton_close_file_mapping->setGeometry(QRect(320, 160, 93, 28));
        lineEdit_file_mapping = new QLineEdit(groupBox_4);
        lineEdit_file_mapping->setObjectName(QStringLiteral("lineEdit_file_mapping"));
        lineEdit_file_mapping->setGeometry(QRect(30, 30, 261, 101));
        label_file_mapping = new QLabel(groupBox_4);
        label_file_mapping->setObjectName(QStringLiteral("label_file_mapping"));
        label_file_mapping->setGeometry(QRect(30, 160, 261, 20));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(340, 240, 441, 211));
        lineEdit_file_mapping_with_file = new QLineEdit(groupBox_5);
        lineEdit_file_mapping_with_file->setObjectName(QStringLiteral("lineEdit_file_mapping_with_file"));
        lineEdit_file_mapping_with_file->setGeometry(QRect(30, 50, 251, 101));
        lineEdit_file_mapping_with_file->setInputMethodHints(Qt::ImhMultiLine);
        pushButton_create_file_mapping_with_file = new QPushButton(groupBox_5);
        pushButton_create_file_mapping_with_file->setObjectName(QStringLiteral("pushButton_create_file_mapping_with_file"));
        pushButton_create_file_mapping_with_file->setGeometry(QRect(320, 30, 93, 28));
        pushButton_write__file_mapping_with_file = new QPushButton(groupBox_5);
        pushButton_write__file_mapping_with_file->setObjectName(QStringLiteral("pushButton_write__file_mapping_with_file"));
        pushButton_write__file_mapping_with_file->setGeometry(QRect(320, 70, 93, 28));
        pushButton_read_file_mapping_with_file = new QPushButton(groupBox_5);
        pushButton_read_file_mapping_with_file->setObjectName(QStringLiteral("pushButton_read_file_mapping_with_file"));
        pushButton_read_file_mapping_with_file->setGeometry(QRect(320, 110, 93, 28));
        pushButton_close__file_mapping_with_file = new QPushButton(groupBox_5);
        pushButton_close__file_mapping_with_file->setObjectName(QStringLiteral("pushButton_close__file_mapping_with_file"));
        pushButton_close__file_mapping_with_file->setGeometry(QRect(320, 150, 93, 28));
        label_file_mapping_with_file = new QLabel(groupBox_5);
        label_file_mapping_with_file->setObjectName(QStringLiteral("label_file_mapping_with_file"));
        label_file_mapping_with_file->setGeometry(QRect(30, 170, 251, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lab_1_Processes", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "WM_COPYDATA", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Task 2 send message", nullptr));
        pushButton_task_2->setText(QApplication::translate("MainWindow", "Task 2 send msg", nullptr));
        pushButton_call_a_child->setText(QApplication::translate("MainWindow", "Task 2 child window", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        pushButton_task_1_5->setText(QApplication::translate("MainWindow", "Task 1.5", nullptr));
        pushButton_poz_size->setText(QApplication::translate("MainWindow", "NP poz size", nullptr));
        pushButton_chiProFromFoldr->setText(QApplication::translate("MainWindow", "Child proc from folder", nullptr));
        pushButtonnotepadsuspended->setText(QApplication::translate("MainWindow", "P2 Notepad Suspended", nullptr));
        pushButtonMinimized->setText(QApplication::translate("MainWindow", "NP minimized", nullptr));
        pushButton3processes->setText(QApplication::translate("MainWindow", "3 processes together", nullptr));
        pushButtonNotepad->setText(QApplication::translate("MainWindow", "P1 Notepad", nullptr));
        pushButton_Maximized->setText(QApplication::translate("MainWindow", "NP maximized", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "File mapping", nullptr));
        pushButton_create_file_mapping->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButton_write_file_mapping->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButton_close_file_mapping->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        label_file_mapping->setText(QString());
        groupBox_5->setTitle(QApplication::translate("MainWindow", "File mapping with file", nullptr));
        pushButton_create_file_mapping_with_file->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButton_write__file_mapping_with_file->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButton_read_file_mapping_with_file->setText(QApplication::translate("MainWindow", "\320\247\321\202\320\265\320\275\320\270\320\265", nullptr));
        pushButton_close__file_mapping_with_file->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        label_file_mapping_with_file->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
