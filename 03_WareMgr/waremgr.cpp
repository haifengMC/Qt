#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <vector>
#include <sstream>
#include "waredata.h"
#include "ui_waremgr.h"
#include "waremgr.h"

WareMgr::WareMgr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WareMgr)
{  
    ui->setupUi(this);

    //setStretchFactor(ui->lineEdit_2, 1);
    fillTextLable();
    fillTableView();
    QRegExp regx("[0-9]+$");
    QValidator* validator = new QRegExpValidator(regx, ui->lineEdit_3);
    ui->lineEdit_3->setValidator(validator);
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->action, QAction::triggered, this, putIn);
    connect(ui->action_2, QAction::triggered, this, putOut);
}

WareMgr::~WareMgr()
{
    delete ui;
}

void WareMgr::fillTextLable()
{
    std::ostringstream os;
    switch (mode)
    {
    case WareMode_PutIn:
        os << PUTIN << " ";
        ui->pushButton->setText(PUTIN);
        break;
    case WareMode_PutOut:
        os << PUTOUT << " ";
        ui->pushButton->setText(PUTOUT);
        break;
    default:
        break;
    }

    dataMgr.fillCurKey(os);
    ui->label->setText(os.str().c_str());
}

void WareMgr::fillTableView()
{
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,"类型");
    model->setHeaderData(1,Qt::Horizontal,"名称");
    model->setHeaderData(2,Qt::Horizontal,"数量");

    WareData* pData = dataMgr.getWareData();
    if (!pData)
        return;

    quint32 idx = 0;
    pData->fillBase(model, idx);
    pData->fillData(model, idx);
    pData->fillItem(model, idx);
    ui->treeView->setModel(model);
    ui->treeView->setColumnWidth(0,100);
    ui->treeView->setColumnWidth(1,200);
}

void WareMgr::putIn()
{
    mode = WareMode_PutIn;
    fillTextLable();
}

void WareMgr::putOut()
{
    mode = WareMode_PutOut;
    fillTextLable();
}

void WareMgr::on_lineEdit_editingFinished()
{
    if (dataMgr.entryKey(ui->lineEdit->text()))
    {
        fillTableView();
        fillTextLable();
    }

    ui->lineEdit->clear();
}

void WareMgr::on_pushButton_clicked()
{
    if (ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty())
    {
        QMessageBox::information(this, "注意", "商品和数量不能为空");
        return;
    }

    dataMgr.putIn(this, ui->lineEdit_2->text(), ui->lineEdit_3->text().toUInt());
    fillTableView();
}

void WareMgr::on_treeView_doubleClicked(const QModelIndex &index)
{
    if (dataMgr.entryClick(index.row()))
    {
        fillTableView();
        fillTextLable();
    }
}
