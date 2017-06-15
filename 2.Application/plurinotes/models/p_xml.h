
#ifndef P_XML
#define P_XML

#include "main.h"

#include <QDomDocument>
#include <QWidget>
#include <QFile>

#include "p_notes.h"
#include "p_relations.h"

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
    Couple* getCoupleById(QString) const;
    Note* getNoteById(QString) const;
    std::vector<Relation*>getAllRelations() const;
    unsigned int getLastId() const;

    void insertIntoArticle(Article*);
    void insertIntoTask(Task*t);
    void insertIntoMultimedia(Multimedia*);
    void insertIntoRelation(Relation*);
    void insertIntoCouple(Couple*);
    void insertIntoRelationCouple(Relation*,Couple*);

    void deleteFromArticle(Article*);
    void deleteFromMultimedia(Multimedia*);
    void deleteFromTask(Task*t);

    void updateArticle(Article*,Article*);
    void updateMultimedia(Multimedia*,Multimedia*);
    void updateTask(Task*,Task*);

    void deleteNoteVersion(Note*,Version*);
    void restoreNoteVersion(Note*,Version*);

    void deleteCouple(Relation*r,Couple*c);
    void deleteRelation(Relation*r);

    ~XMLManager();
};

#endif // P_XML

