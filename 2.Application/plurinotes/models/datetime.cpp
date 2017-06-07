#include "main.h"
#include "datetime.h"

Datetime::Datetime(QString s) {
    year = atoi(s.toStdString().substr(0,4).c_str());
    month = atoi(s.toStdString().substr(5,2).c_str());
    day = atoi(s.toStdString().substr(8,2).c_str());
    hour = atoi(s.toStdString().substr(11,2).c_str());
    min = atoi(s.toStdString().substr(14,2).c_str());
    sec = atoi(s.toStdString().substr(17,2).c_str());
}
