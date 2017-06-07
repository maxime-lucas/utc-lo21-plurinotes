#include "main.h"
#include "datetime.h"

std::ostream& operator << (std::ostream& f, const Datetime& d) {

    f << d.getYear() << "-";

    ( d.getMonth() < 10 ) ? f << "0" : "" ;
    f << d.getMonth() << "-";

    ( d.getDay() < 10 ) ? f << "0" : "" ;
    f << d.getDay() << " ";

    ( d.getHour() < 10 ) ? f << "0" : "" ;
    f << d.getHour() << ":";

    ( d.getMin() < 10 ) ? f << "0" : "" ;
    f << d.getMin() << ":";

    ( d.getSec() < 10 ) ? f << "0" : "" ;
    f << d.getSec();

    return f;
}
