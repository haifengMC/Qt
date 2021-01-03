#ifndef WAREMGR_H
#define WAREMGR_H

#include <QMainWindow>
#include "waredata.h"

namespace Ui {
class WareMgr;
}

enum WareMode
{
    WareMode_PutIn,
    WareMode_PutOut,
    WareMode_Data,
};

#define PUTIN "入库"
#define PUTOUT "出库"

class WareMgr : public QMainWindow
{
    uint8_t mode = WareMode_PutIn;
    WareDataMgr dataMgr;

    Q_OBJECT

public:
    explicit WareMgr(QWidget *parent = 0);
    ~WareMgr();

    void fillTextLable();
    void fillTableView();
private:
    Ui::WareMgr *ui;

private Q_SLOTS:
    void putIn();
    void putOut();
    void on_lineEdit_editingFinished();
    void on_pushButton_clicked();
    void on_treeView_doubleClicked(const QModelIndex &index);
};

#endif // WAREMGR_H
