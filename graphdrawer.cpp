#include "graphdrawer.h"
#include <QPainter>
#include <QRect>

GraphDrawer::GraphDrawer(Graph* g, QPainter* p, int circleSize)
    : _painter(p),
      _graph(g),
      _circleSize(circleSize)
{
    prepare();
}

void GraphDrawer::prepare() {
    _vertex.append(new GraphVertex(20,20,"DICSK"));
    _vertex.append(new GraphVertex(50,70,"YUEB"));
}

void GraphDrawer::draw() {
    drawEdge(_vertex[0], _vertex[1]);
    for(GraphVertex* v: _vertex){
        _painter->setBrush(Qt::white);
        drawVertex(v);
    }

}

void GraphDrawer::drawVertex(GraphVertex* v) {
    QRect r = QRect(v->X, v->Y, _circleSize, _circleSize);

    _painter->drawEllipse(r);
    _painter->drawText(r, Qt::AlignCenter, v->Data);
//    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
//    painter->drawEllipse(x, y, circleSize, circleSize);
//    painter->drawText(x+circleSize/2, y + circleSize/2, data);
}


void GraphDrawer::drawEdge(GraphVertex* v1, GraphVertex* v2) {
    _painter->drawLine(v1->X + _circleSize / 2,
                       v1->Y + _circleSize / 2,
                       v2->X + _circleSize / 2,
                       v2->Y + _circleSize / 2);
}
