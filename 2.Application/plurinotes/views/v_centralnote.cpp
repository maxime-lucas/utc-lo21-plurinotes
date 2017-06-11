#include "v_centralnote.h"
#include "ui_v_centralnote.h"
#include <QFileDialog>

V_CentralNote::V_CentralNote(QWidget *parent,V_Mainwindow* m) :
    QWidget(parent),
    ui(new Ui::V_CentralNote)
{
    parentView = m;
    ui->setupUi(this);

    QSignalMapper* signalMapper = new QSignalMapper(this);
    parentView->connect(signalMapper, SIGNAL(mapped(QString)),this,SLOT(deleteNote()));
    signalMapper->setMapping(ui->btnDelete, ui->labelID->text());
    parentView->connect(ui->btnDelete, SIGNAL(clicked()), signalMapper, SLOT(map()));

}

void V_CentralNote::deleteNote() {
    parentView->getController()->deleteByID(this->ui->labelID->text());
}

V_CentralNote::~V_CentralNote()
{
    delete ui;
}

V_CentralArticle::V_CentralArticle(Article *a,V_Mainwindow* m) : V_CentralNote(0,m) {
    this->getUi()->labelType->setText("Type : Article");
    this->getUi()->labelID->setText(a->getId());
    this->getUi()->textTitle->setText(a->getTitle());
    this->getUi()->labelCreatedOn->setText(a->getCreatedOn().toString());
    this->getUi()->labelLastModifOn->setText(a->getLastModifOn().toString());

    text = new QPlainTextEdit(a->getText());
    QVBoxLayout *formWidgetLayout = new QVBoxLayout();
    formWidgetLayout->addWidget(text);
    this->getUi()->formWidget->setLayout(formWidgetLayout);


    QSignalMapper* signalMapper = new QSignalMapper(this);
    this->connect(signalMapper, SIGNAL(mapped(QString)),this,SLOT(editArticle()));
    signalMapper->setMapping(this->getUi()->btnEdit, text->toPlainText());
    this->connect(this->getUi()->btnEdit, SIGNAL(clicked()), signalMapper, SLOT(map()));
}

void V_CentralArticle::editArticle()
{
    if(text->toPlainText().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");

    QDateTime dNow = QDateTime::currentDateTime();
    QDateTime dCreated = QDateTime::fromString(this->getUi()->labelCreatedOn->text());

    Article *a = new Article(
        this->getUi()->labelID->text(),
        this->getUi()->textTitle->text(),
        dCreated,
        dNow,
        text->toPlainText()
    );

    this->getMainwindow()->getController()->saveNewArticle(a);
    this->getMainwindow()->refreshCentralNote(this->getUi()->labelID->text());
    this->getMainwindow()->getController()->refreshActiveNotes();
}


V_CentralMultimedia::V_CentralMultimedia(Multimedia *m, V_Mainwindow*mw) : V_CentralNote(0,mw){
    this->getUi()->labelType->setText("Type : Multimedia/"+m->getTypeToQString());
    this->getUi()->labelID->setText(m->getId());
    this->getUi()->textTitle->setText(m->getTitle());
    this->getUi()->labelCreatedOn->setText(m->getCreatedOn().toString());
    this->getUi()->labelLastModifOn->setText(m->getLastModifOn().toString());

    QPlainTextEdit *textDescription = new QPlainTextEdit(m->getDescription());
    textDescription->setFixedHeight(100);
    QVBoxLayout *formWidgetLayout = new QVBoxLayout();
    formWidgetLayout->addWidget(textDescription);

    if( m->getType() == PICTURE ) {
        QFile *file = new QFile(m->getFileName());
        QFileInfo fileInfo(file->fileName());
        QDir dirToRessources(QDir::currentPath());
        dirToRessources.cd("../plurinotes/ressources/");
        QString path(dirToRessources.absolutePath()+ QDir::separator() + m->getId() + "." + fileInfo.completeSuffix());
        QLabel *img = new QLabel(this);
        img->setPixmap(QPixmap(path));
        img->setAlignment(Qt::AlignCenter);
        formWidgetLayout->addWidget(img);
    }

    this->getUi()->formWidget->setLayout(formWidgetLayout);

    /*QSignalMapper* signalMapper = new QSignalMapper(this);
    this->connect(signalMapper, SIGNAL(mapped(QString)),this,SLOT(editMultimedia()));
    signalMapper->setMapping(this->getUi()->btnEdit, desc->toPlainText());*/
    this->connect(this->getUi()->btnEdit, SIGNAL(clicked()), this, SLOT(editMultimedia(m)));
}

void V_CentralMultimedia::editMultimedia(Multimedia *m)
{
    if(desc->toPlainText().isEmpty())
        QMessageBox::warning(this,"Missing field","The fields cannot be empty.");

    QDateTime dNow = QDateTime::currentDateTime();
    QDateTime dCreated = QDateTime::fromString(this->getUi()->labelCreatedOn->text());

    Multimedia *m2 = new Multimedia(
        m->getId(),
        this->getUi()->textTitle->text(),
        dCreated,
        dNow,
        desc->toPlainText(),
        m->getFileName(),
        m->getType()
    );

    this->getMainwindow()->getController()->saveNewMultimedia(m);
    this->getMainwindow()->refreshCentralNote(this->getUi()->labelID->text());
    this->getMainwindow()->getController()->refreshActiveNotes();
}


V_CentralTask::V_CentralTask(Task *t, V_Mainwindow*m) : V_CentralNote(0,m){
    this->getUi()->labelType->setText("Type : Task/"+t->getStatusToString());
    this->getUi()->labelID->setText(t->getId());
    this->getUi()->textTitle->setText(t->getTitle());
    this->getUi()->labelCreatedOn->setText(t->getCreatedOn().toString());
    this->getUi()->labelLastModifOn->setText(t->getLastModifOn().toString());

}

V_CentralArticle::~V_CentralArticle(){}
V_CentralMultimedia::~V_CentralMultimedia(){}
V_CentralTask::~V_CentralTask(){}
