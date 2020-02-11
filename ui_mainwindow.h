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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_a;
    QLineEdit *lineEdit_b;
    QLineEdit *lineEdit_res;
    QLabel *label;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_div;
    QRadioButton *radioButton_static;
    QRadioButton *radioButton_dll_task_3;
    QRadioButton *radioButton_dll_task_;
    QRadioButton *radioButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 323);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_a = new QLineEdit(centralWidget);
        lineEdit_a->setObjectName(QStringLiteral("lineEdit_a"));
        lineEdit_a->setGeometry(QRect(10, 70, 113, 22));
        lineEdit_b = new QLineEdit(centralWidget);
        lineEdit_b->setObjectName(QStringLiteral("lineEdit_b"));
        lineEdit_b->setGeometry(QRect(210, 70, 113, 22));
        lineEdit_res = new QLineEdit(centralWidget);
        lineEdit_res->setObjectName(QStringLiteral("lineEdit_res"));
        lineEdit_res->setGeometry(QRect(400, 70, 113, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 70, 55, 16));
        label->setAlignment(Qt::AlignCenter);
        pushButton_plus = new QPushButton(centralWidget);
        pushButton_plus->setObjectName(QStringLiteral("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(160, 10, 30, 30));
        pushButton_minus = new QPushButton(centralWidget);
        pushButton_minus->setObjectName(QStringLiteral("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(160, 50, 30, 30));
        pushButton_mult = new QPushButton(centralWidget);
        pushButton_mult->setObjectName(QStringLiteral("pushButton_mult"));
        pushButton_mult->setGeometry(QRect(160, 90, 30, 30));
        pushButton_div = new QPushButton(centralWidget);
        pushButton_div->setObjectName(QStringLiteral("pushButton_div"));
        pushButton_div->setGeometry(QRect(160, 130, 30, 30));
        radioButton_static = new QRadioButton(centralWidget);
        radioButton_static->setObjectName(QStringLiteral("radioButton_static"));
        radioButton_static->setGeometry(QRect(30, 170, 95, 20));
        radioButton_static->setCheckable(true);
        radioButton_static->setChecked(true);
        radioButton_dll_task_3 = new QRadioButton(centralWidget);
        radioButton_dll_task_3->setObjectName(QStringLiteral("radioButton_dll_task_3"));
        radioButton_dll_task_3->setGeometry(QRect(30, 200, 181, 20));
        radioButton_dll_task_ = new QRadioButton(centralWidget);
        radioButton_dll_task_->setObjectName(QStringLiteral("radioButton_dll_task_"));
        radioButton_dll_task_->setGeometry(QRect(30, 230, 181, 20));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(230, 170, 95, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 130, 93, 28));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 170, 93, 28));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 220, 91, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 220, 101, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_plus, SIGNAL(clicked()), MainWindow, SLOT(clickButtonPlus()));
        QObject::connect(pushButton_minus, SIGNAL(clicked()), MainWindow, SLOT(clickButtonMinus()));
        QObject::connect(pushButton_mult, SIGNAL(clicked()), MainWindow, SLOT(clickButtonMult()));
        QObject::connect(pushButton_div, SIGNAL(clicked()), MainWindow, SLOT(clickButtonDiv()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\260\321\200\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label->setText(QApplication::translate("MainWindow", "=", nullptr));
        pushButton_plus->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton_minus->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushButton_mult->setText(QApplication::translate("MainWindow", "*", nullptr));
        pushButton_div->setText(QApplication::translate("MainWindow", "/", nullptr));
        radioButton_static->setText(QApplication::translate("MainWindow", "Static lib", nullptr));
        radioButton_dll_task_3->setText(QApplication::translate("MainWindow", "DLL \320\275\320\265\321\217\320\262\320\275\320\276\320\265 \321\201\320\262\321\217\320\267\321\213\320\262\320\260\320\275\320\270\320\265", nullptr));
        radioButton_dll_task_->setText(QApplication::translate("MainWindow", "DLL \321\217\320\262\320\275\320\276\320\265 \321\201\320\262\321\217\320\267\321\213\320\262\320\260\320\275\320\270\320\265", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "DLL with DEF", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\230\320\272\320\276\320\275\320\272\320\260", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\272\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
