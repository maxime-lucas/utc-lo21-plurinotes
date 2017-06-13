#include "v_mainrelation.h"
#include "ui_v_mainrelation.h"

V_MainRelation::V_MainRelation(QWidget *parent, C_Mainwindow* c) :
    QWidget(parent),
    ui(new Ui::v_mainrelation)
{
    ui->setupUi(this);
    controller = c;

    QStringListModel* relationModel = new QStringListModel(this);

    //controller->getApp()->

    relationModel->setStringList(relations);

    ui->listeRelation->setModel(relationModel);

    ui->listeRelation->connect(ui->listeRelation,SIGNAL(clicked(QModelIndex)),this,SLOT(refreshCouple()));
}

void V_MainRelation::refreshCouple() {
    QMessageBox::warning(this,"Coucouuu","Refreeeesh");
}

V_MainRelation::~V_MainRelation()
{
    delete ui;
}
