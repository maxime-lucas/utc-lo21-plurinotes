#include "v_centralrelation.h"
#include "ui_v_centralrelation.h"

V_CentralView::V_CentralView(QWidget *parent, V_MainRelation *m) :
    QWidget(parent),
    ui(new Ui::V_CentralRelation)
{
    parentView = m;
    ui->setupUi(this);

    //parentView->connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(deleteView()));
    //parentView->connect(ui->btnEdit, SIGNAL(clicked()), this, SLOT(editView()));
}

void V_CentralView::deleteView() {
    //parentView->getController()->deleteByID(this->ui->labelID->text());
}

void V_CentralView::editView()
{

}

V_CentralView::~V_CentralView()
{
    delete ui;
}

V_CentralRelation::V_CentralRelation(Relation *r,V_MainRelation* m) : V_CentralView(0,m) {
    this->getUi()->labelType->setText("Type : Relation");
    //this->getUi()->labelID->setText(r->getId());
    this->getUi()->textTitle->setText(r->getTitle());

    desc = new QPlainTextEdit(r->getDesc());
    text->setFixedSize(500,450);

    QFormLayout *formWidgetLayout = new QFormLayout();


    oriented = new QRadioButton("Yes");
    noriented = new QRadioButton("No");

    QHBoxLayout* btnLayout = new QHBoxLayout;

    btnLayout->addWidget(oriented);
    btnLayout->addWidget(noriented);

    formWidgetLayout->addRow(tr("Description :"),desc);
    formWidgetLayout->addRow(tr("Oriented ?"),btnLayout);

    this->getUi()->formWidget->setLayout(formWidgetLayout);

}

void V_CentralRelation::editRelation()
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

V_CentralCouple::V_CentralCouple(Couple *c,V_MainRelation* m) : V_CentralView(0,m) {
    this->getUi()->labelType->setText("Type : Couple");
    //this->getUi()->labelID->setText(r->getId());
    this->getUi()->textTitle->setText(c->getLabel());

    label = new QLineEdit;
    label->setText(c->getLabel());

    QFormLayout *formWidgetLayout = new QFormLayout();

    note1 = new QComboBox;
    note2 = new QComboBox;

    formWidgetLayout->addRow(tr("Note 1"),note1);
    formWidgetLayout->addRow(tr("Note 2"),note2);

    this->getUi()->formWidget->setLayout(formWidgetLayout);

}

void V_CentralCouple::editCouple()
{
    if(label->text().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");

     Note* a = this->getMainwindow()->getController()->getApp()->getNoteByID(note1->currentIndex());
     Note* b = this->getMainwindow()->getController()->getApp()->getNoteByID(note2->currentIndex());
     else {
        Couple* editCouple = new Couple(
                    this->getUi()->textTile->text(),
                    a,
                    b
                    );
        //this->getMainwindow()->getController()->editRelation(editRelation);
    }
}

V_CentralRelation::~V_CentralRelation(){}
V_CentralCouple::~V_CentralCouple(){}
