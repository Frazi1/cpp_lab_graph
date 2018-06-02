#ifndef LAYERSELECTORDIALOG_H
#define LAYERSELECTORDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class LayerSelectorDialog;
}

class LayerSelectorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LayerSelectorDialog(QWidget *parent = 0, QStringList* vertex = 0);
    ~LayerSelectorDialog();
    QString GetSelectedVertex();

private:
    Ui::LayerSelectorDialog *ui;
    QStringList* _vertex;
};

#endif // LAYERSELECTORDIALOG_H
