#include "graphsubwindow.h"
#include "ui_graphsubwindow.h"

GraphSubWindow::GraphSubWindow(QWidget *parent, Graph<int>* g) :
    QMdiSubWindow(parent),
    ui(new Ui::GraphSubWindow),
    _graph(g)
{
    ui->setupUi(this);

    _graphDrawer = new GraphDrawer<int>(_graph);
    repaint();
}

GraphSubWindow::~GraphSubWindow()
{
    delete ui;
}

void GraphSubWindow::paintEvent(QPaintEvent *paintEvent) {
    Q_UNUSED(paintEvent);
     _painter = new QPainter(this);
    _graphDrawer->draw(_painter);
}


Graph<int>* GraphSubWindow::GetGraph() {
    return _graph;
}


