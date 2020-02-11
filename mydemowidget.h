#ifndef MYDEMOWIDGET_H
#define MYDEMOWIDGET_H

#include <QWidget>
#include <mypoint.h>
#include <QObject>

class MyDemoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyDemoWidget(QWidget *parent = nullptr);
private:
    QVector<MyPoint>m_vector;

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void slotAddPoint(MyPoint);
    void Clear();
};

#endif // MYDEMOWIDGET_H
