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
#include <QVariant>

template<class T>
class GraphDrawer
{
private:
    const int MIN_VERTEX_DISTANCE = 35;
    const int tryCount = 100;

    bool alreadyPrepared = false;
    QPainter* _painter;

    int _circleSize;
    Graph<T>* _graph{};
    QVector<GraphVertex<T>*> _vertex{};
    QVector<GraphEdge<T>*> _edges{};

    void prepare() {
        foreach (T data, _graph->GetVertex().keys()) {
            _vertex.append(new GraphVertex<T>(getNextAvailablePoint(), data));
        }
        foreach (T data, _graph->GetVertex().keys()) {
            GraphVertex<T>* curr = getVertexByData(data);

            vector<T>* adjacent =  _graph->GetVertex()[data];//TODO: make generic
            for(T v: *adjacent){
                GraphVertex<T>* adjVertex = getVertexByData(v);
                _edges.append(new GraphEdge<T>(curr, adjVertex));
            }
        }
        alreadyPrepared = true;
    }

    void drawVertex(GraphVertex<T>* v) {
        QRect r = QRect(v->X, v->Y, _circleSize, _circleSize);

        _painter->drawEllipse(r);
        //TODO: tostring
        _painter->drawText(r, Qt::AlignCenter, QVariant(v->Data).value<QString>());
    }

    void drawEdge(GraphEdge<T>* e) {
        _painter->drawLine(e->GetV1()->X + _circleSize / 2,
                           e->GetV1()->Y + _circleSize / 2,
                           e->GetV2()->X + _circleSize / 2,
                           e->GetV2()->Y + _circleSize / 2);
    }

    QPoint getNextAvailablePoint() {
        int maxX = _painter->window().width();
        int maxY = _painter->window().height();


        for(int i = 0; i<tryCount; i++){
            int x = QRandomGenerator::global()->bounded(0, maxX);
            int y = QRandomGenerator::global()->bounded(0, maxY);
            if(isFreePosition(x, y))
                return QPoint(x, y);
        }
        throw "graph drawing error";

    }

    int getDistance(int x1, int y1, int x2, int y2) {
        return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    }

    bool isFreePosition(int x, int y) {
        for(GraphVertex<T>* v: _vertex) {
            if(getDistance(x,y, v->X, v->Y) < MIN_VERTEX_DISTANCE)
                return false;
        }
        return true;
    }

    GraphVertex<T>* getVertexByData(T data) {
        typename QVector<GraphVertex<T> *>::iterator res = find_if(_vertex.begin(), _vertex.end(),[data](GraphVertex<T>* v){
                return v->Data == data;
    });
        return *res;
    }

public:
    GraphDrawer(Graph<T>* g, int circleSize = 30)     : _graph(g),
        _circleSize(circleSize){

    }

    void draw(QPainter* painter) {
        _painter = painter;
        if(!alreadyPrepared)
            prepare();
        //    drawEdge(_vertex[0], _vertex[1]);

        for(GraphEdge<T>* e: _edges) {
            drawEdge(e);
        }
        for(GraphVertex<T>* v: _vertex){
            painter->setBrush(Qt::white);
            drawVertex(v);
        }
    }
};

#endif // GRAPHDRAWER_H
