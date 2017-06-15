#ifndef P_RELATIONS
#define P_RELATIONS

#include "main.h"
#include "models/p_notes.h"

class Relation;

class RelationManager {

    private:
        std::vector<Relation*>* tab;
        unsigned int currentId;

    public:

        RelationManager();
        ~RelationManager();
        unsigned int getCurrentId() const {return currentId;}

        void incCurrentId() {currentId++;}
        void decCurrentId() {currentId--;}

        std::vector<Relation*>* getTab() const { return tab;}
};


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

        QString generateCoupleId(Note* X, Note* Y);
        QString toString() const;
};

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

