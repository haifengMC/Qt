#include <QDebug>
#include "ui_waremgr.h"
#include "waremgr.h"

WareMgr::WareMgr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WareMgr)
{
    ui->setupUi(this);

    //setStretchFactor(ui->lineEdit_2, 1);

    connect(ui->action, QAction::triggered, this, putIn);
    connect(ui->action_2, QAction::triggered, this, putOut);
}

WareMgr::~WareMgr()
{
    delete ui;
}

void WareMgr::putIn()
{
    ui->label->setText(PUTIN);
}

void WareMgr::putOut()
{
    ui->label->setText(PUTOUT);
}
