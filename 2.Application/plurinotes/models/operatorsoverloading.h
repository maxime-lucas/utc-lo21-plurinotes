#ifndef OPERATORSOVERLOADING
#define OPERATORSOVERLOADING

#include "main.h"
#include "p_notes.h"


std::ostream& operator << (std::ostream& , const QDateTime& );

class Article;

std::ostream& operator << (std::ostream& f, const Article& a);
std::ostream& operator << (std::ostream& f, Article *a);

#endif // OPERATORSOVERLOADING

