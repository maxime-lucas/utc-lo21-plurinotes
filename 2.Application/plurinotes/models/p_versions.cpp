#include "main.h"
#include "p_versions.h"

#include <typeinfo>

QString Version::toString() const {
    QString f;
        f = "[VERSION]\n";
        f += "  numVersion : " + QString::number(numVersion) + "\n";

        if(typeid(*state) == typeid(Article)) {
            Article *a = new Article(dynamic_cast<Article&>(*state));
            f += a->toString();
        } else if(typeid(*state) == typeid(Multimedia)) {
            Multimedia *m = new Multimedia(dynamic_cast<Multimedia&>(*state));
            f += m->toString();
        } else if(typeid(*state) == typeid(Task)) {
            Task *t = new Task(dynamic_cast<Task&>(*state));
            f += t->toString();
        }

        f += "[/VERSION]\n";


    return f;
}
