#include "graphreader.h"

GraphReader::GraphReader()
{

}

Graph<QString>* GraphReader::ReadGraphFromFile(QString path){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        throw ApplicationException(file.errorString());
    }

    QTextStream in(&file);

    Graph<QString>* g = new Graph<QString>;
    while(!in.atEnd()) {
        QStringList lineVertex = in.readLine().split(" ");
        lineVertex.removeAll("");
        if(!lineVertex.isEmpty()) {
            g->GetVertex().insert(lineVertex[0], new vector<QString>);
            for(QString& v: lineVertex) {
                if(v != lineVertex[0])
                    g->GetVertex()[lineVertex[0]]->push_back(v);
            }
        }
    }

    file.close();
    return g;
}

void GraphReader::SaveGraphToFile(QString path, Graph<QString>* graph) {
    QFile file(path);
    if(!file.open(QIODevice::Truncate|QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream out(&file);
    for(QString v: graph->GetVertex().keys()) {
        out << v;
        for(QString adj: *graph->GetVertex()[v])
            out << " " << adj;
        out << "\r\n";
    }
    file.close();

}
//template class Graph<int>;
