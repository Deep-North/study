#ifndef SALARY_H
#define SALARY_H

#include <QWidget>
#include <QPushButton>
#include <QLibraryInfo>
#include <QEvent>
#include <QMessageBox>

class salary : public QWidget
{
    Q_OBJECT

    QPushButton* yesButton;
    QPushButton* noButton;

public:
    salary(QWidget *parent = 0);
    ~salary();

    // QObject interface
public:
    virtual bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void handleButtonNo();
    void handleButtonYes();
};

#endif // SALARY_H
