#ifndef OPERATORSOVERLOADING
#define OPERATORSOVERLOADING

#include "main.h"
#include "datetime.h"
#include "p_notes.h"

std::ostream& operator << (std::ostream& , const Datetime& );
std::ostream& operator << (std::ostream& f, const Article& a);
std::ostream& operator << (std::ostream& f, Article *a);

#endif // OPERATORSOVERLOADING

