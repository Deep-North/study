#ifndef MYPOINT_H
#define MYPOINT_H
#include <QColor>
#include <QPoint>
#include <QPainter>

class MyPoint
{
public:
    MyPoint(const QPoint &pt = QPoint(), QColor = Qt::black);
    void draw(QPainter & painter);
private:
    QPoint m_pt;
    QColor m_col;
};

#endif // MYPOINT_H
