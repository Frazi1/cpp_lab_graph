#ifndef VERTEXLAYER_H
#define VERTEXLAYER_H


class VertexLayer
{
private:
    int _data;
    int _layer;
public:
    VertexLayer(int data, int layer);
    int GetData();
    int GetLayer();
};

#endif // VERTEXLAYER_H
