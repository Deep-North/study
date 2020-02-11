#include "mypoint.h"

MyPoint::MyPoint(const QPoint &pt, QColor col)
{
    m_pt=pt;
    m_col=col;
}

void MyPoint::draw(QPainter & painter){
    painter.setPen(QPen(m_col));
    painter.drawLine(m_pt.rx(), m_pt.ry(), m_pt.rx(), m_pt.ry() + 10);
}
