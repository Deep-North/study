#include "spider2.h"


spider2::spider2(QWidget *parent)
    : QWidget(parent)
{
    this->isDrawing = false;
    this->isDrawing2 = false;
    this->leftButtonPressed = false;
    this->rigthButtonPressed = false;
    this->setCursor(Qt::PointingHandCursor);
}

spider2::~spider2()
{

}


void spider2::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::RightButton){                   //если нажата правая кнопка мыши

        //если нажат модифаер (клавиша ctrl)
        if (event->modifiers() == Qt::KeyboardModifier::ControlModifier){
            currentPosition = event->pos();
            QString strX = QString().setNum(currentPosition.x());
            QString strY = QString().setNum(currentPosition.y());
            QString s = "x= " + strX + ", y=  " + strY;

            QToolTip::showText(event->globalPos(), s);
        }

        //рисуем правой кнопкой
        rigthButtonPressed = true;
        isDrawing2 = true;
        m_startPoint = event->pos();
    }

    if (event->button() == Qt::MouseButton::LeftButton){
        leftButtonPressed = true;
        isDrawing = true;
    }
}

void spider2::mouseReleaseEvent(QMouseEvent*) {
    if (leftButtonPressed){
        this->leftButtonPressed = false;
        this->isDrawing = false;
        this->setCursor(Qt::PointingHandCursor);
        repaint();
    }

    if (rigthButtonPressed){
        this->rigthButtonPressed = false;
        this->isDrawing2 = false;
        QRect rect;
        rect.setRect(m_startPoint.x(), m_startPoint.y(), (currentPosition.x()-m_startPoint.x()), (currentPosition.y()-m_startPoint.y()));
        rectList.append(rect);
    }
}

void spider2::mouseMoveEvent(QMouseEvent * event) {

    if (leftButtonPressed) {
        if(!this->rect().contains(event->pos())) {
            this->setCursor(Qt::PointingHandCursor);
            return;
        }
        if(this->isDrawing) {
            currentPosition = event->pos();
            repaint();
        }
    }

    if (rigthButtonPressed && isDrawing2) {
        currentPosition = event->pos();
        repaint();
    }
}

void spider2::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    if(this->isDrawing) {
        this->drawWeb(&painter);
    }

    if (this->isDrawing2) {
        this->drawMyRects(&painter);
    }
}

void spider2::drawWeb(QPainter* painter) {

    QPixmap pix("cursor1.cur");
    pix.setMask(QBitmap("cursor1.cur"));
    this->setCursor(pix);

    int linesCoords[8][4] = {
        {currentPosition.x(), currentPosition.y(), 0, 0},
        {currentPosition.x(), currentPosition.y(), width()/2, 0},
        {currentPosition.x(), currentPosition.y(), width(), 0},
        {currentPosition.x(), currentPosition.y(), width(), height()/2},
        {currentPosition.x(), currentPosition.y(), width(), height()},
        {currentPosition.x(), currentPosition.y(), width()/2, height()},
        {currentPosition.x(), currentPosition.y(), 0, height()},
        {currentPosition.x(), currentPosition.y(), 0, height()/2}
    };

    painter->setPen(QPen(Qt::darkRed, 1, Qt::SolidLine));
    for(int i = 0; i < 8; i ++) {
        painter->drawLine(linesCoords[i][0], linesCoords[i][1], linesCoords[i][2], linesCoords[i][3]);
        painter->drawEllipse(currentPosition, width()*(i+1)/16, height()*(i+1)/16);
    }
}

void spider2::drawMyRect(QPainter *painter) {
    painter->setPen(QPen(Qt::darkRed, 5, Qt::SolidLine));
    QRect rect;
    rect.setRect(m_startPoint.x(), m_startPoint.y(), (currentPosition.x()-m_startPoint.x()), (currentPosition.y()-m_startPoint.y()));
    painter->drawRect(rect);
    rectList.append(rect);
}

void spider2::drawMyRects(QPainter *painter){
    painter->setPen(QPen(Qt::darkRed,5,Qt::SolidLine));

    //qDebug()<<"ponit9";
    //qDebug()<<rectList.size();
    for(int i=0; i<rectList.size(); ++i){painter->drawRect(rectList[i]);}
    QRect rect;
    rect.setRect(m_startPoint.x(),m_startPoint.y(),(currentPosition.x()-m_startPoint.x()),(currentPosition.y()-m_startPoint.y()));
    painter->drawRect(rect);
}

void spider2::resizeEvent(QResizeEvent *event)
{
    QString title = "паучок: ширина= " + QString().setNum(width()) + ", высота= " + QString().setNum(height());
    this->setWindowTitle(title);
}
