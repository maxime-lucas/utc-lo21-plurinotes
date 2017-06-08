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
