#ifndef GRAPHREADER_H
#define GRAPHREADER_H
#include "graph.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qmessagebox.h"

class GraphReader
{
public:
    GraphReader();
    Graph* ReadGraphFromFile(QString path);
};

#endif // GRAPHREADER_H
