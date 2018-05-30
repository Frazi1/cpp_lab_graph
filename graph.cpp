#include "graph.h"

Graph::Graph()
{
   this->vertex = QMap<int, vector<int>*>();
}

QMap<int, vector<int>*> Graph::GetVertexLayers(int startVertex) {
    vector<int> evaluated;
    QMap<int, vector<int>*> res;
    res[startVertex] = new vector<int>();
    res[startVertex] = 0;
    evaluated.push_back(startVertex);

    //queue<int> nextVertex;
    //for(int v: *vertex[startVertex]) {
      //  nextVertex.push(v);
   // }

    //while (!nextVertex.empty()) {
      //  int next = nextVertex.pop();

    //}

    return res;

}

QMap<int, vector<int>*>& Graph::GetVertex(){
    return vertex;
}
