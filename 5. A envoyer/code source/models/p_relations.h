#ifndef P_RELATIONS
#define P_RELATIONS

#include "main.h"
#include "models/p_notes.h"

/*!
 * \file p_relations.h
 * \brief Gestion des relations et couples
 * \author FAYAX
 * \version 1.0
 */

class Relation;


/*!
 * \class RelationManager
 * \brief Classe qui permet de gérer les différentes relations
 *
 *
 */
class RelationManager {

    private:
        std::vector<Relation*>* tab;
        unsigned int currentId;

    public:

        RelationManager();
        ~RelationManager();
        /*!
              getCurrentId() permet d'obtenir le dernier id d'une relation afin de pouvoir affecter à une nouvelle relation l'id suivant par exemple
        */
        unsigned int getCurrentId() const {return currentId;}

        void incCurrentId() {currentId++;}
        void decCurrentId() {currentId--;}

        std::vector<Relation*>* getTab() const { return tab;}

        void deleteByRelation(Relation*);
};

/*!
 * \class Couple
 * \brief Classe qui permet de gérer les différentes couples qui se trouvent dans les relations
 *
 *
 */
class Couple
{
    private:
        QString Id;
        QString label;
        Note* x;
        Note* y;
    public:
        Couple(QString s,Note* a, Note* b): label(s) {
            x = a;
            y = b;
            Id = generateCoupleId(a,b);
        }

        QString getId() const {return Id;}
        const QString getLabel() const { return label; }
        Note* getX() const {return x;}
        Note* getY() const {return y;}

        void setLabel(QString l) {label = l;}
        void setX(Note* a) {x = a;}
        void setY(Note* b) {x = b;}

        /*!
             generateCoupleId permet de créer un Id pour le couple sous la forme id note X / id note Y, par exemple pour la note 1 et la note 2 : [1/2]
        */
        QString generateCoupleId(Note* X, Note* Y);
        QString toString() const;
};


/*!
 * \class Relation
 * \brief Classe qui permet de créer les différentes relations
 *
 *  On notera que la relation "reference" n'existe pas encore, mais il est possible de la créer en ajoutant un champ bool "isReference" qui permet de la rendre unique
 */
class Relation {
    private:
        QString id;
        QString title;
        QString description;
        bool isOriented;
        std::vector<Couple*>* couples;

    public:
        Relation(QString i, QString t, QString d, bool iO) : id(i), title(t), description(d), isOriented(iO), couples(new std::vector<Couple*>) {}
        Relation(QString i, QString t, QString d, bool iO,std::vector<Couple*>*c) : id(i), title(t), description(d), isOriented(iO), couples(c) {}

        QString getId() const { return id; }
        QString getTitle() const { return title; }
        QString getDesc() const { return description; }
        bool getOriented() const { return isOriented; }
        std::vector<Couple*>* getCouples() const { return couples; }

        void setTitle(QString t) {title = t;}
        void setDesc(QString d) {description = d;}
        void setOriented(bool o) {isOriented = o;}

        QString toString() const;
        ~Relation() { if (couples) delete[] couples;}
};

#endif // P_RELATIONS

