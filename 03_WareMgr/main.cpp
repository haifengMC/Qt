#include "waremgr.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WareMgr w;
    w.show();

    return a.exec();
}
