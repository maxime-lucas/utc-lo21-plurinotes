#ifndef P_XML
#define P_XML

#include "main.h"
#include "p_notes.h"

class XMLManager : public QWidget {
    private:
    QDomDocument *dom;
    QFile doc;

    public:
    XMLManager(const QString &);
    std::vector<Article*> getAllActiveArticles();
    ~XMLManager();
};

#endif // P_XML

