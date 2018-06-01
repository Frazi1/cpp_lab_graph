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
    explicit GraphSubWindow(QWidget *parent = 0, Graph<int>* g = nullptr);
    ~GraphSubWindow();
    Graph<int>* GetGraph();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::GraphSubWindow *ui;
    Graph<int>* _graph{};
    GraphDrawer<int>* _graphDrawer;
    QPainter* _painter;
};



#endif // GRAPHSUBWINDOW_H
