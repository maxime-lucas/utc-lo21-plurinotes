#include "views/v_article.h"
#include <QMessageBox>

v_article::v_article(Article &article, QWidget *parent)
{
    id1 = new QLabel("Id",this);
    titre1 = new QLabel("Titre",this);
    text1 = new QLabel("Text",this);

    id = new QLineEdit(this);
    titre = new QLineEdit(this);

    text = new QTextEdit(this);

    save = new QPushButton("Save",this);

    layout = new QGridLayout(this);
    layout->addWidget(id1,0,0);
    layout->addWidget(id,0,1);
    layout->addWidget(text1,2,0);
    layout->addWidget(titre,1,1);
    layout->addWidget(titre1,1,0);
    layout->addWidget(text,2,1);
    layout->addWidget(save,3,0,1,2);

    id->setReadOnly(true);

    id->setText(article.getId());
    titre->setText(article.getTitle());
    text->setText(article.getText());

    this->article = &article;
    save->setEnabled(false);
    QObject::connect(save,SIGNAL(clicked(bool)),this,SLOT(saveArticle()));
    QObject::connect(titre,SIGNAL(textChanged(QString)),this,SLOT(enableSave()));
    QObject::connect(text,SIGNAL(textChanged()),this,SLOT(enableSave()));
}

void v_article::saveArticle()
{
    article->setTitle(titre->text());
    article->setText(text->toPlainText());
    //NotesManager::getManager().save();
    QMessageBox::information(this, "Sauvegarde", "Votre article a été sauvergarder");
    save->setEnabled(false);
}

void v_article::enabledSave()
{
    save->setEnabled(true);
}

