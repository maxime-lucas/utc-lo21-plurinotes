#include "main.h"

std::ostream& operator << (std::ostream& f, const QDateTime& d) {

    f << d.currentDateTime().toString() << std::endl;

    return f;
}

std::ostream& operator << (std::ostream& f, const Article& a) {
    f << "id:" << a.getId().toStdString() << " ";
    f << "title:" << a.getTitle().toStdString() << " ";
    f << "createdOn:" << a.getCreatedOn() << " ";
    f << "lastModifOn:" << a.getLastModifOn() << " ";
    f << "text:" << a.getText().toStdString();
    return f;
}

std::ostream& operator << (std::ostream& f, Article *a) {
    f << "id:" << a->getId().toStdString() << " ";
    f << "title:" << a->getTitle().toStdString() << " ";
    f << "createdOn:" << a->getCreatedOn() << " ";
    f << "lastModifOn:" << a->getLastModifOn() << " ";
    f << "text:" << a->getText().toStdString();
    return f;
}
