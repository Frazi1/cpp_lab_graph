#ifndef GRAPHDRAWER_H
#define GRAPHDRAWER_H

#include <graph.h>
#include "graphvertex.h"
#include "graphedge.h"
#include <QPainter>
#include <QVector>
#include <QPoint>
#include <QRect>
#include <QRandomGenerator>

class GraphDrawer
{
private:
    const int MIN_VERTEX_DISTANCE = 35;
    const int tryCount = 100;

    bool alreadyPrepared = false;
    QPainter* _painter;

    int _circleSize;
    Graph* _graph{};
    QVector<GraphVertex*> _vertex{};
    QVector<GraphEdge*> _edges{};
    void prepare();

    void drawVertex(GraphVertex* v);
    void drawEdge(GraphEdge* e);
    QPoint getNextAvailablePoint();
    int getDistance(int x1, int y1, int x2, int y2);
    bool isFreePosition(int x, int y);
    GraphVertex* getVertexByData(QString data);
public:
    GraphDrawer(Graph* g, int circleSize = 30);
    void draw(QPainter* painter);
};

#endif // GRAPHDRAWER_H
