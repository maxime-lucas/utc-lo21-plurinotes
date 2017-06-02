#include "main.h"
#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow() {
    // Création et initialisation de la fenêtre
    setFixedSize(1366,768);
    setWindowTitle("PluriNotes - FAYA / YAYA / MAX");

    // Mise en place du widget principal pour contenir le layout principal (obligatoire pour une QMainWindow)
    QWidget *centralWidget = new QWidget();
    setCentralWidget(centralWidget);
    mainLayout = new QHBoxLayout;
    centralWidget->setLayout(mainLayout);

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

    createActions();
    createMenus();
}

void MainWindow::createActions()
{
    exitAct = new QAction(tr("&Quit"), this);
    exitAct->setStatusTip(tr("Quit the app"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()) );
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAct);
}
