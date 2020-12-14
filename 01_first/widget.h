#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QDebug>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    QPushButton * btn = new QPushButton;
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

private Q_SLOTS:
    void printAbc();
};

#endif // WIDGET_H
