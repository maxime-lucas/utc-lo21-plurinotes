#include "v_relationform.h"
#include "ui_v_relationform.h"
#include <ctime>
#include <iostream>
#include <QMessageBox>

V_RelationForm::V_RelationForm(QWidget *w, V_Mainwindow *m) :
    QDialog(w),
    ui(new Ui::v_relationform)
{
    ui->setupUi(this);
    parent = m;

    ui->btnYes->setChecked(true);

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

V_RelationForm::~V_RelationForm() {
    delete ui;
}

void V_RelationForm::checkFields() {
    if(ui->lineTitle->text().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");

    else{
        bool type;

        if(ui->btnYes->isChecked())
            type = true;
        else if(ui->btnNo->isChecked())
            type = false;

        QString id = QString::number(parent->getController()->getApp()->getXMLManager()->getLastRelationId()+1);

        Relation* r = new Relation(
                    id,
                    ui->lineTitle->text(),
                    ui->textEdit->toPlainText(),
                    type
                    );
        this->parent->getController()->saveNewRelation(r);
        this->close();
    }

}
