#include "main.h"
#include "datetime.h"

std::ostream& operator << (std::ostream& f, const Datetime& d) {

    f << d.getYear() << "-";

    if ( d.getMonth() < 10 )
        f << "0";
    f << d.getMonth() << "-";

    if ( d.getDay() < 10 )
        f << "0";
    f << d.getDay() << " ";

    if ( d.getHour() < 10 )
        f << "0";
    f << d.getHour() << ":";

    if ( d.getMin() < 10 )
        f << "0";
    f << d.getMin() << ":";

    if ( d.getSec() < 10 )
        f << "0";
    f << d.getSec();

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
