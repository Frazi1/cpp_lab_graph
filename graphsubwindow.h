#ifndef GRAPHSUBWINDOW_H
#define GRAPHSUBWINDOW_H

#include <QWidget>
#include <QMdiSubWindow>
#include "graph.h"
#include "graphdrawer.h"
#include "errorhandler.h"


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
    void showEvent(QShowEvent* event ) override {
        QWidget::showEvent( event );
        isShown = true;
    }

private:
    Ui::GraphSubWindow *ui;
    Graph<QString>* _graph{};
    GraphDrawer<QString>* _graphDrawer;
    QPainter* _painter;
    bool paintFailed = false;
    bool paintInProgress = false;
    bool isShown = false;
};



#endif // GRAPHSUBWINDOW_H
