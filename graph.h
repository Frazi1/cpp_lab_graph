#ifndef GRAPH_H
#define GRAPH_H
#include <qmap.h>
#include "vertexlayer.h"
#include <queue>
#include <QVector>
#include <QQueue>

using namespace std;

template <class T>
class Graph
{
private:
    QMap<T, vector<T>*> vertex;
    Graph<T>* ExtractLayer(int layer, QVector<VertexLayer<T>*>* layers) {
        Graph<T>* res = new Graph<T>;

        for (VertexLayer<T>* vl: *layers) {
            if(vl->GetLayer() == layer){
                res->GetVertex().insert(vl->GetData(), new vector<int>);
            }
        }
        for (T layerGraphVertex: res->GetVertex().keys()) {
            for (int adjacentVertex: *GetVertex()[layerGraphVertex]) {
                if(res->GetVertex().contains(adjacentVertex))
                    res->GetVertex()[layerGraphVertex]->push_back(adjacentVertex);
            }
        }
        return res;
    }

public:
    Graph();
    Graph(QMap<T, vector<T>*> vertex);
    QMap<T, Graph<T>*>* GetVertexLayers(T startVertex) {
        QVector<VertexLayer<T>*> evaluated;

        QQueue<VertexLayer<T>*> vertexQueue;
        VertexLayer<T>* start = new VertexLayer<T>(startVertex, 0);
        vertexQueue.enqueue(start);
        evaluated.append(start);

        while(!vertexQueue.empty()) {
            VertexLayer<T>* current = vertexQueue.dequeue();
            vector<T>* adjacent = vertex[current->GetData()];
            for(T adj: *adjacent) {
                if(std::count_if(evaluated.begin(), evaluated.end(), [adj](VertexLayer<T>* vl) {return vl->GetData() == adj;}) == 0){
                    VertexLayer<T>* created = new VertexLayer<T>(adj, current->GetLayer() + 1);
                    evaluated.push_back(created);
                    vertexQueue.append(created);
                }
            }
        }
        QMap<T,Graph*>* layerGraphs = new QMap<T, Graph*>;
        VertexLayer<T>* maxLayer = *std::max_element(evaluated.begin(), evaluated.end(),
                                                     [](VertexLayer<T>* l, VertexLayer<T>* r) {
                return l->GetLayer() < r->GetLayer();
    });
        int max = maxLayer->GetLayer();
        for(int i= 1; i<= max; i++) {
            layerGraphs->insert(i, ExtractLayer(i, &evaluated));
        }
        return layerGraphs;

    }

    QMap<T, vector<T>*>& GetVertex() {
        return vertex;
    }
};

#endif // GRAPH_H
