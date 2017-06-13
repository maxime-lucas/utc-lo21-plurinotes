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
    relations.push_back("Test");
    relations.push_back("Test2");

    relationModel->setStringList(relations);

    ui->listeRelation->setModel(relationModel);

    ui->listeRelation->connect(ui->listeRelation,SIGNAL(clicked(QModelIndex)),this,SLOT(refreshCouple()));
}

void V_MainRelation::refreshCouple() {
    //couples.clear();

    QFormLayout* formLayout = new QFormLayout;
    QTextEdit* label = new QTextEdit();
    label->setText("C'est la relation de votre vie");
    label->setFixedSize(200,100);

    QRadioButton* oriented = new QRadioButton("Yes");
    QRadioButton* noriented = new QRadioButton("No");

    QHBoxLayout* btnLayout = new QHBoxLayout;

    btnLayout->addWidget(oriented);
    btnLayout->addWidget(noriented);

    this->getUi()->labelType->setText("Type : Relation");
    //this->getUi()->labelID->setText(r->getId());
    //this->getUi()->textTitle->setText(r->getLabel());
    ui->textTitle->setText("Relation");

    formLayout->addRow(tr("Description"),label);
    formLayout->addRow(tr("Oriented ?"),btnLayout);

    ui->contentView->setLayout(formLayout);

    QStringListModel* coupleModel = new QStringListModel(this);

    couples.push_back("Hey");

    coupleModel->setStringList(couples);

    ui->listCouple->setModel(coupleModel);

    ui->listCouple->connect(ui->listCouple,SIGNAL(clicked(QModelIndex)),this,SLOT(afficheCouple()));

}

void V_MainRelation::afficheCouple() {

    //controller->app->getCoupleById()
    this->getUi()->labelType->setText("Type : Couple/");
    //this->getUi()->labelID->setText(c->getId());
    //this->getUi()->textTitle->setText(c->getLabel());

    QFormLayout* formLayout = new QFormLayout;
    QLineEdit* label = new QLineEdit();
    label->setText("C'est le label de votre vie");

    ui->textTitle->setText("Mais oui c'est clair");

    formLayout->addRow(tr("Label"),label);
    formLayout->addRow(tr("Note1"),label);
    formLayout->addRow(tr("Note2"),label);

    ui->contentView->setLayout(formLayout);

    QStringListModel* coupleModel = new QStringListModel(this);

    coupleModel->setStringList(empty);

    ui->listCouple->setModel(coupleModel);

}




V_MainRelation::~V_MainRelation()
{
    delete ui;
}
