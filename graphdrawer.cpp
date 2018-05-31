#include "graphdrawer.h"


GraphDrawer::GraphDrawer(Graph* g, int circleSize)
    : _graph(g),
      _circleSize(circleSize)
{
}

void GraphDrawer::prepare() {

    foreach (int data, _graph->GetVertex().keys()) {
        _vertex.append(new GraphVertex(getNextAvailablePoint(), QString::number(data)));
    }
    foreach (int data, _graph->GetVertex().keys()) {
        GraphVertex* curr = getVertexByData(QString::number(data));
        vector<int>* adjacent = _graph->GetVertex()[data];
        for(int v: *adjacent){
            GraphVertex* adjVertex = getVertexByData(QString::number(v));
            _edges.append(new GraphEdge(curr, adjVertex));
        }
    }
    alreadyPrepared = true;
//    _vertex.append(new GraphVertex(getNextAvailablePoint(),"DICSK"));
//    _vertex.append(new GraphVertex(getNextAvailablePoint(),"YUEB"));
}
GraphVertex* GraphDrawer::getVertexByData(QString data) {

    QVector<GraphVertex*>::iterator res = find_if(_vertex.begin(), _vertex.end(),[data](GraphVertex* v){
        return v->Data == data;
    });
    return *res;
}

void GraphDrawer::draw(QPainter* painter) {
    _painter = painter;
    if(!alreadyPrepared)
        prepare();
//    drawEdge(_vertex[0], _vertex[1]);
    painter->setBrush(Qt::white);
    for(GraphVertex* v: _vertex){
        drawVertex(v);
    }
    for(GraphEdge* e: _edges) {
        drawEdge(e);
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


void GraphDrawer::drawEdge(GraphEdge* e) {
    _painter->drawLine(e->GetV1()->X + _circleSize / 2,
                       e->GetV1()->Y + _circleSize / 2,
                       e->GetV2()->X + _circleSize / 2,
                       e->GetV2()->Y + _circleSize / 2);
}


QPoint GraphDrawer::getNextAvailablePoint() {
    int maxX = _painter->window().width();
    int maxY = _painter->window().height();


    for(int i = 0; i<tryCount; i++){
        int x = QRandomGenerator::global()->bounded(0, maxX);
        int y = QRandomGenerator::global()->bounded(0, maxY);
        if(isFreePosition(x, y))
            return QPoint(x, y);
    }
    throw "graph drawing error";

}

int GraphDrawer::getDistance(int x1, int y1, int x2, int y2) {
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

bool GraphDrawer::isFreePosition(int x, int y) {
    for(GraphVertex* v: _vertex) {
        if(getDistance(x,y, v->X, v->Y) < MIN_VERTEX_DISTANCE)
            return false;
    }
    return true;
}
