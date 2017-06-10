#include "v_articleform.h"
#include "ui_v_articleform.h"
#include <ctime>
#include <iostream>

V_ArticleForm::V_ArticleForm(QWidget *w, V_Mainwindow *m) :
    QDialog(w),
    ui(new Ui::V_ArticleForm)
{
    ui->setupUi(this);
    parent = m;

    unsigned int lastID = parent->getController()->getApp()->getXMLManager()->getLastId();
    ui->textID->setPlainText(QString::number(lastID+1));

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

V_ArticleForm::~V_ArticleForm()
{
    delete ui;
}

void V_ArticleForm::checkFields() {


    if( ui->textTitle->toPlainText().isEmpty() || ui->textText->toPlainText().isEmpty() )
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");
    else {

        QDateTime dNow = QDateTime::currentDateTime();

        Article *a = new Article(
            ui->textID->toPlainText(),
            ui->textTitle->toPlainText(),
            dNow,
            dNow,
            ui->textText->toPlainText()
        );

        this->parent->getController()->saveNewArticle(a);
        this->close();
    }
}
