#include "main.h"
#include "models/p_core.h"

PluriNotes::PluriNotes() {
    activeNotesManager = new ActiveNotesManager();
    deletedNotesManager = new DeletedNotesManager();
    archivedNotesManager = new ArchivedNotesManager();
    xmlManager = new XMLManager("../plurinotes/ressources/data.xml");

    // Récupération des articles actifs
    std::vector<Article*> activeArticle = xmlManager->getAllActiveArticles();
    for(unsigned int i = 0; i < activeArticle.size() ; i++ ) {
        Article *a = activeArticle[i];
        activeNotesManager->getTab()->push_back(a);
    }

    // Récupération des multimedia actifs
    std::vector<Multimedia*> activeMultimedia = xmlManager->getAllActiveMultimedia();
    for(unsigned int i = 0; i < activeMultimedia.size() ; i++ ) {
        Multimedia *m = activeMultimedia[i];
        activeNotesManager->getTab()->push_back(m);
    }

    // Récupération des tasks actives
    std::vector<Task*> activeTasks = xmlManager->getAllActiveTasks();
    for(unsigned int i = 0; i < activeTasks.size() ; i++ ) {
        Task *t = activeTasks[i];
        activeNotesManager->getTab()->push_back(t);
    }
}

PluriNotes::~PluriNotes() {
    delete activeNotesManager;
    delete archivedNotesManager;
    delete deletedNotesManager;
}

Note* PluriNotes::getNoteByID(QString id) {

    for(unsigned int i = 0; i < activeNotesManager->getTab()->size() ; i++ ) {
        Note* n = activeNotesManager->getTab()->at(i);
        if(n->getId() == id) return n;
    }

    for(unsigned int i = 0; i < archivedNotesManager->getTab()->size() ; i++ ) {
        Note* n = archivedNotesManager->getTab()->at(i);
        if(n->getId() == id) return n;
    }

    for(unsigned int i = 0; i < deletedNotesManager->getTab()->size() ; i++ ) {
        Note* n = deletedNotesManager->getTab()->at(i);
        if(n->getId() == id) return n;
    }

    return 0;
}
