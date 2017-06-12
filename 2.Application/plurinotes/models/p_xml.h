
#ifndef P_XML
#define P_XML

#include "main.h"
#include "p_notes.h"

class XMLManager : public QWidget {
    private:
    QDomDocument *dom;
    QFile doc;
    QString pathToFile;

    public:
    XMLManager(const QString &);
    std::vector<Article*> getAllActiveArticles() const;
    std::vector<Multimedia*> getAllActiveMultimedia() const;
    std::vector<Task*> getAllActiveTasks() const;
    unsigned int getLastId() const;
    void insertIntoArticle(Article*);
    void insertIntoMultimedia(Multimedia*);
    void insertIntoTask(Task*t);

    ~XMLManager();
};

#endif // P_XML

