#include "graphsubwindow.h"
#include "ui_graphsubwindow.h"
#include "graphdrawer.h"

GraphSubWindow::GraphSubWindow(QWidget *parent) :
    QMdiSubWindow(parent),
    ui(new Ui::GraphSubWindow)
{
    ui->setupUi(this);
    repaint();
}

GraphSubWindow::~GraphSubWindow()
{
    delete ui;
}

void GraphSubWindow::paintEvent(QPaintEvent *paintEvent) {
    Q_UNUSED(paintEvent);
    QPainter p(this);
    GraphDrawer gd(nullptr, &p);
    gd.draw();
}
