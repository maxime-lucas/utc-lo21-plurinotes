#include "v_centralnote.h"
#include "ui_v_centralnote.h"
#include <QPlainTextEdit>

V_CentralNote::V_CentralNote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::V_CentralNote)
{
    ui->setupUi(this);
}

V_CentralNote::~V_CentralNote()
{
    delete ui;
}

V_CentralArticle::V_CentralArticle(Article *a) {
    this->getUi()->labelType->setText("Type : Article");
    this->getUi()->labelID->setText("ID : " + a->getId());
    this->getUi()->textTitle->setText(a->getTitle());
    this->getUi()->labelCreatedOn->setText(a->getCreatedOn().toString());
    this->getUi()->labelLastModifOn->setText(a->getLastModifOn().toString());

    QPlainTextEdit *textText = new QPlainTextEdit(a->getText());
    QVBoxLayout *formWidgetLayout = new QVBoxLayout();
    formWidgetLayout->addWidget(textText);
    this->getUi()->formWidget->setLayout(formWidgetLayout);
}

V_CentralMultimedia::V_CentralMultimedia(Multimedia *m) {
    this->getUi()->labelType->setText("Type : Multimedia");
    this->getUi()->labelID->setText("ID : " + m->getId());
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

V_CentralArticle::~V_CentralArticle(){}
V_CentralMultimedia::~V_CentralMultimedia(){}
