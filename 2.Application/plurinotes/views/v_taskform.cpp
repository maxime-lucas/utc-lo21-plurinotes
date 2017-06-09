#include "v_taskform.h"
#include "ui_v_taskform.h"
#include <ctime>
#include <iostream>

V_TaskForm::V_TaskForm(QWidget *w, V_Mainwindow *m) :
    QDialog(w),
    ui(new Ui::V_TaskForm)
{
    ui->setupUi(this);
    parent = m;

    unsigned int lastId = parent->getController()->getApp()->getXMLManager()->getLastId();
    ui->iDLineEdit->setText(QString::number(lastId+1));

    QObject::connect(ui->prioritySlider, SIGNAL(valueChanged(int)), ui->priorityBox, SLOT(display(int))) ;

    QObject::connect(
                this->ui->btnSave,
                SIGNAL(clicked()),
                this,
                SLOT(checkFields())
                );
    QObject::connect(this->ui->btnCancel,
                SIGNAL(clicked()),
                this,
                SLOT(close())
                );
}

V_TaskForm::~V_TaskForm()
{
    delete ui;
}

void V_TaskForm::checkFeilds()
{
    if(ui->titleLineEdit->text().isEmpty() ||
       ui->actionLineEdit->text().isEmpty() ||
       (!(ui->yesBtn->isChecked()) && !(ui->noBtn->isChecked())))
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");

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
    QDateTime ToBeDone;

    if(ui->yesBtn->isChecked())
         {
            ToBeDone = ui->toBeDoneOnDateTimeEdit->text();
           }



    Task *ta = new Task(
                ui->iDLineEdit->text(),
                ui->titleLineEdit->text(),
                dNow,
                dNow,
                ui->actionLineEdit->text(),
                ui->priorityBox->text(),
                ToBeDone,
                PENDING);

    //this->parent->getController()->saveNewTask(ta);
    this->close;

}
