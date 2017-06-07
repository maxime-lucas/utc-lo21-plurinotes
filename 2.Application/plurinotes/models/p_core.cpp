#include "main.h"
#include "models/p_core.h"

PluriNotes::PluriNotes() {
    activeNotesManager = new ActiveNotesManager();
    deletedNotesManager = new DeletedNotesManager();
    archivedNotesManager = new ArchivedNotesManager();
    xmlManager = new XMLManager("../plurinotes/ressources/data.xml");

    std::vector<Article*> activeArticle = xmlManager->getAllActiveArticles();
    for(unsigned int i = 0; i < activeArticle.size() ; i++ ) {
        Article *a = activeArticle[i];
        activeNotesManager->addElement(a);
    }
    std::cout << activeNotesManager->getNb() << std::endl;
}

PluriNotes::~PluriNotes() {
    delete activeNotesManager;
    delete archivedNotesManager;
    delete deletedNotesManager;
}
