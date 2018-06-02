#ifndef GRAPHVERTEX_H
#define GRAPHVERTEX_H

#include <QString>
#include <QPoint>

template <class T>
class GraphVertex
{
public:
    GraphVertex(int x, int y, T data):X(x), Y(y), Data(data){

    }

    GraphVertex(QPoint p, T data): GraphVertex(p.x(), p.y(), data){

    }
    int X;
    int Y;
    T Data;
};

#endif // GRAPHVERTEX_H
