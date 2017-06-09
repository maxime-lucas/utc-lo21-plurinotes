#ifndef DATETIME
#define DATETIME

#include "main.h"

class Datetime {

    private:
        unsigned int hour;
        unsigned int min;
        unsigned int sec;

        unsigned int year;
        unsigned int month;
        unsigned int day;

    public:
        Datetime(unsigned int d = 0, unsigned int mo = 0, unsigned int y = 0, unsigned int h = 0, unsigned int mn = 0, unsigned int s = 0) : hour(h), min(mn), sec(s), year(y), month(mo), day(d) {}
        Datetime(QString);

        unsigned int getHour() const { return hour; }
        unsigned int getMin() const { return min; }
        unsigned int getSec() const { return sec; }
        unsigned int getYear() const { return year; }
        unsigned int getMonth() const { return month; }
        unsigned int getDay() const { return day; }

        QString toString() const;
};

#endif // DATETIME

