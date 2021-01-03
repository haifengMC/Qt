#include <QApplication>
#include "waredata.h"
#include "waremgr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WareMgr w;
    w.show();

    return a.exec();
}
