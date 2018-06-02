#include "layerselectordialog.h"
#include "ui_layerselectordialog.h"

LayerSelectorDialog::LayerSelectorDialog(QWidget *parent, QStringList* vertex) :
    QDialog(parent),
    ui(new Ui::LayerSelectorDialog),
    _vertex(vertex)
{
    ui->setupUi(this);
    ui->comboBox->addItems(*vertex);
}

LayerSelectorDialog::~LayerSelectorDialog()
{
    delete ui;
}

QString LayerSelectorDialog::GetSelectedVertex() {
    return ui->comboBox->currentText();
}
