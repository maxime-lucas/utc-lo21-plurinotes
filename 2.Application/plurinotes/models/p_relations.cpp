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

void RelationManager::deleteByRelation(Relation* r)
{
    for(unsigned int i = 0;i < getTab()->size(); i ++)
    {
        Relation* relation = getTab()->at(i);
        if(relation->getId() == r->getId())
            getTab()->erase(getTab()->begin()+i);
    }
}
