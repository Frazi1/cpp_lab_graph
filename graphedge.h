#ifndef GRAPHEDGE_H
#define GRAPHEDGE_H

#include "graphvertex.h"

template <class T>
class GraphEdge
{

private:
    GraphVertex<T>* _v1, *_v2;
public:
    GraphEdge(GraphVertex<T>* v1, GraphVertex<T>* v2) :_v1(v1), _v2(v2){

    }
    GraphVertex<T>* GetV1(){
        return _v1;
    }

    GraphVertex<T>* GetV2()  {
        return _v2;
    }
};

#endif // GRAPHEDGE_H
