#include "graphedge.h"

GraphEdge::GraphEdge(GraphVertex* v1, GraphVertex* v2)
    :_v1(v1), _v2(v2)
{

}

GraphVertex* GraphEdge::GetV1() {
    return _v1;
}

GraphVertex* GraphEdge::GetV2() {
    return _v2;
}
