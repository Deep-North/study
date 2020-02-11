#include "spider.h"

spider::spider(QWidget *parent)
    : QWidget(parent)
{
    //флаги
//    this->setWindowFlags(Qt::CustomizeWindowHint
//                      | Qt::WindowTitleHint
//                      | Qt::WindowSystemMenuHint
//                      | Qt::WindowMinimizeButtonHint
//                      | Qt::WindowMaximizeButtonHint
//                      | Qt::WindowCloseButtonHint
//                      | Qt::WindowStaysOnTopHint);

//вывод окна на весь экран или свернутым
//    w.setWindowState(Qt::WindowFullScreen);
//    w.showMinimized();
    this->showNormal();

    //заголовок окна
    //w.setWindowTitle(QObject::tr("spider"));
    QString title = QObject::tr("spider");
    this->setWindowTitle(title);

    //меняю цвет фона при активном/неактивном окне
    QPalette palette;
    palette.setColor(QPalette::Active, QPalette::Background, Qt::darkRed);
    palette.setColor(QPalette::Inactive, QPalette::Background, Qt::darkGreen);
    this->setPalette(palette);

    //установка картинки фоном
    QPixmap pm("WomanAndDog.jpg");
    QBrush brush(pm);
    palette.setBrush(QPalette::Inactive, QPalette::Background, pm);
    this->setPalette(palette);

    //прозрачность
    this->setWindowOpacity(1);

    //иконка
    QIcon icon("icon2.ico");
    this->setWindowIcon(icon);

    //размеры и позиция
    //w.move(50, 50);
    //w.setGeometry(10,20,100,100);
    //w.resize(250,250);

    //расположить окно в нижней правой четверти
    QDesktopWidget* dw = QApplication::desktop();
    const QRect rect = dw->screenGeometry();
    this->move(rect.right()-pm.width(), rect.bottom()-pm.height());

    //задать минимальные и максимальные размеры окна
    this->setMinimumSize(500, 500);
    this->setMaximumSize(900, 900);

    //запретить менять размеры. использую размеры картинки
    this->setFixedSize(pm.width(), pm.height());

    //меняю курсор
    this->setCursor(Qt::PointingHandCursor);
   // this->unsetCursor();

    QPixmap pix("cursor1.cur");
    pix.setMask(QBitmap("cursor1.cur"));
    QCursor cr1(pix.scaled(28,28));
    this->setCursor(cr1);

    //стандартные диалоги. цвет фона
    QColor color = QColorDialog::getColor();
    if (color.isValid()){
        palette.setColor(QPalette::Active, QPalette::Background, color);
        //this->setPalette(palette);
    }

    //стандартные диалоги. имя файла картинки
    QString fileName = QFileDialog::getOpenFileName(0, "", QDir::currentPath(), ("Images (*.png *.bmp *.jpg)"));
    if( !fileName.isNull() )
        {
        QPixmap pm1(fileName);
        palette.setBrush(QPalette::Inactive, QPalette::Background, pm1);
        //this->setPalette(palette);
        }
    this->setPalette(palette);
}

spider::~spider()
{

}
