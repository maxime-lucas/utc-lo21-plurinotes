#include "v_centralrelation.h"
#include "ui_v_centralrelation.h"
#include <QMessageBox>

V_CentralView::V_CentralView(QWidget *parent, V_MainView *m) :
    QWidget(parent),
    ui(new Ui::V_CentralRelation)
{
    parentView = m;
    ui->setupUi(this);

    //parentView->connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(deleteView()));
    parentView->connect(ui->btnEdit, SIGNAL(clicked()), this, SLOT(editView()));
}

void V_CentralView::deleteView() {
    //parentView->getController()->deleteByID(this->ui->labelID->text());
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
    //this->getUi()->labelID->setText(r->getId());
    this->getUi()->textTitle->setText(r->getTitle());

    desc = new QPlainTextEdit(r->getDesc());
    desc->setFixedSize(400,250);

    QFormLayout *formWidgetLayout = new QFormLayout();


    oriented = new QRadioButton("Yes");
    noriented = new QRadioButton("No");

    if(r->getOriented() == true)
        oriented->setChecked(true);
    else if(r->getOriented() == false)
        noriented->setChecked(true);

    QHBoxLayout* btnLayout = new QHBoxLayout;

    btnLayout->addWidget(oriented);
    btnLayout->addWidget(noriented);

    formWidgetLayout->addRow(tr("Description :"),desc);
    formWidgetLayout->addRow(tr("Oriented ?"),btnLayout);

    QPushButton* addCouple = new QPushButton("AddCouple");
    this->getUi()->gridLayout->addWidget(addCouple,4,0);

    this->getUi()->formWidget->setLayout(formWidgetLayout);

    this->getMainwindow()->connect(addCouple,SIGNAL(clicked(bool)), this->getMainwindow()->getController()->getView(),SLOT(openNewCouple()));

}

void V_Centralrelation::editRelation()
{
    if(desc->toPlainText().isEmpty() || this->getUi()->textTitle->text().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");
    else {
        bool ori;

        if(oriented->isChecked())
            ori = true;
        else if(noriented->isChecked())
            ori = false;


        Relation* editRelation = new Relation(
                    this->getUi()->textTitle->text(),
                    desc->toPlainText(),
                    ori
                    );
        //this->getMainwindow()->getController()->editRelation(editRelation);
    }
}

V_CentralCouple::V_CentralCouple(Couple *c,V_MainView* m) : V_CentralView(0,m) {
    this->getUi()->labelType->setText("Type : Couple");
    //this->getUi()->labelID->setText(r->getId());
    this->getUi()->textTitle->setText(c->getLabel());

    label = new QLineEdit;
    label->setText(c->getLabel());

    QFormLayout *formWidgetLayout = new QFormLayout();

    note1 = new QComboBox;
    note2 = new QComboBox;

     std::vector<Note*> *notes = this->getMainwindow()->getController()->getApp()->getActiveNotesManager()->getTab();
    for(unsigned int i = 0; i<notes->size(); i++)
    {
        Note* note = notes->at(i);
        if( typeid(*note) == typeid(Article) ) {
        note1->addItem("Article "+note->getId()+" : "+note->getTitle());
        note2->addItem("Article "+note->getId()+" : "+note->getTitle());
        }
        if( typeid(*note) == typeid(Multimedia) ) {
        note1->addItem("Multimedia "+note->getId()+" : "+note->getTitle());
        note2->addItem("Multimedia "+note->getId()+" : "+note->getTitle());
        }
        if( typeid(*note) == typeid(Task) ) {
        note1->addItem("task "+note->getId()+" : "+note->getTitle());
        note2->addItem("task "+note->getId()+" : "+note->getTitle());
        }
    }


    // initialisation des combo box$
    bool ok = true;
    int xId = c->getX()->getId().toInt(&ok,10);
    int yId = c->getY()->getId().toInt(&ok,10);
    note1->setCurrentIndex(xId - 1);
    note2->setCurrentIndex(yId - 1);

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

     Note* a = this->getMainwindow()->getController()->getApp()->getNoteByID(QString::number(note1->currentIndex()+1));
     Note* b = this->getMainwindow()->getController()->getApp()->getNoteByID(QString::number(note2->currentIndex()+1));

        Couple* editCouple = new Couple(
                    this->getUi()->textTitle->text(),
                    a,
                    b
                    );

        //this->getMainwindow()->getController()->editRelation(editRelation);
    }
}

V_Centralrelation::~V_Centralrelation(){}
V_CentralCouple::~V_CentralCouple(){}
