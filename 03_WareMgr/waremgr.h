#ifndef WAREMGR_H
#define WAREMGR_H

#include <QMainWindow>

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

struct WareTypeStr
{
    std::vector<size_t> key;
    QString name;
};

struct WareItem
{
    std::vector<size_t> key;
    QString name;
    size_t num = 0;
    size_t createTime = 0;
    size_t updateTime = 0;

    WareItem(const QString& key, const QString& name, size_t num);
};

class WareMgr : public QMainWindow
{
    uint8_t mode = WareMode_PutIn;
    std::map<std::vector<size_t>, WareItem> data;

    Q_OBJECT

public:
    explicit WareMgr(QWidget *parent = 0);
    ~WareMgr();

private:
    Ui::WareMgr *ui;

private Q_SLOTS:
    void putIn();
    void putOut();
};

#endif // WAREMGR_H
