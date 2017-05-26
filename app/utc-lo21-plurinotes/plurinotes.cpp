#include "plurinotes.h"

void Relation::addCouple(string lab, Note *a, Note *b){
    if(nbCouple == nbMaxCouple)
    {
    //Augnmente taille Couple**
     Couple ** newtab = new Couple*[nbMaxCouple+NBMAX];
     for(unsigned int i=0; i<nbCouple; i++)
             newtab[i]=couples[i];
     Couple** oldCouples=couples;
     couples=newtab;
     nbMaxCouple+=NBMAX;
     if (oldCouples) delete[] oldCouples;
    }

    Couple x(lab,a,b);
    //verification si x est deja dans couples (en bonus)

    couples[nbCouple+1] =  &x;
    nbCouple ++;
}

void Relation::RemoveCouple(string lab)
{
    for(unsigned int i=0; i<nbCouple; i++){
            if (couples[i]->getLabel()==lab)
            {
                //delete couples[i];
                //decalage des couples restant dans le tableau
                for(unsigned int j=i; j<nbCouple;j++)
                    couples[j] = couples[j+1];
                nbCouple --;
                return;
             }
        }
    throw NotesException("error, non existent couple");
}
