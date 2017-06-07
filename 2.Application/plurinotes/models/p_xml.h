#ifndef P_XML
#define P_XML

#include "main.h"

class XMLManager : public QWidget {
    private:
    QDomDocument *dom;
    QFile doc;

    public:
    XMLManager(const QString &);

    ~XMLManager();
};

#endif // P_XML

