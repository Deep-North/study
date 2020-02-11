#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>
#include <QApplication>
#include <QIcon>
#include <QPalette>
#include <QPixmap>
#include <QDesktopWidget>
#include <QBitmap>
#include <QColorDialog>
#include <QFileDialog>
#include <QString>
#include <QTranslator>
#include <QLibraryInfo>

class spider : public QWidget
{
    Q_OBJECT

public:
    spider(QWidget *parent = 0);
    ~spider();
};

#endif // SPIDER_H
