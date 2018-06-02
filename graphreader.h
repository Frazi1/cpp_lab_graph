#ifndef GRAPHREADER_H
#define GRAPHREADER_H
#include "graph.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qmessagebox.h"
#include "applicationexception.h"

class GraphReader
{
public:
    GraphReader();
    Graph<QString>* ReadGraphFromFile(QString path);
    void SaveGraphToFile(QString path, Graph<QString>* graph);
};

#endif // GRAPHREADER_H
