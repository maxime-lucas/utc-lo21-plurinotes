#include "v_mainrelation.h"
#include "ui_v_mainrelation.h"

V_MainRelation::V_MainRelation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::v_mainrelation)
{
    ui->setupUi(this);
}

V_MainRelation::~V_MainRelation()
{
    delete ui;
}
