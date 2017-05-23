#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../Export/GMsh/ExportGMsh.cpp"

CMR c;

MainWindow::MainWindow(CMR cm, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    c = cm;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionGMsh_triggered()
{
    MeshExport exportGMsh;
    exportGMsh.Export("test_export.msh", c);
    ui->label->setText("Finished export to .msh format");
}
