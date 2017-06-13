#include "v_mainrelation.h"
#include "ui_v_mainrelation.h"

V_MainView::V_MainView(QWidget *parent, C_Mainwindow* c) :
    QWidget(parent),
    ui(new Ui::v_mainrelation)
{
    ui->setupUi(this);
    controller = c;

    move(0,0);
    setStyleSheet("V_mainrelation { background-color:#FFF;}");

    centralView = new QWidget;
    QVBoxLayout *centralViewLayout = new QVBoxLayout;
    QLabel *beginningTitle = new QLabel("Select a relation in the left tab");
    beginningTitle->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    centralViewLayout->addWidget(beginningTitle);
    centralView->setFixedWidth(560);
    centralView->setLayout(centralViewLayout);

    centralRLayout = new QHBoxLayout;
    //centralView->setFixedWidth(580);
    centralRLayout->addWidget(centralView);
    ui->formWidget->setLayout(centralRLayout);

    QStringListModel* relationModel = new QStringListModel(this);

    //controller->getApp()->
    relations.push_back("Test");

    relationModel->setStringList(relations);

    ui->listeRelation->setModel(relationModel);

    ui->listeRelation->connect(ui->listeRelation,SIGNAL(clicked(QModelIndex)),this,SLOT(refreshCouple()));
}

void V_MainView::refreshCouple() {

    Relation* relation = new Relation("Test","Relation Test",true);
    V_Centralrelation* V_CentralRelation = new V_Centralrelation(relation,this);
    centralView = V_CentralRelation;

    QLayoutItem* item = centralRLayout->takeAt(0);
    while ( item != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }
    delete centralRLayout;
    centralRLayout = new QHBoxLayout;
    centralView->setFixedWidth(580);
    centralRLayout->addWidget(centralView);
    ui->formWidget->setLayout(centralRLayout);

    QStringListModel* coupleModel = new QStringListModel(this);

    couples.push_back("TestCouple");

    coupleModel->setStringList(couples);

    ui->listCouple->setModel(coupleModel);

    ui->listCouple->connect(ui->listCouple,SIGNAL(clicked(QModelIndex)),this,SLOT(afficheCouple()));

}

void V_MainView::afficheCouple() {
    Note* a = this->getController()->getApp()->getNoteByID("1");
    Note* b = this->getController()->getApp()->getNoteByID("2");

    Couple* couple = new Couple("TestCouple",a,b);
    V_CentralCouple* V_Centralcouple = new V_CentralCouple(couple,this);
    centralView = V_Centralcouple;

    QLayoutItem* item = centralRLayout->takeAt(0);
    while ( item != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    delete centralRLayout;
    centralRLayout = new QHBoxLayout;
    centralView->setFixedWidth(580);
    centralRLayout->addWidget(centralView);
    ui->formWidget->setLayout(centralRLayout);

    QStringListModel* coupleModel = new QStringListModel(this);

    coupleModel->setStringList(empty);

    ui->listCouple->setModel(coupleModel);

}




V_MainView::~V_MainView()
{
    delete ui;
}
