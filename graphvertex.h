#ifndef GRAPHVERTEX_H
#define GRAPHVERTEX_H

#include <QString>
#include <QPoint>

class GraphVertex
{
public:
    GraphVertex(int x, int y, QString data);
    GraphVertex(QPoint p, QString data);
    int X;
    int Y;
    QString Data;
};

#endif // GRAPHVERTEX_H
