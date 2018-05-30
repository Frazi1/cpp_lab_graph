#ifndef GRAPHVERTEX_H
#define GRAPHVERTEX_H

#include <QString>

class GraphVertex
{
public:
    GraphVertex(int x, int y, QString data);
    int X;
    int Y;
    QString Data;
};

#endif // GRAPHVERTEX_H
