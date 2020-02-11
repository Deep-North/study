#include "mydemowidget.h"
#include <qDebug>
MyDemoWidget::MyDemoWidget(QWidget *parent) : QWidget(parent)
{
qRegisterMetaType<MyPoint>("MyPoint"); //механизм сигналов/слотов при взаимодействии между потоками реализуется посредством событий =>
//чтобы параметр, передаваемый в сигнале по значению (в нашем случае MyPoint), «завернуть» в событие, мета-объектная система должна «знать»
//о пользовательском типе =>пользовательский тип нужно зарегистрировать посредством шаблона
//int qRegisterMetaType  (const char * typeName), где  typeName - тип
}


void MyDemoWidget::slotAddPoint(MyPoint p){
    m_vector.push_back(p);
    repaint();
}

void MyDemoWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    foreach(MyPoint x, m_vector ){ x.draw(painter);}
}

void MyDemoWidget::Clear(){
    m_vector.clear();
    repaint();
}
