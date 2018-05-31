#include "graphreader.h"

GraphReader::GraphReader()
{

}

Graph* GraphReader::ReadGraphFromFile(QString path){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    Graph* g = new Graph;
    while(!in.atEnd()) {
        QString vertexLine = in.readLine();
        if(!vertexLine.isEmpty()){
            int vertex = vertexLine.toInt();
            g->GetVertex().insert(vertex, new vector<int>());
            if(!in.atEnd()){
                QStringList adjacentLines = in.readLine().split(" ");
                for(QString& al: adjacentLines) {
                    g->GetVertex()[vertex]->push_back(al.toInt());
                }
            }
        }
    }

    file.close();
    return g;
}
