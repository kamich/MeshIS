#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../Export/GMsh/ExportGMsh.cpp"
#include "../../Import/Abaqus/Abaqus_Importer.cpp"

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
{   // export GMsh
    MeshExport exportGMsh;
    exportGMsh.Export("test_export.msh", c);
    ui->label->setText("Finished export to .msh format");
}

void MainWindow::on_actionGMsh_2_triggered()
{   // import GMsh
    Abaqus_Importer importGMsh;
    importGMsh.Import("../../../../TestData/MeshFiles/Abaqus/test1_fluent.inp");
    ui->label->setText("Finished import from .msh file");
}
