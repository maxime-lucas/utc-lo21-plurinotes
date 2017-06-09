#include "views/v_multimedia.h"

#include <QMessageBox>

v_multimedia::v_multimedia(Multimedia &multimedia, QWidget *parent)
{

    id = new QLineEdit(this);
    titre = new QLineEdit(this);

    desc = new QLineEdit(this);

    liste = new QComboBox(this);
    liste->addItem("Video");
    liste->addItem("Image");




    id->setReadOnly(true);

    Vlayout = new QVBoxLayout(this);
    layout = new QFormLayout(this);

    Open = new QPushButton("Open", this);
    layout->addRow("id", id);
    layout->addRow("Titre", titre);
    layout->addRow("Description", desc);
    layout->addWidget(liste);
    layout->addRow("File",Open);
    Vlayout->addLayout(layout);

    save = new QPushButton("Save", this);
    Vlayout->addWidget(save);

    QObject::connect(save,SIGNAL(clicked(bool)),this,SLOT(saveArticle()));
    QObject::connect(Open,SIGNAL(clicked(bool)),this,SLOT(openFile()));
    setLayout(Vlayout);
}

void v_multimedia::saveMultimedia()
{


    QMessageBox::information(this, "Sauvegarde", "Votre Note Multimedia a été sauvergarder");
}

void v_multimedia::openFile()
{

         QString fileName = QFileDialog::getOpenFileName(this, tr("Open Multimeda"),
                 QDir::homePath());

         if (!fileName.isEmpty()) {
             multimedia->setPath(fileName);
         }
}


