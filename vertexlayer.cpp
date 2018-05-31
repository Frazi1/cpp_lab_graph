#include "vertexlayer.h"

VertexLayer::VertexLayer(int data, int layer)
    : _data(data), _layer(layer)
{

}

int VertexLayer::GetData() {
    return _data;
}

int VertexLayer::GetLayer() {
    return _layer;
}
