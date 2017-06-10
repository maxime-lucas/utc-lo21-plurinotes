#ifndef P_NOTES
#define P_NOTES

#include "main.h"
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
        QDateTime createdOn;
        QDateTime lastModifOn;

    public:
        Note(QString i = "", QString t = "", QDateTime co = QDateTime::currentDateTime(), QDateTime lmo = QDateTime::currentDateTime()) :
            id(i),
            title(t),
            createdOn(co),
            lastModifOn(lmo) {}
        virtual ~Note() = 0;

        QString getId() const { return id; }
        QString getTitle() const { return title; }
        QDateTime getCreatedOn() const { return createdOn; }
        QDateTime getLastModifOn() const { return lastModifOn; }

        void setId(QString i) { id = i; }
        void setTitle(QString t) { title = t; }
        void setCreatedOn(QDateTime co) { createdOn = co; }
        void setLastModifOn(QDateTime lmo) { lastModifOn = lmo; }

};

class Article : public Note {
    private :
        QString text;

    public :
        Article(QString i = "", QString t = "", QDateTime co = QDateTime::currentDateTime(), QDateTime lmo = QDateTime::currentDateTime(), QString txt = "" ) : Note(i,t,co,lmo), text(txt) {}
        ~Article();

        QString getText() const { return text; }
        void setText(QString t) { text = t; }
};

class Multimedia : public Note {
    private :
        QString description;
        QString fileName;
        enum TypeMultimedia type;

    public :
        Multimedia(QString i = "", QString t = "", QDateTime co = QDateTime::currentDateTime(), QDateTime lmo = QDateTime::currentDateTime(), QString desc = "", QString ptf = "", TypeMultimedia tm = PICTURE) : Note(i,t,co,lmo), description(desc), fileName(ptf), type(tm) {}

        ~Multimedia();

        QString getDescription() const { return description; }
        QString getFileName() const { return fileName; }
        void setFileName(QString f) { fileName = f; }
        enum TypeMultimedia getType() const { return type; }
        QString getTypeToQString() const { if(type==PICTURE) return "picture"; if(type==VIDEO) return "video"; return "audio"; }
};

class Task : public Note {
    private :
        QString action;
        unsigned int priority;
        QDateTime toBeDoneOn;
        enum TaskStatus status;

    public :
        Task(QString i = "", QString t = "", QDateTime co = QDateTime::currentDateTime(), QDateTime lmo = QDateTime::currentDateTime(), QString a ="", unsigned int p = 0, QDateTime tbdo = QDateTime::currentDateTime(), TaskStatus s = PENDING) : Note(i,t,co,lmo), action(a), priority(p), toBeDoneOn(tbdo), status(s)  {}

        ~Task();
};

#endif // P_NOTES
