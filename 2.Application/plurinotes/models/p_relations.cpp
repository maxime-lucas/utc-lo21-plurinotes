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
QString Couple::toString() const {

    QString f;
        f = "[COUPLE]\n";
        f += "  id : " + Id + "\n";
        f += "  label : " + label + "\n";
        f += "[NOTE_X]\n";
            f += "\n"+x->toString();
        f += "[/NOTE_X]\n";
        f += "[NOTE_Y]\n";
            f += "\n"+y->toString();
        f += "[/NOTE_Y]\n";
        f += "[/COUPLE]\n";

    return f;
}
