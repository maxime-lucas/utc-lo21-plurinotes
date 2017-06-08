#include "main.h"
#include "v_mainwindow.h"

V_Mainwindow::V_Mainwindow() : QMainWindow() {
    // Création et initialisation de la fenêtre
    setFixedSize(1366,768);
    setWindowTitle("PluriNotes - FAYA / YAYA / MAX");

    // Mise en place du widget principal pour contenir le layout principal (obligatoire pour une QMainWindow)
    QWidget *centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    // Mise en place des ongles
    tab = new QTabWidget(centralWidget);
    mainView = new QWidget;
    secondaryView = new QWidget;
    tab->addTab(mainView,"Vue principale");
    tab->addTab(secondaryView,"Vue secondaire");

    mainLayout = new QHBoxLayout;
    mainView->setLayout(mainLayout);

    // Mise en place du widget gauche qui contiendra les trois listwidgets
    QWidget *leftPart = new QWidget();
    leftPart->setFixedSize(455,768);
    leftLayout = new QVBoxLayout;
    leftPart->setLayout(leftLayout);
    mainLayout->addWidget(leftPart);

    // Initialisation et Ajout des listwidgets au widget de gauche
    activeNotes = new QListWidget();
    task = new QListWidget();
    archivedNotes = new QListWidget();

    leftLayout->addWidget(activeNotes);
    leftLayout->addWidget(task);
    leftLayout->addWidget(archivedNotes);

    // Mise en place du widget central qui contiendra la vue principale
    QWidget *mainPart = new QWidget();
    mainPart->setFixedSize(455,768);
    mainLayout->addWidget(mainPart);

    // Mise en place du widget droite qui contiendra les arborescences
    QWidget *rightPart = new QWidget();
    rightPart->setFixedSize(455,768);
    mainLayout->addWidget(rightPart);

    // Création du menu tout en haut
    fileMenu = this->menuBar()->addMenu(tr("&File"));

    //ajout bouton ajouter article
    NewArticle = new QPushButton("Nouvel Article", this);
    NewArticle->setCursor(Qt::PointingHandCursor);
    NewArticle->move(30, 20);
    QObject::connect(NewArticle, SIGNAL(clicked()), this, SLOT(AfficherFormArticle()));
}

void V_Mainwindow::AfficherFormArticle(){
    v_article *fenetre = new v_article;
    fenetre->show();
}
