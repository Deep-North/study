#ifndef SPIDER2_H
#define SPIDER2_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QToolTip>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>
#include <QList>

class spider2 : public QWidget
{
    Q_OBJECT

    bool isDrawing;
    bool isDrawing2;
    bool leftButtonPressed;
    bool rigthButtonPressed;

    QPoint currentPosition;
    QPoint m_startPoint;

    QList<QRect> rectList;

public:
    spider2(QWidget *parent = 0);
    ~spider2();

    void drawWeb(QPainter* painter);
    void drawMyRect(QPainter* painter);
    void drawMyRects(QPainter* painter);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent*);
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // SPIDER2_H
