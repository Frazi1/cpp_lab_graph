#include "graphsubwindow.h"
#include "ui_graphsubwindow.h"

GraphSubWindow::GraphSubWindow(QWidget *parent, Graph<QString>* g) :
    QMdiSubWindow(parent),
    ui(new Ui::GraphSubWindow),
    _graph(g)
{
    ui->setupUi(this);

    _graphDrawer = new GraphDrawer<QString>(_graph);
    repaint();
}

GraphSubWindow::~GraphSubWindow()
{
    delete ui;
    delete _graph;
    delete _graphDrawer;
}

void GraphSubWindow::paintEvent(QPaintEvent *paintEvent) {
    Q_UNUSED(paintEvent);
     _painter = new QPainter(this);
    _graphDrawer->draw(_painter);
}


Graph<QString>* GraphSubWindow::GetGraph() {
    return _graph;
}


