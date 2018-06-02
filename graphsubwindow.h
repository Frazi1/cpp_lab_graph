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
    explicit GraphSubWindow(QWidget *parent = 0, Graph<QString>* g = nullptr);
    ~GraphSubWindow();
    Graph<QString>* GetGraph();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::GraphSubWindow *ui;
    Graph<QString>* _graph{};
    GraphDrawer<QString>* _graphDrawer;
    QPainter* _painter;
};



#endif // GRAPHSUBWINDOW_H
