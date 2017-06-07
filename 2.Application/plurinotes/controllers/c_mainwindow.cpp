#include "main.h"
#include "c_mainwindow.h"
#include "../views/v_mainwindow.h"

C_Mainwindow::C_Mainwindow(QApplication *q) {
    // Initialisation des models et de la view
    qapp = q;
    view = new V_Mainwindow;
    app = new PluriNotes;

    // Création des actions
    createActions();

    // Connexions des éléments à leurs actions
    view->getFileMenu()->addAction(newAct);
    view->getFileMenu()->addAction(exitAct);
}

void C_Mainwindow::createActions()
{
    newAct = new QAction(QString::fromStdString("New..."), view);
    //view->connect(exitAct, SIGNAL(triggered()), view, SLOT(close()) );

    exitAct = new QAction(QString::fromStdString("Quit"), view);
    view->connect(exitAct, SIGNAL(triggered()), view, SLOT(close()) );
}
