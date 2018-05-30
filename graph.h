#ifndef GRAPH_H
#define GRAPH_H
#include <qmap.h>
#include <queue>

using namespace std;

class Graph
{
private:
    QMap<int, vector<int>*> vertex;
public:
    Graph();
    QMap<int, vector<int>*> GetVertexLayers(int startVertex);
    QMap<int, vector<int>*>& GetVertex();
};

#endif // GRAPH_H
