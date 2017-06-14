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
        Note* getX() const {return x;}
        Note* getY() const {return y;}
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
        ~Relation();

        QString getId() const { return id; }
        QString getTitle() const { return title; }
        QString getDescription() const { return description; }
        bool getIsOriented() const { return isOriented; }
        std::vector<Couple*>* getCouples() const { return couples; }
};

#endif // P_RELATIONS

