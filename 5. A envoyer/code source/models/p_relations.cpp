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


/*!
 * \brief Couple::generateCoupleId
 * \param X la note 1
 * \param Y la note 2
 * \return un id unique sous la forme "id1 / id2"
 */
QString Couple::generateCoupleId(Note* X, Note* Y){
    return (X->getId()+"/"+Y->getId());
}

/*!
 * \brief RelationManager::deleteByRelation
 * Supprime une relation
 */
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

QString Relation::toString() const {

    QString f;
        f = "[RELATION]\n";
        f += "  id : " + id + "\n";
        f += "  title : " + title + "\n";
        f += "  description : " + description + "\n";
        if(isOriented) f += "  isOriented : TRUE\n";
        else f += "  isOriented : FALSE\n";
        f += "[COUPLES][size=" + QString::number(couples->size()) + "]\n";

        for(unsigned int i = 0; i < couples->size(); i++){
            Couple *c = couples->at(i);
            f += "\n"+c->toString();
        }
        f += "[/COUPLES]\n";
        f += "[/RELATION]\n";

    return f;
}
