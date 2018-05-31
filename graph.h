#ifndef GRAPH_H
#define GRAPH_H
#include <qmap.h>
#include "vertexlayer.h"
#include <queue>
#include <QVector>
#include <QQueue>

using namespace std;

class Graph
{
private:
    QMap<int, vector<int>*> vertex;
public:
    Graph();
    QVector<Graph*>* GetVertexLayers(int startVertex);
    QMap<int, vector<int>*>& GetVertex();
};

#endif // GRAPH_H
