#ifndef PLURINOTES_H
#define PLURINOTES_H
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "timming.h"

#define NBMAX 100

using namespace std;

class NotesException{
public:
    NotesException(const string& message):info(message){}
    string getInfo() const { return info; }
private:
    string info;
};


class Note
{
private:
    string id;
    string title;
public:
    Note(){};
};

class version
{
private:
    unsigned int numero;
    Note* state;
public:
    version(unsigned int num,Note* s): numero(num), state(s) {}
};

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
    string const getLabel() const {return label;};
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
    ~Relation()
    { if (couples) delete[] couples;}


};

#endif // PLURINOTES_H
