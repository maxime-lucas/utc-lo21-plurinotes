#include "v_coupleform.h"
#include "ui_v_coupleform.h"
#include <ctime>
#include <iostream>

V_CoupleForm::V_CoupleForm(Relation *relation, QWidget *w, V_Mainwindow *c) :
    QDialog(w),
    ui(new Ui::v_coupleform),
    r(relation)
{
    ui->setupUi(this);
    parent = c;

    std::vector<Note*> *notes = parent->getController()->getApp()->getActiveNotesManager()->getTab();
   for(unsigned int i = 0; i<notes->size(); i++)
   {
       Note* note = notes->at(i);
       if( typeid(*note) == typeid(Article) ) {
       ui->note1->addItem("Article "+note->getId()+" : "+note->getTitle());
       ui->note2->addItem("Article "+note->getId()+" : "+note->getTitle());
       }
       if( typeid(*note) == typeid(Multimedia) ) {
       ui->note1->addItem("Multimedia "+note->getId()+" : "+note->getTitle());
       ui->note2->addItem("Multimedia "+note->getId()+" : "+note->getTitle());
       }
       if( typeid(*note) == typeid(Task) ) {
       ui->note1->addItem("task "+note->getId()+" : "+note->getTitle());
       ui->note2->addItem("task "+note->getId()+" : "+note->getTitle());
       }
   }

    QObject::connect(
                this->ui->btnSave,
                SIGNAL(clicked()),
                this,
                SLOT(checkFields())
    );

    QObject::connect(
                this->ui->btnCancel,
                SIGNAL(clicked()),
                this,
                SLOT(close())
    );
}

V_CoupleForm::~V_CoupleForm() {
    delete ui;
}

void V_CoupleForm::checkFields() {
    if(ui->labelline->text().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");

    else if(ui->note1->currentIndex() == ui->note2->currentIndex())
        QMessageBox::warning(this,"Error","Note 1 and Note 2 can't be the same");

    else{

        Note* a = parent->getController()->getApp()->getNoteByID(QString::number(ui->note1->currentIndex()+1));
        Note* b = parent->getController()->getApp()->getNoteByID(QString::number(ui->note2->currentIndex()+1));


        Couple* c = new Couple(
                    ui->labelline->text(),
                    a,
                    b
                    );

        this->parent->getController()->addCouple(c,r);
        this->close();
    }

}
