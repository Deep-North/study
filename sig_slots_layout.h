#ifndef SIG_SLOTS_LAYOUT_H
#define SIG_SLOTS_LAYOUT_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QSignalMapper>
#include <QGridLayout>
#include <QStackedLayout>
#include <QComboBox>
#include <QSpacerItem>
#include <QFrame>


class sig_slots_layout : public QWidget
{
    Q_OBJECT

public:
    QPushButton* buttonExit;
    QPushButton* buttonVertical;
    QPushButton* buttonHorizontal;
    QPushButton* buttonGrid;
    QPushButton* buttonStacked;

    QHBoxLayout* mainLayout;

    QLineEdit*  lineEdit;
    QSpinBox*   spinBox;
    QSlider*    slider;
    QLabel*     label;

    QHBoxLayout*    hBoxLayout;
    QVBoxLayout*    buttonsLayout;
    QVBoxLayout*    vBoxLayout;
    QGridLayout*    gridLayout;
    QStackedLayout* stackLayout;
    QVBoxLayout*    demoStackLayout;
    QComboBox*      combo;

    QSignalMapper*  mapper;


    QFrame*         myQFrame;
    QHBoxLayout*    frameLayout;
    QPushButton*    buttonEnDis;
    QVBoxLayout*    EDEbuttonsLayout;


signals:
    void mySignal(int n);

private slots:
    void lineEdit_valueChanged(QString);
    void changeLayout(QObject* pNewLayout);
    void buttonEnDisCklicked();

public:
    sig_slots_layout(QWidget *parent = 0);
    ~sig_slots_layout();
};

#endif // SIG_SLOTS_LAYOUT_H
