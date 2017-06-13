#include "v_multiplerelation.h"
#include "ui_v_multiplerelation.h"

#include <QLabel>

V_Multiplerelation::V_Multiplerelation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::v_multiplerelation)
{
    ui->setupUi(this);
    ui->labelAscendants->setFixedSize(200,20);
    ui->labelDescendants->setFixedSize(200,20);
    ui->treeAscendant->setFixedWidth(200);
    ui->treeDescendant->setFixedWidth(200);
    setStyleSheet("#multiplerelation { background-color:#FFF }");
}

V_Multiplerelation::~V_Multiplerelation()
{
    delete ui;
}
