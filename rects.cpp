#include "rects.h"

rects::rects(QWidget *parent)
    : QWidget(parent)
{
    this->isDrawing = false;
}

rects::~rects()
{
}

void rects::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::LeftButton){
        isDrawing = true;
        m_startPoint = event->pos();
    }
}

void rects::mouseReleaseEvent(QMouseEvent*) {
    if (isDrawing){

        QRect rect;
        rect.setRect(m_startPoint.x(), m_startPoint.y(), (currentPosition.x()-m_startPoint.x()), (currentPosition.y()-m_startPoint.y()));
        rectList.append(rect);
        this->isDrawing = false;
    }
}

void rects::mouseMoveEvent(QMouseEvent * event) {

    if (isDrawing) {
        currentPosition = event->pos();
        repaint();
    }
}

void rects::drawMyRect(QPainter *painter) {
    painter->setPen(QPen(Qt::darkRed, 5, Qt::SolidLine));
    QRect rect;
    rect.setRect(m_startPoint.x(), m_startPoint.y(), (currentPosition.x()-m_startPoint.x()), (currentPosition.y()-m_startPoint.y()));
    painter->drawRect(rect);
    //rectList.append(rect);
}

void rects::drawMyRects(QPainter*painter){
    painter->setPen(QPen(Qt::darkRed,5,Qt::SolidLine));

    //qDebug()<<"ponit9";
    //qDebug()<<rectList.size();
    for(int i=0; i<rectList.size(); ++i){painter->drawRect(rectList[i]);}
    QRect rect;
    rect.setRect(m_startPoint.x(),m_startPoint.y(),(currentPosition.x()-m_startPoint.x()),(currentPosition.y()-m_startPoint.y()));
    painter->drawRect(rect);
    }

void rects::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    if(this->isDrawing) {
        qDebug() << rectList.size();
        this->drawMyRects(&painter);
    }
}
