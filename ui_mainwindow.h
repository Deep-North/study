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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mydemowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    MyDemoWidget *widget;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_7;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(867, 406);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 10, 93, 28));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 10, 93, 28));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(520, 10, 121, 28));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(520, 50, 121, 28));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(760, 20, 93, 28));
        widget = new MyDemoWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 200, 821, 141));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(80, 60, 41, 121));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 10, 95, 20));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 50, 95, 20));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 90, 95, 20));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(130, 60, 41, 121));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 10, 95, 20));
        radioButton_4->setChecked(true);
        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 50, 95, 20));
        radioButton_6 = new QRadioButton(groupBox_2);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(10, 90, 95, 20));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(180, 60, 51, 121));
        radioButton_8 = new QRadioButton(groupBox_3);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        radioButton_8->setGeometry(QRect(20, 50, 95, 20));
        radioButton_9 = new QRadioButton(groupBox_3);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        radioButton_9->setGeometry(QRect(20, 90, 95, 20));
        radioButton_7 = new QRadioButton(groupBox_3);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setGeometry(QRect(20, 10, 95, 20));
        radioButton_7->setChecked(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 150, 55, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 110, 55, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 70, 55, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 10, 71, 21));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 50, 93, 28));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(410, 50, 93, 28));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 40, 55, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 40, 55, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 40, 55, 16));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(300, 110, 93, 28));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(410, 110, 93, 28));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(520, 110, 111, 28));
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(300, 150, 131, 28));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(450, 150, 121, 28));
        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(590, 150, 151, 28));
        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(760, 110, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 867, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_6, SIGNAL(clicked()), widget, SLOT(Clear()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(ThreadsGo()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(Mutex()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), MainWindow, SLOT(Semaphore()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), MainWindow, SLOT(SystemSemaphore()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(CriticalSection()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), MainWindow, SLOT(SystemMutex()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), MainWindow, SLOT(ManualEvent()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), MainWindow, SLOT(ManualStop()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), MainWindow, SLOT(ManualContinue()));
        QObject::connect(pushButton_14, SIGNAL(clicked()), MainWindow, SLOT(AutoEvent()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), MainWindow, SLOT(NamedManualEvent()));
        QObject::connect(pushButton_12, SIGNAL(clicked()), MainWindow, SLOT(NamedManualStop()));
        QObject::connect(pushButton_13, SIGNAL(clicked()), MainWindow, SLOT(NamedManualContinue()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lab_3_Threads", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Threads go", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Mutex", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Semaphore", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Named semaphore", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        groupBox->setTitle(QString());
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        groupBox_2->setTitle(QString());
        radioButton_4->setText(QString());
        radioButton_5->setText(QString());
        radioButton_6->setText(QString());
        groupBox_3->setTitle(QString());
        radioButton_8->setText(QString());
        radioButton_9->setText(QString());
        radioButton_7->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Low", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Normal", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "High", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "PRIORITY", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Critical section", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "Named mutex", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Blue", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Red", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Green", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "Manual event", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "Manual stop", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "Manual continue", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "Named manual event", nullptr));
        pushButton_12->setText(QApplication::translate("MainWindow", "Named manual stop", nullptr));
        pushButton_13->setText(QApplication::translate("MainWindow", "Named manual continue", nullptr));
        pushButton_14->setText(QApplication::translate("MainWindow", "Auto event", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
