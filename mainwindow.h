#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "graphreader.h"
#include "qfiledialog.h"
#include "graphsubwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void OnFileOpenClick();
    void OnLayersClick();

private:
    Ui::MainWindow *ui;
    void CreateGraphSubWindow(Graph<int>* g, QString name);
};

#endif // MAINWINDOW_H
