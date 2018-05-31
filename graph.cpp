#include "graph.h"

Graph::Graph()
{
   this->vertex = QMap<int, vector<int>*>();
}

QVector<Graph*>* Graph::GetVertexLayers(int startVertex) {
    QVector<VertexLayer*> evaluated;

    QQueue<VertexLayer*> vertexQueue;
    vertexQueue.enqueue(new VertexLayer(startVertex, 0));
    while(!vertexQueue.empty()) {
        VertexLayer* current = vertexQueue.dequeue();
        vector<int>* adjacent = vertex[current->GetData()];
        for(int adj: *adjacent) {
            if(std::count_if(evaluated.begin(), evaluated.end(), [adj](VertexLayer* vl) {return vl->GetData() == adj;}) == 0){
                evaluated.push_back(new VertexLayer(adj, current->GetLayer() + 1));
            }
        }
    }
    return res;

}

QMap<int, vector<int>*>& Graph::GetVertex(){
    return vertex;
}
