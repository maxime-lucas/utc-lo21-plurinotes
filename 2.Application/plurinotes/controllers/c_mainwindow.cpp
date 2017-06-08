#include "main.h"
#include "../models/p_core.h"
#include "c_mainwindow.h"
#include "../views/v_mainwindow.h"
#include "../views/v_littlenote.h"
#include "ui_v_mainwindow.h"
#include "ui_v_multiplenotes.h"

C_Mainwindow::C_Mainwindow(QApplication *q) {

    // Initialisation des models et de la view
    qapp = q;
    view = new V_Mainwindow;
    app = new PluriNotes;

    refreshActiveNotes();
}

void C_Mainwindow::refreshActiveNotes() {

    std::vector<Note*> *notes = app->getActiveNotesManager()->getTab();
    QGridLayout *gridLayout = new QGridLayout;
    unsigned int row = 0;
    unsigned int column = 0;
    for(unsigned int i = 0; i < notes->size(); i++) {
        Note* note = notes->at(i);

        if( typeid(*note) == typeid(Article) ) {
            Article* a = new Article( dynamic_cast<Article&>(*note) );
            gridLayout->addWidget(new V_Littlenote(this->getView()->getActiveNotes()->getContainer(),a->getId(),article),row,column);
        }

        if( column != 0 && column % 1 == 0 )
        {
            row++;
            column=0;
        } else column++;
    }
}
