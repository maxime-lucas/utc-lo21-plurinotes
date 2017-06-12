#include "v_centralnote.h"
#include "ui_v_centralnote.h"
#include <QPlainTextEdit>
#include <QFileDialog>

V_CentralNote::V_CentralNote(QWidget *parent,V_Mainwindow* m) :
    QWidget(parent),
    ui(new Ui::V_CentralNote)
{
    parentView = m;
    ui->setupUi(this);
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

    QPlainTextEdit *textText = new QPlainTextEdit(a->getText());
    QVBoxLayout *formWidgetLayout = new QVBoxLayout();
    formWidgetLayout->addWidget(textText);
    this->getUi()->formWidget->setLayout(formWidgetLayout);
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
