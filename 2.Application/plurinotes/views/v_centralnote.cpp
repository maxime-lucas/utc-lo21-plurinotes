#include "v_centralnote.h"
#include "ui_v_centralnote.h"

V_CentralNote::V_CentralNote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::V_CentralNote)
{
    ui->setupUi(this);
}

V_CentralNote::~V_CentralNote()
{
    delete ui;
}
