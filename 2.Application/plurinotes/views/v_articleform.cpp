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

        std::time_t t = time(0);
        struct std::tm* now = localtime(&t);
        Datetime dNow(
            now->tm_mday,
            now->tm_mon+1,
            now->tm_year+1900,
            now->tm_hour,
            now->tm_min,
            now->tm_sec
        );

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
