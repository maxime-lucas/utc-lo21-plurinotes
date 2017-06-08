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

    // Ajout des notes actives dans le listwidget de la view
    for(unsigned int i; i < app->getActiveNotesManage()->getTab()->size() ; i++ ) {
        Note *n = app->getActiveNotesManage()->getTab()->at(i);

        view->getActiveNotes()->addItem(n->getTitle()   );
    }
}

void C_Mainwindow::createActions()
{
    newAct = new QAction(QString::fromStdString("New..."), view);

    exitAct = new QAction(QString::fromStdString("Quit"), view);
    view->connect(exitAct, SIGNAL(triggered()), view, SLOT(close()) );
}
