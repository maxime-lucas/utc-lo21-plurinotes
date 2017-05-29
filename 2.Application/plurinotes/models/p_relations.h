#ifndef P_RELATIONS
#define P_RELATIONS

#include "main.h"

class Couple
{
    private:
        std::string label;
        Note* x;
        Note* y;
    public:
        Couple(std::string s,Note* a, Note* b): label(s) {
            x = a;
            y = b;
        }
        const std::string getLabel() const { return label; }
};

class Relation
{
    private:
        std::string title;
        std::string description;
        bool isOriented;
        Couple** couples;
        unsigned int nbCouple;
        unsigned int nbMaxCouple;
    public:
        Relation(std::string t,std::string d,bool Or): title(t),description(d),isOriented(Or),nbCouple(0),nbMaxCouple(NBMAX) {}
        void addCouple(std::string lab,Note* a,Note* b);
        void RemoveCouple(std::string lab);
        ~Relation() { if (couples) delete[] couples;}
};

#endif // P_RELATIONS

