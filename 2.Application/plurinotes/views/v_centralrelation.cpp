#include "v_centralrelation.h"
#include "ui_v_centralrelation.h"
#include <QMessageBox>
#include <QSignalMapper>

V_CentralView::V_CentralView(QWidget *parent, V_MainView *m) :
    QWidget(parent),
    ui(new Ui::V_CentralRelation)
{
    parentView = m;
    ui->setupUi(this);

    parentView->connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(deleteView()));
    parentView->connect(ui->btnEdit, SIGNAL(clicked()), this, SLOT(editView()));
}

void V_CentralView::deleteView() {
    if(relationView == true)
    {
        QString id = this->getUi()->labelID->text();
        Relation* relation = this->getMainwindow()->getController()->getApp()->getRelationByID(id);
        this->getMainwindow()->getController()->getApp()->getRelationManager()->deleteByRelation(relation);
        this->getMainwindow()->getController()->getApp()->getXMLManager()->deleteRelation(relation);
    }
    else if(relationView == false)
    {

    }
}

void V_CentralView::editView()
{

    if(relationView == true)
    {
        V_Centralrelation* v_centralRelation = &(dynamic_cast<V_Centralrelation&>(*this));
        v_centralRelation->editRelation();
    }
    else if(relationView == false)
    {
        V_CentralCouple* v_centralcouple = &(dynamic_cast<V_CentralCouple&>(*this));
        v_centralcouple->editCouple();
    }


}

V_CentralView::~V_CentralView()
{
    delete ui;
}

V_Centralrelation::V_Centralrelation(Relation *r,V_MainView* m) : V_CentralView(0,m) {
    this->getUi()->labelType->setText("Type : Relation");
    this->getUi()->labelID->setText(r->getId());
    this->getUi()->textTitle->setText(r->getTitle());

    desc = new QPlainTextEdit(r->getDesc());
    desc->setFixedSize(400,250);

    QFormLayout *formWidgetLayout = new QFormLayout();

    if(r->getOriented() == true)
        oriented = new QLabel("Yes");
    if(r->getOriented() == false)
        oriented = new QLabel("No");

    formWidgetLayout->addRow(tr("Description :"),desc);
    formWidgetLayout->addRow(tr("Oriented ?"),oriented);

    QPushButton* addCouple = new QPushButton("AddCouple");
    this->getUi()->gridLayout->addWidget(addCouple,4,0);

    this->getUi()->formWidget->setLayout(formWidgetLayout);

    QSignalMapper* signalmapper = new QSignalMapper(this);
    this->connect(signalmapper, SIGNAL(mapped(QString)),this->getMainwindow()->getController()->getView(), SLOT(openNewCouple(QString)));
    signalmapper->setMapping(addCouple,r->getId());
    this->getMainwindow()->connect(addCouple, SIGNAL(clicked()), signalmapper, SLOT(map()));
}

void V_Centralrelation::editRelation()
{
    if(desc->toPlainText().isEmpty() || this->getUi()->textTitle->text().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");
    else {
        bool ori;

        if(oriented->text() == "Yes")
            ori = true;
        if(oriented->text() == "No")
            ori = false;


        QString id = QString::number(this->getMainwindow()->getController()->getApp()->getRelationManager()->getCurrentId()+1);

        this->getMainwindow()->getController()->getApp()->getRelationManager()->incCurrentId();
        Relation* editRelation = new Relation(
                    id,
                    this->getUi()->textTitle->text(),
                    desc->toPlainText(),
                    ori
                    );
       this->getMainwindow()->getController()->editRelation(editRelation);
    }
}

V_CentralCouple::V_CentralCouple(Relation *r, Couple *c,V_MainView* m) : V_CentralView(0,m), r(r), c(c){
    this->getUi()->labelType->setText("Type : Couple");
    this->getUi()->labelID->setText(c->getId());
    this->getUi()->textTitle->setText(c->getLabel());

    label = new QLineEdit;
    label->setText(c->getLabel());

    QFormLayout *formWidgetLayout = new QFormLayout();



        Note* note = c->getX();
        if( typeid(*note) == typeid(Article) ) {
        note1 = new QLabel("Article "+note->getId()+" : "+note->getTitle());
        }
        if( typeid(*note) == typeid(Multimedia) ) {
        note1 = new QLabel("Multimedia "+note->getId()+" : "+note->getTitle());
        }
        if( typeid(*note) == typeid(Task) ) {
        note1 = new QLabel("task "+note->getId()+" : "+note->getTitle());
        }

        Note* n= c->getY();
        if( typeid(*n) == typeid(Article) ) {
        note2 = new QLabel("Article "+n->getId()+" : "+n->getTitle());
        }
        if( typeid(*n) == typeid(Multimedia) ) {
        note2 = new QLabel("Multimedia "+n->getId()+" : "+n->getTitle());
        }
        if( typeid(*n) == typeid(Task) ) {
        note2 = new QLabel("task "+n->getId()+" : "+n->getTitle());
        }


    formWidgetLayout->addRow(tr("Note 1"),note1);
    formWidgetLayout->addRow(tr("Note 2"),note2);

    this->getUi()->formWidget->setLayout(formWidgetLayout);

}

void V_CentralCouple::editCouple()
{
    if(label->text().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");
    else {
     //Currentindex() renvoie 0 a partir du permier rang

        Couple* editCouple = new Couple(
            this->getUi()->textTitle->text(),
            c->getX(),
            c->getY()
            );

        this->getMainwindow()->getController()->editCouple(editCouple,r->getId());
    }
}

V_Centralrelation::~V_Centralrelation(){}
V_CentralCouple::~V_CentralCouple(){}
