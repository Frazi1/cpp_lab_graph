#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QList>
#include "graphreader.h"
#include "qfiledialog.h"
#include "graphsubwindow.h"
#include "layerselectordialog.h"
#include "applicationexception.h"
#include "errorhandler.h"

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
    void OnFileSaveClick();
    void OnLayersClick();

private:
    Ui::MainWindow *ui;
    void CreateGraphSubWindow(Graph<QString>* g, QString name);
};

#endif // MAINWINDOW_H
