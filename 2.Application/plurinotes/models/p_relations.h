#ifndef P_RELATIONS
#define P_RELATIONS

#include "main.h"

class Couple
{
    private:
        string label;
        Note* x;
        Note* y;
    public:
        Couple(string s,Note* a, Note* b): label(s) {
            x = a;
            y = b;
        }
        const std::string getLabel() const { return label; }
};

class Relation
{
    private:
        string title;
        string description;
        bool isOriented;
        Couple** couples;
        unsigned int nbCouple;
        unsigned int nbMaxCouple;
    public:
        Relation(string t,string d,bool Or): title(t),description(d),isOriented(Or),nbCouple(0),nbMaxCouple(NBMAX) {}
        void addCouple(string lab,Note* a,Note* b);
        void RemoveCouple(string lab);
        ~Relation() { if (couples) delete[] couples;}
};

#endif // P_RELATIONS

