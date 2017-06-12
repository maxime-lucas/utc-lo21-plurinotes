#include "v_multiplerelation.h"
#include "ui_v_multiplerelation.h"

#include <QLabel>

V_Multiplerelation::V_Multiplerelation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::v_multiplerelation)
{
    ui->setupUi(this);
    //setFixedSize(200,170);
    setStyleSheet("#multiplerelation { background-color:#FFF }");
}

V_Multiplerelation::~V_Multiplerelation()
{
    delete ui;
}
