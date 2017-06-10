#include "v_multimediaform.h"
#include "ui_v_multimediaform.h"
#include <ctime>
#include <iostream>
V_MultimediaForm::V_MultimediaForm(QWidget *w, V_Mainwindow *m) :
    QDialog(w),
    ui(new Ui::V_MultimediaForm)
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
    QObject::connect(this->ui->btnCancel,
                SIGNAL(clicked()),
                this,
                SLOT(close())
                );
    QObject::connect(this->ui->btnOpen,
                SIGNAL(clicked()),
                this,
                SLOT(openFile())
                );
    ui->audioBtn->setChecked(true);
}

V_MultimediaForm::~V_MultimediaForm()
{
    delete ui;
}

void V_MultimediaForm::openFile()
{
    QString extensionFilter;
    if(ui->videoBtn->isChecked())
        extensionFilter = tr("Video (*.mp4)");
    else if(ui->imageBtn->isChecked())
        extensionFilter = tr("JPEG (*.jpg *.jpeg);;PNG (*.png)");
    else if(ui->audioBtn->isChecked())
        extensionFilter = tr("Audio (*.mp3)");

    QString files = QFileDialog::getOpenFileName(this,
                                                 tr("Open MultiMedia File"),
                                                 "",
                                                 extensionFilter,
                                                 &extensionFilter);

    ui->fileLineEdit->setText(files);
}


void V_MultimediaForm::checkFields() {
    if(ui->textTitle->toPlainText().isEmpty() ||
        (!(ui->videoBtn->isChecked()) && !(ui->imageBtn->isChecked()) && !(ui->audioBtn->isChecked())) ||
        (ui->fileLineEdit->text().isEmpty()))
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
        TypeMultimedia type;
        if(ui->videoBtn->isChecked())
            type = VIDEO;
        else if(ui->imageBtn->isChecked())
            type = PICTURE;
        else if(ui->audioBtn->isChecked())
            type = AUDIO;


        Multimedia *m = new Multimedia(
                    ui->textID->toPlainText(),
                    ui->textTitle->toPlainText(),
                    dNow,
                    dNow,
                    ui->textDesc->toPlainText(),
                    ui->fileLineEdit->text(),
                    type);

        this->parent->getController()->saveNewMultimedia(m);
        this->close();
    }
}
