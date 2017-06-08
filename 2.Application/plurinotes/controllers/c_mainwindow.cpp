#include "main.h"
#include "../models/p_core.h"
#include "c_mainwindow.h"
#include "../views/v_mainwindow.h"
#include "../views/v_littlenote.h"
#include "ui_v_mainwindow.h"
#include "ui_v_articleform.h"
#include "ui_v_multiplenotes.h"

C_Mainwindow::C_Mainwindow(QApplication *q) {

    // Initialisation des models et de la view
    qapp = q;
    view = new V_Mainwindow(0,this);
    app = new PluriNotes;

    refreshActiveNotes();
    createActions();
}

void C_Mainwindow::createActions()
{
    view->connect(view->getUi()->actionQuit, SIGNAL(triggered()), qapp, SLOT(quit()) );
    view->connect(view->getUi()->actionArticle, SIGNAL(triggered()), view, SLOT(openNewArticle()));
}

void C_Mainwindow::refreshActiveNotes() {

    std::vector<Note*> *notes = app->getActiveNotesManager()->getTab();
    unsigned int row = 0;
    unsigned int column = 0;
    for(unsigned int i = 0; i < notes->size(); i++) {
        Note* note = notes->at(i);

        if( typeid(*note) == typeid(Article) ) {
            Article* a = new Article( dynamic_cast<Article&>(*note) );
            view->getActiveNotes()->getGridLayout()->addWidget(new V_Littlenote(this->getView()->getActiveNotes()->getContainer(),a->getId(),article),row,column);
        }

        if( typeid(*note) == typeid(Multimedia) ) {
            Multimedia* a = new Multimedia( dynamic_cast<Multimedia&>(*note) );
            view->getActiveNotes()->getGridLayout()->addWidget(new V_Littlenote(this->getView()->getActiveNotes()->getContainer(),a->getId(),multimedia),row,column);
        }

        if( typeid(*note) == typeid(Task) ) {
            Task* a = new Task( dynamic_cast<Task&>(*note) );
            view->getActiveNotes()->getGridLayout()->addWidget(new V_Littlenote(this->getView()->getActiveNotes()->getContainer(),a->getId(),task),row,column);
        }

        if( column != 0 && column % 2 == 0 )
        {
            row++;
            column=0;
        } else column++;
    }
}
