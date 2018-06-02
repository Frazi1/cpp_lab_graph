#include "graphreader.h"

GraphReader::GraphReader()
{

}

Graph<QString>* GraphReader::ReadGraphFromFile(QString path){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    Graph<QString>* g = new Graph<QString>;
    while(!in.atEnd()) {
//        QString vertexLine = in.readLine();
        QStringList lineVertex = in.readLine().split(" ");
        lineVertex.removeAll("");
        if(!lineVertex.isEmpty()) {
            g->GetVertex().insert(lineVertex[0], new vector<QString>);
            for(QString& v: lineVertex) {
                if(v != lineVertex[0])
                    g->GetVertex()[lineVertex[0]]->push_back(v);
            }
        }
//        if(!vertexLine.isEmpty()){
//            int vertex = vertexLine.toInt();
//            g->GetVertex().insert(vertex, new vector<int>());
//            if(!in.atEnd()){
//                QStringList adjacentLines = in.readLine().split(" ");
//                adjacentLines.removeAll("");
//                for(QString& al: adjacentLines) {
//                    g->GetVertex()[vertex]->push_back(al.toInt());
//                }
//            }
//        }
    }

    file.close();
    return g;
}

//template class Graph<int>;
