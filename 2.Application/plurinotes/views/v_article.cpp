#include "views/v_article.h"

#include <QMessageBox>

v_article::v_article(Article &article, QWidget *parent)
{

    id = new QLineEdit(this);
    titre = new QLineEdit(this);

    text = new QTextEdit(this);

    id->setReadOnly(true);

    Vlayout = new QVBoxLayout(this);
    layout = new QFormLayout(this);

    layout->addRow("id", id);
    layout->addRow("Titre", titre);
    layout->addRow("Text", text);

    Vlayout->addLayout(layout);

    save = new QPushButton("Save", this);
    Vlayout->addWidget(save);


    id->setText(article.getId());
    titre->setText(article.getTitle());
    text->setText(article.getText());

    QObject::connect(save,SIGNAL(clicked(bool)),this,SLOT(saveArticle()));

    setLayout(Vlayout);
}

void v_article::saveArticle()
{
    article->setTitle(titre->text());
    article->setText(text->toPlainText());
    //NotesManager::getManager().save();
    QMessageBox::information(this, "Sauvegarde", "Votre article a été sauvergarder");
    save->setEnabled(false);
}


