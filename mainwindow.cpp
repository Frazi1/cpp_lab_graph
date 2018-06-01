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
    Graph* g = gr.ReadGraphFromFile(fileName);

    GraphSubWindow* w = new GraphSubWindow(ui->mdiArea, g);
    w->setWindowTitle("DICK");
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();

    QPainter p(w);
    p.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    p.drawEllipse(10, 10, 100, 100);

}

void MainWindow::OnLayersClick(){
    GraphSubWindow* active =  dynamic_cast<GraphSubWindow*>(ui->mdiArea->activeSubWindow());
    if(active != nullptr) {
       QMap<int, Graph*>* layers = active->GetGraph()->GetVertexLayers(1);
    }
}
