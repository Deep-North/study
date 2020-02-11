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
    QLabel *label;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_file_mapping;
    QPushButton *pushButton_create_file_mapping;
    QPushButton *pushButton_read_file_mapping;
    QPushButton *pushButton_close_file_mapping;
    QLabel *label_file_mapping;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_file_mapping_wf;
    QLabel *label_file_mapping_wf;
    QPushButton *pushButton_create_file_mapping_wf;
    QPushButton *pushButton_write_file_mapping_wf;
    QPushButton *pushButton_read_file_mapping_wf;
    QPushButton *pushButton_close_file_mapping_wf;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 381, 71));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 351, 31));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 90, 381, 141));
        lineEdit_file_mapping = new QLineEdit(groupBox_2);
        lineEdit_file_mapping->setObjectName(QStringLiteral("lineEdit_file_mapping"));
        lineEdit_file_mapping->setGeometry(QRect(10, 20, 241, 41));
        pushButton_create_file_mapping = new QPushButton(groupBox_2);
        pushButton_create_file_mapping->setObjectName(QStringLiteral("pushButton_create_file_mapping"));
        pushButton_create_file_mapping->setGeometry(QRect(270, 20, 93, 28));
        pushButton_read_file_mapping = new QPushButton(groupBox_2);
        pushButton_read_file_mapping->setObjectName(QStringLiteral("pushButton_read_file_mapping"));
        pushButton_read_file_mapping->setGeometry(QRect(270, 60, 93, 28));
        pushButton_close_file_mapping = new QPushButton(groupBox_2);
        pushButton_close_file_mapping->setObjectName(QStringLiteral("pushButton_close_file_mapping"));
        pushButton_close_file_mapping->setGeometry(QRect(270, 100, 93, 28));
        label_file_mapping = new QLabel(groupBox_2);
        label_file_mapping->setObjectName(QStringLiteral("label_file_mapping"));
        label_file_mapping->setGeometry(QRect(10, 100, 241, 21));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 240, 381, 191));
        lineEdit_file_mapping_wf = new QLineEdit(groupBox_3);
        lineEdit_file_mapping_wf->setObjectName(QStringLiteral("lineEdit_file_mapping_wf"));
        lineEdit_file_mapping_wf->setGeometry(QRect(20, 30, 231, 111));
        lineEdit_file_mapping_wf->setInputMethodHints(Qt::ImhMultiLine);
        label_file_mapping_wf = new QLabel(groupBox_3);
        label_file_mapping_wf->setObjectName(QStringLiteral("label_file_mapping_wf"));
        label_file_mapping_wf->setGeometry(QRect(20, 150, 231, 21));
        pushButton_create_file_mapping_wf = new QPushButton(groupBox_3);
        pushButton_create_file_mapping_wf->setObjectName(QStringLiteral("pushButton_create_file_mapping_wf"));
        pushButton_create_file_mapping_wf->setGeometry(QRect(270, 30, 93, 28));
        pushButton_write_file_mapping_wf = new QPushButton(groupBox_3);
        pushButton_write_file_mapping_wf->setObjectName(QStringLiteral("pushButton_write_file_mapping_wf"));
        pushButton_write_file_mapping_wf->setGeometry(QRect(270, 70, 93, 28));
        pushButton_read_file_mapping_wf = new QPushButton(groupBox_3);
        pushButton_read_file_mapping_wf->setObjectName(QStringLiteral("pushButton_read_file_mapping_wf"));
        pushButton_read_file_mapping_wf->setGeometry(QRect(270, 110, 93, 28));
        pushButton_close_file_mapping_wf = new QPushButton(groupBox_3);
        pushButton_close_file_mapping_wf->setObjectName(QStringLiteral("pushButton_close_file_mapping_wf"));
        pushButton_close_file_mapping_wf->setGeometry(QRect(270, 150, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Child window for message", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217 \320\276\321\202 WM_COPYDATA", nullptr));
        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "File mapping", nullptr));
        pushButton_create_file_mapping->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButton_read_file_mapping->setText(QApplication::translate("MainWindow", "\320\247\321\202\320\265\320\275\320\270\320\265", nullptr));
        pushButton_close_file_mapping->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        label_file_mapping->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "File mapping with file", nullptr));
        label_file_mapping_wf->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_create_file_mapping_wf->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButton_write_file_mapping_wf->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButton_read_file_mapping_wf->setText(QApplication::translate("MainWindow", "\320\247\321\202\320\265\320\275\320\270\320\265", nullptr));
        pushButton_close_file_mapping_wf->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
