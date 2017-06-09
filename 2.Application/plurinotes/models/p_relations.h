#ifndef P_RELATIONS
#define P_RELATIONS

#include "main.h"
#include "models/p_notes.h"

class Couple
{
    private:
        QString label;
        Note* x;
        Note* y;
    public:
        Couple(QString s,Note* a, Note* b): label(s) {
            x = a;
            y = b;
        }
        const QString getLabel() const { return label; }
};

class Relation
{
    private:
        QString title;
        QString description;
        bool isOriented;
        Couple** couples;
        unsigned int nbCouple;
        unsigned int nbMaxCouple;
    public:
        Relation(QString t,QString d,bool Or): title(t),description(d),isOriented(Or),nbCouple(0),nbMaxCouple(NBMAX) {}
        void addCouple(QString lab,Note* a,Note* b);
        void RemoveCouple(QString lab);
        ~Relation() { if (couples) delete[] couples;}
};

#endif // P_RELATIONS

