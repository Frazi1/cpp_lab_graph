#include "graphvertex.h"

GraphVertex::GraphVertex(int x, int y, QString data)
    :X(x), Y(y), Data(data)
{

}

GraphVertex::GraphVertex(QPoint p, QString data): GraphVertex(p.x(), p.y(), data)
{

}
