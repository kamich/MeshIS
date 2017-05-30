#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../../Common/CommonMeshRepresentation.h"

using MeshIS::Model::Common::CMR;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Element_P6;
using MeshIS::Model::Common::Vertex;
using MeshIS::Model::Common::VertexID;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(CMR cm, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionGMsh_triggered();

    void on_actionGMsh_2_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
