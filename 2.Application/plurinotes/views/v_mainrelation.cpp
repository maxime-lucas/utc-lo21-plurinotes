#include "v_mainrelation.h"
#include "ui_v_mainrelation.h"
#include <QSignalMapper>

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

    for(unsigned int i = 0; i < controller->getApp()->getRelationManager()->getTab()->size(); i ++)
    {
        Relation* r = controller->getApp()->getRelationManager()->getTab()->at(i);

        QListWidgetItem * item = new QListWidgetItem;
        item->setData(Qt::UserRole,r->getId());
        item->setText("Relation "+r->getId()+" : "+r->getTitle());

        ui->listRelation->addItem(item);
    }
    this->connect(ui->listRelation,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(refreshCouple(QListWidgetItem*)));
}

void V_MainView::refreshCouple(QListWidgetItem* id) {

    while(ui->listWidget->count()>0) ui->listWidget->takeItem(0);



    QString idRelation = id->data(Qt::UserRole).toString();
    Relation* relation = this->getController()->getApp()->getRelationByID(idRelation);

    V_Centralrelation* V_CentralRelation = new V_Centralrelation(relation,this);
    V_CentralRelation->setIsRelationView(true);
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


    refreshListCouple(id->data(Qt::UserRole).toString());

    this->connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(afficheCouple(QListWidgetItem*)));
}

void V_MainView::afficheCouple(QListWidgetItem* c) {


    QString str = c->data(Qt::UserRole).toString();

    QStringList strList = str.split(".");
    QString idRelation = strList.at(0);
    QString idCouple = strList.at(1);

    Relation* relation = this->getController()->getApp()->getRelationByID(idRelation);
    Couple* couple = this->getController()->getApp()->getCoupleByID(idCouple,relation);
    V_CentralCouple* V_Centralcouple = new V_CentralCouple(relation,couple,this);
    V_Centralcouple->setIsRelationView(false);
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


}

void V_MainView::refreshRelation()
{
    while(ui->listRelation->count()>0) ui->listRelation->takeItem(0);

    for(unsigned int i = 0; i < controller->getApp()->getRelationManager()->getTab()->size(); i ++)
    {
        Relation* r = controller->getApp()->getRelationManager()->getTab()->at(i);

        QListWidgetItem * item = new QListWidgetItem;
        item->setData(Qt::UserRole,r->getId());
        item->setText("Relation "+r->getId()+" : "+r->getTitle());

        ui->listRelation->addItem(item);
    }
}

void V_MainView::refreshListCouple(QString id)
{
    while(ui->listWidget->count()>0) ui->listWidget->takeItem(0);

    Relation* relation = this->getController()->getApp()->getRelationByID(id);

    for(unsigned int i = 0; i < relation->getCouples()->size(); i ++)
    {
        Couple* couple = relation->getCouples()->at(i);

        QListWidgetItem * item = new QListWidgetItem;
        item->setData(Qt::UserRole,relation->getId()+"."+couple->getId());
        item->setText("Couple "+couple->getId()+" : "+couple->getLabel());

        ui->listWidget->addItem(item);
    }
}


V_MainView::~V_MainView()
{
    delete ui;
}
