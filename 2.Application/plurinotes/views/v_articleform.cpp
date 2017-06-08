#include "v_articleform.h"
#include "ui_v_articleform.h"

V_ArticleForm::V_ArticleForm(QWidget *w, V_Mainwindow *m) :
    QDialog(w),
    ui(new Ui::V_ArticleForm)
{
    ui->setupUi(this);
    parent = m;

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

}
