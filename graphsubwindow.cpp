#include "graphsubwindow.h"
#include "ui_graphsubwindow.h"

GraphSubWindow::GraphSubWindow(QWidget *parent, Graph<QString>* g) :
    QMdiSubWindow(parent),
    ui(new Ui::GraphSubWindow),
    _graph(g)
{
    ui->setupUi(this);
    _graphDrawer = new GraphDrawer<QString>(_graph);

}

GraphSubWindow::~GraphSubWindow()
{
    delete ui;
    delete _graph;
    delete _graphDrawer;
    delete _painter;
}

void GraphSubWindow::paintEvent(QPaintEvent *paintEvent) {
    Q_UNUSED(paintEvent);
    if(!paintFailed&& !paintInProgress) {
        paintInProgress = true;
        try {
            _painter = new QPainter(this);
            _graphDrawer->draw(_painter);
        }
        catch(ApplicationException& e) {
            ErrorHandler::GetInstance().Handle(e);
            paintFailed = true;
        }
        paintInProgress = false;
    }
}

Graph<QString>* GraphSubWindow::GetGraph() {
    return _graph;
}
