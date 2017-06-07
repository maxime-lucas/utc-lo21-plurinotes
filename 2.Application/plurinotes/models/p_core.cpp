#include "main.h"
#include "models/p_core.h"

PluriNotes::PluriNotes() {
    activeNotesManager = new ActiveNotesManager();
    deletedNotesManager = new DeletedNotesManager();
    archivedNotesManager = new ArchivedNotesManager();
    xmlManager = new XMLManager("../plurinotes/ressources/data.xml");
}

PluriNotes::~PluriNotes() {
    delete activeNotesManager;
    delete archivedNotesManager;
    delete deletedNotesManager;
}
