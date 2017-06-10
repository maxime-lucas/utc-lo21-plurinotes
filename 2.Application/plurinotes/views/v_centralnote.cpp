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
    this->getUi()->labelType->setText("Article");
    this->getUi()->labelID->setText("ID : " + a->getId());
    this->getUi()->labelTitle->setText(a->getTitle());
    this->getUi()->labelCreatedOn->setText(a->getCreatedOn().toString());
    this->getUi()->labelLastModifOn->setText(a->getLastModifOn().toString());

    QPlainTextEdit *textText = new QPlainTextEdit(a->getText());
    QVBoxLayout *formWidgetLayout = new QVBoxLayout();
    formWidgetLayout->addWidget(textText);
    this->getUi()->formWidget->setLayout(formWidgetLayout);
}

V_CentralArticle::~V_CentralArticle(){}
