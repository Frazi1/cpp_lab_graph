#ifndef GRAPHDRAWER_H
#define GRAPHDRAWER_H

#include <QPainter>
#include <graph.h>
#include <QVector>
#include <graphvertex.h>

class GraphDrawer
{
private:
    int _circleSize;
    QPainter* _painter;
    Graph* _graph{};
    QVector<GraphVertex*> _vertex{};
    void prepare();
    void drawVertex(GraphVertex* v);
    void drawEdge(GraphVertex* v1, GraphVertex* v2);
public:
    GraphDrawer(Graph* g, QPainter* p, int circleSize = 30);
    void draw();

};

#endif // GRAPHDRAWER_H
