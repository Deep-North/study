#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>
#include <QColor>
#include <Windows.h>
#include "MyPoint.h"

class MyData : public QObject
{
    Q_OBJECT
public:
    explicit MyData(QObject *parent = nullptr, int y=0, QColor col=Qt::black, HANDLE hObject=NULL);
    int getY(){return m_y;}
    QColor getCol(){return m_col;}
    int getMax(){return m_maxX;}
    HANDLE getHandle(){return m_hObject;}

 private:
    int m_y;            //индивидуальная для потока координата Y
    QColor m_col;       //индивидуальный цвет
    int m_maxX=800;    //«докуда» рисовать
    HANDLE m_hObject;   //дескриптор синхронизирующего объекта

signals:

    void signalAddPoint (MyPoint);

public slots:


};

#endif // MYDATA_H
