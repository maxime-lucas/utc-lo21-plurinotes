#include "main.h"

#include <iostream>
#include <string>

#include "models/p_core.h"

PluriNotes::PluriNotes() {
    activeNotesManager = 0;
    deletedNotesManager = 0;
    archivedNotesManager = 0;
    relationManager = 0;
    xmlManager = 0;

    reloadFromDatabase();
}

PluriNotes::~PluriNotes() {
    delete activeNotesManager;
    delete archivedNotesManager;
    delete deletedNotesManager;
    delete relationManager;
}

void PluriNotes::reloadFromDatabase() {
    if(activeNotesManager != 0) delete activeNotesManager;
    if(deletedNotesManager != 0) delete deletedNotesManager;
    if(archivedNotesManager != 0) delete archivedNotesManager;
    if(relationManager != 0) delete relationManager;
    if(xmlManager != 0) delete xmlManager;

    activeNotesManager = new ActiveNotesManager();
    deletedNotesManager = new DeletedNotesManager();
    archivedNotesManager = new ArchivedNotesManager();
    relationManager = new RelationManager();
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

Relation* PluriNotes::getRelationByID(QString id) {

    for(unsigned int i = 0; i < relationManager->getTab()->size() ; i++ ) {
        Relation* r = relationManager->getTab()->at(i);
        if(r->getId() == id) return r;
    }

    return 0;
}

Couple* PluriNotes::getCoupleByID(QString id,Relation* r) {

    for(unsigned int i = 0; i < r->getCouples()->size() ; i++ ) {
        Couple* c = r->getCouples()->at(i);
        if(c->getId() == id) return c;}

    return 0;
}


Version* PluriNotes::getNoteVersionByID(QString id, QString numV) {
    Note* n = getNoteByID(id);

    for(unsigned int i = 0; i < n->getVersions()->size() ; i++ ) {
        Version *v = n->getVersions()->at(i);
        if(v->getNumVersion() == (unsigned)numV.toInt()) return v;
    }

    return 0;
}

void PluriNotes::debug(QString str) {
    std::cout << "[DEBUG] " << str.toStdString() << std::endl;
}
