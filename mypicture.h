#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QDebug>


class myPicture : public QWidget
{
    Q_OBJECT

    QPixmap* pixmap;
    double scale;

public:
    explicit myPicture(QWidget *parent = nullptr);
    //~myPicture();

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void scaleChanged(int);
};

#endif // MYPICTURE_H
