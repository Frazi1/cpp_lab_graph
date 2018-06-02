#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include <QPen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnFileOpenClick() {
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Graph"), "",
            tr("Graph (*.txt);;All Files (*)"));
    GraphReader gr;
    Graph<QString>* g = gr.ReadGraphFromFile(fileName);

   CreateGraphSubWindow(g, "Test");
}

void MainWindow::OnLayersClick(){
    GraphSubWindow* active =  dynamic_cast<GraphSubWindow*>(ui->mdiArea->activeSubWindow());
    if(active != nullptr) {
       QMap<int, Graph<QString>*>* layers = active->GetGraph()->GetVertexLayers("1");
       for(int layer: layers->keys()) {
           CreateGraphSubWindow((*layers)[layer], QString::number(layer));
       }
    }
}

void MainWindow::CreateGraphSubWindow(Graph<QString>* g, QString title){
    GraphSubWindow* w = new GraphSubWindow(ui->mdiArea, g);
    w->setWindowTitle(title);
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
}
