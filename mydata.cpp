#include "mydata.h"

MyData::MyData(QObject *parent, int y, QColor col, HANDLE hObject) : QObject(parent)
{
    m_y=y;
    m_col=col;
    m_hObject=hObject;
}
