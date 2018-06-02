#ifndef VERTEXLAYER_H
#define VERTEXLAYER_H


template <class T>
class VertexLayer
{
private:
    T _data;
    int _layer;
public:
    VertexLayer(T data, int layer) : _data(data), _layer(layer) {
    }
    T GetData() {
        return _data;
    }
    int GetLayer() {
        return _layer;
    }
};

#endif // VERTEXLAYER_H
