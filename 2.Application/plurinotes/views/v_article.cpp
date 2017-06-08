#include "views/v_article.h"

#include <QMessageBox>

v_article::v_article()
{
    //setFixedSize(300, 150);


    id = new QLineEdit(this);
    titre = new QLineEdit(this);

    text = new QTextEdit(this);


    layout = new QFormLayout(this);
    layout->addRow("id", id);
    layout->addRow("Titre", titre);
    layout->addRow("Text", text);

    setLayout(layout);
    Vlayout = new QVBoxLayout(this);
    Vlayout->addLayout(layout);

    save = new QPushButton("Save", this);

    id->setReadOnly(true);

    //id->setText(article.getId());
    //titre->setText(article.getTitle());
    //text->setText(article.getText());

    //this->article = &article;
    //save->setEnabled(false);
    QObject::connect(save,SIGNAL(clicked(bool)),this,SLOT(saveArticle()));
    //QObject::connect(titre,SIGNAL(textChanged(QString)),this,SLOT(enableSave()));
    //QObject::connect(text,SIGNAL(textChanged()),this,SLOT(enableSave()));
    Vlayout->addWidget(save);
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

