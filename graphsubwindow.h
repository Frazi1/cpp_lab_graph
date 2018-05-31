#ifndef GRAPHSUBWINDOW_H
#define GRAPHSUBWINDOW_H

#include <QWidget>
#include <QMdiSubWindow>
#include "graph.h"
#include "graphdrawer.h"


namespace Ui {
class GraphSubWindow;
}

class GraphSubWindow : public QMdiSubWindow
{
    Q_OBJECT

public:
    explicit GraphSubWindow(QWidget *parent = 0, Graph* g = nullptr);
    ~GraphSubWindow();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::GraphSubWindow *ui;
    Graph* _graph{};
    GraphDrawer* _graphDrawer;
    QPainter* _painter;
};



#endif // GRAPHSUBWINDOW_H
