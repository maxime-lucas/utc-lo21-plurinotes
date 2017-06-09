#ifndef P_NOTES
#define P_NOTES

#include "main.h"
#include "datetime.h"
#include <QString>

class Note;
class Article;
class Multimedia;
class Task;

class NotesManager {

    private:
        std::vector<Note*>* tab;

    public:

        NotesManager();
        virtual ~NotesManager() = 0;

        std::vector<Note*>* getTab() const { return tab; }
};

class ActiveNotesManager : public NotesManager {
    public:
        ActiveNotesManager();
        ~ActiveNotesManager();
};

class ArchivedNotesManager : public NotesManager {
    public:
        ArchivedNotesManager();
        ~ArchivedNotesManager();
};

class DeletedNotesManager : public NotesManager {
    public:
        DeletedNotesManager();
        ~DeletedNotesManager();
};

class Note {

    private:
        QString id;
        QString title;
        Datetime createdOn;
        Datetime lastModifOn;

    public:
        Note(QString i = "", QString t = "", Datetime co = 0, Datetime lmo = 0) :
            id(i),
            title(t),
            createdOn(co),
            lastModifOn(lmo) {}
        virtual ~Note() = 0;

        QString getId() const { return id; }
        QString getTitle() const { return title; }
        Datetime getCreatedOn() const { return createdOn; }
        Datetime getLastModifOn() const { return lastModifOn; }

        void setId(QString i) { id = i; }
        void setTitle(QString t) { title = t; }
        void setCreatedOn(Datetime co) { createdOn = co; }
        void setLastModifOn(Datetime lmo) { lastModifOn = lmo; }

};

class Article : public Note {
    private :
        QString text;

    public :
        Article(QString i = "", QString t = "", Datetime co = 0, Datetime lmo = 0, QString txt = "" ) : Note(i,t,co,lmo), text(txt) {}
        ~Article();

        QString getText() const { return text; }
        void setText(QString t) { text = t; }
};

class Multimedia : public Note {
    private :
        QString description;
        QString pathToFile;
        enum TypeMultimedia type;

    public :
        Multimedia(QString i = "", QString t = "", Datetime co = 0, Datetime lmo = 0, QString desc = "", QString ptf = "", TypeMultimedia tm = PICTURE) : Note(i,t,co,lmo), description(desc), pathToFile(ptf), type(tm) {}

        ~Multimedia();
};

class Task : public Note {
    private :
        QString action;
        unsigned int priority;
        Datetime toBeDoneOn;
        enum TaskStatus status;

    public :
        Task(QString i = "", QString t = "", Datetime co = 0, Datetime lmo = 0, QString a ="", unsigned int p = 0, Datetime tbdo = 0, TaskStatus s = PENDING) : Note(i,t,co,lmo), action(a), priority(p), toBeDoneOn(tbdo), status(s)  {}

        ~Task();
};

#endif // P_NOTES
