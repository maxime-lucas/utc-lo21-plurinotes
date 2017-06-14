#include "main.h"
#include "models/p_relations.h"
#include <QString>

RelationManager::RelationManager() {
    currentId = 0;
    tab = new std::vector<Relation*>;
}
RelationManager::~RelationManager() {
    if (tab) delete[] tab;
}

QString Couple::generateCoupleId(Note* X, Note* Y){
    return (X->getId()+"/"+Y->getId());
}
