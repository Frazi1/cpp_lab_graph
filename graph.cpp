#include "graph.h"

Graph::Graph()
{
   this->vertex = QMap<int, vector<int>*>();
}

QMap<int, Graph*>* Graph::GetVertexLayers(int startVertex) {
    QVector<VertexLayer*> evaluated;

    QQueue<VertexLayer*> vertexQueue;
    VertexLayer* start = new VertexLayer(startVertex, 0);
    vertexQueue.enqueue(start);
    evaluated.append(start);

    while(!vertexQueue.empty()) {
        VertexLayer* current = vertexQueue.dequeue();
        vector<int>* adjacent = vertex[current->GetData()];
        for(int adj: *adjacent) {
            if(std::count_if(evaluated.begin(), evaluated.end(), [adj](VertexLayer* vl) {return vl->GetData() == adj;}) == 0){
                VertexLayer* created = new VertexLayer(adj, current->GetLayer() + 1);
                evaluated.push_back(created);
                vertexQueue.append(created);
            }
        }
    }
    QMap<int,Graph*>* layerGraphs = new QMap<int, Graph*>;
    VertexLayer* maxLayer = *std::max_element(evaluated.begin(), evaluated.end(),
                                    [](VertexLayer* l, VertexLayer* r) {
                                     return l->GetLayer() < r->GetLayer();
                                    });
    int max = maxLayer->GetLayer();
    for(int i= 1; i<= max; i++) {
        layerGraphs->insert(i, ExtractLayer(i, &evaluated));
    }
    return layerGraphs;

}

QMap<int, vector<int>*>& Graph::GetVertex(){
    return vertex;
}

Graph* Graph::ExtractLayer(int layer, QVector<VertexLayer*>* layers){
    Graph* res = new Graph;

    for (VertexLayer* vl: *layers) {
        if(vl->GetLayer() == layer){
            res->GetVertex().insert(vl->GetData(), new vector<int>);
        }
    }
    for (int layerGraphVertex: res->GetVertex().keys()) {
        for (int adjacentVertex: *GetVertex()[layerGraphVertex]) {
            if(res->GetVertex().contains(adjacentVertex))
                res->GetVertex()[layerGraphVertex]->push_back(adjacentVertex);
        }
    }
    return res;
}
