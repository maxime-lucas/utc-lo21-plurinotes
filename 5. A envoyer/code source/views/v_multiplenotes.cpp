#include "v_multiplenotes.h"
#include "ui_v_multiplenotes.h"
#include <QPushButton>
#include <QLabel>

V_Multiplenotes::V_Multiplenotes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::v_multiplenotes)
{
    ui->setupUi(this);
    setFixedSize(200,170);
    setStyleSheet("#multipleNotes { background-color:#FFF }");

    container = new QWidget;
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(container);
    gridLayout = new QGridLayout;
    container->setLayout(gridLayout);
    container->setObjectName("multipleNotes");
    container->setStyleSheet("#multipleNotes { background-color:#FCFCFC }");
}

V_Multiplenotes::~V_Multiplenotes()
{
    delete ui;
}
