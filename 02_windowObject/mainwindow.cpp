#include <QAction>
#include <QStandardItemModel>
#include <QDebug>
#include <QCompleter>
#include <QDirModel>
#include <QTreeView>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCompleter *completer = new QCompleter();
    QDirModel *dir_model = new QDirModel();
    completer->setModel(dir_model);
    ui->lineEdit->setCompleter(completer);


    QStandardItem * item1 = new QStandardItem("Lang1");
    item1->appendRow(new QStandardItem("Java"));
    //item1->appendRows({ new QStandardItem("Java"), new QStandardItem("C++"), new QStandardItem("C#") });
    QStandardItem * item2 = new QStandardItem("Lang2");
    //item2->appendRow({ new QStandardItem("Perl"), new QStandardItem("Python"), new QStandardItem("Delphi"), new QStandardItem("Ruby") });

    QStandardItem * item3 = new QStandardItem("Lang1\\C++");

    QStandardItemModel* model = new QStandardItemModel();
    model->appendRow(item1);
    model->appendRow(item2);
    model->appendRow(item3);
    completer = new QCompleter(model);
    ui->lineEdit_2->setCompleter(completer);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addText()
{
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setItem(0, 0, new QStandardItem("张三"));
    model->setItem(0, 1, new QStandardItem("3"));
    model->setItem(0, 2, new QStandardItem("男"));
    model->setHorizontalHeaderLabels({"名字1", "名字2", "名字3"});
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_clicked()
{
    addText();
}

void MainWindow::on_pushButton_2_clicked()
{
    if (btnState)
        ui->tableView->show();
    else
        ui->tableView->hide();

    btnState = !btnState;
}
