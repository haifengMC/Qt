#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置父亲
    btn->setParent(this);
    //设置文字
    btn->setText("德玛西亚");
    //移动位置
    btn->move(100,100);

    connect(btn,&QPushButton::clicked,this,&Widget::printAbc);
    connect(btn,&QPushButton::clicked,this,&Widget::close);
}

Widget::~Widget()
{
    delete ui;
    delete btn;
}

void Widget::printAbc()
{
    qDebug() << "abc";
}
