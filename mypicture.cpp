#include "mypicture.h"

myPicture::myPicture(QWidget *parent) : QWidget(parent)
{
    pixmap = new QPixmap(":/MyImages/images/WomenAndDog.jpg");
    //pixmap->load(":/MyImages/images/WomenAndDog.jpg");
    scale = 1;
}

void myPicture::paintEvent (QPaintEvent *){
    QPainter painter(this);
    QPixmap px = pixmap->scaled(this->width()*scale, this->height()*scale);
    painter.drawPixmap(0,0, px);
}

void myPicture::scaleChanged(int n){
    scale = n/100.0;
    qDebug() << scale;
    this->repaint();
}
