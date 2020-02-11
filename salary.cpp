#include "salary.h"

salary::salary(QWidget *parent)
    : QWidget(parent)
{
    yesButton = new QPushButton(tr("Yes"), this);
    yesButton->setGeometry(QRect(QPoint(50, 220), QSize(150, 50)));

    noButton = new QPushButton(tr("No"), this);
    noButton->setGeometry(QRect(QPoint(450, 220), QSize(150, 50)));

    noButton->installEventFilter(this);

    connect(yesButton, SIGNAL (released()), this, SLOT (handleButtonYes()));
    connect(noButton, SIGNAL (released()), this, SLOT (handleButtonNo()));
}

salary::~salary()
{

}


bool salary::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseMove || event->type() == QEvent::HoverEnter || event->type() == QEvent::HoverMove) {
        while (true) {
            int xDirection = (noButton->x() > width()/2) ? -1 : 1;
            int yDirection = (noButton->y() > height()/2) ? -1 : 1;
            QRect tmpRect(
                        noButton->x() + (rand()%width() - noButton->width()) * xDirection,
                        noButton->y() + (rand()%width() - noButton->width()) * yDirection,
                        noButton->width(),
                        noButton->height()
                        );
            if(!this->rect().contains(tmpRect)) {
                                xDirection = -xDirection;
                                yDirection = -yDirection;
                                continue;
                            }
            noButton->setGeometry(tmpRect);
            break;
        }
    }
}

void salary::handleButtonYes() {
    QMessageBox msgBox;
    msgBox.setText(tr("This is very good!"));
    msgBox.exec();
}

void salary::handleButtonNo() {
    QMessageBox msgBox;
    msgBox.setText(tr("Why are you fooling us?"));
    msgBox.exec();
}
