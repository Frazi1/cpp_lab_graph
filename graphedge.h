#ifndef GRAPHEDGE_H
#define GRAPHEDGE_H

#include "graphvertex.h"

class GraphEdge
{

private:
    GraphVertex* _v1, *_v2;
public:
    GraphEdge(GraphVertex* v1, GraphVertex* v2);
    GraphVertex* GetV1();
    GraphVertex* GetV2();
};

#endif // GRAPHEDGE_H
