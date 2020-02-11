#ifndef RECTS_H
#define RECTS_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QList>

class rects : public QWidget
{
    Q_OBJECT

    bool isDrawing;

    QPoint currentPosition;
    QPoint m_startPoint;

    QList<QRect> rectList;

public:
    rects(QWidget *parent = 0);
    ~rects();

    void drawMyRect(QPainter* painter);
    void drawMyRects(QPainter* painter);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent*);
    ///virtual void resizeEvent(QResizeEvent *event);
};

#endif // RECTS_H
