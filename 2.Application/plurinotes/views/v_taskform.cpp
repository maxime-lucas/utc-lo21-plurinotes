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

    QObject::connect(ui->prioritySlider, SIGNAL(valueChanged(int)), ui->lcdNumber, SLOT(display(int))) ;

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

void V_TaskForm::checkFields() {
    if(ui->titleLineEdit->text().isEmpty() ||
       ui->actionLineEdit->text().isEmpty() ||
       (!(ui->yesBtn->isChecked()) && !(ui->noBtn->isChecked())))
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");
else{
    QDateTime dNow = QDateTime::currentDateTime();

    QDateTime ToBeDone;

    if(ui->yesBtn->isChecked())
         {
            ToBeDone = ui->toBeDoneOnDateTimeEdit->dateTime();
           }


    unsigned int test = ui->lcdNumber->value();


    Task *ta = new Task(
                ui->iDLineEdit->text(),
                ui->titleLineEdit->text(),
                dNow,
                dNow,
                ui->actionLineEdit->text(),
                test,
                ToBeDone,
                PENDING);

    this->parent->getController()->saveNewTask(ta);

    this->close();
}
}
