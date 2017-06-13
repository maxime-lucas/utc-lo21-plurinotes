#ifndef P_NOTES
#define P_NOTES

#include "main.h"
#include "p_versions.h"
#include <QString>
#include <QDateTime>

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

class Version;

class Note {

    protected:
        QString id;
        QString title;
        QDateTime createdOn;
        QDateTime lastModifOn;
        std::vector<Version*>* versions;

    public:
        Note(QString i = "", QString t = "", QDateTime co = QDateTime::currentDateTime(), QDateTime lmo = QDateTime::currentDateTime(),std::vector<Version*>* v = new std::vector<Version*>) :
            id(i),
            title(t),
            createdOn(co),
            lastModifOn(lmo),
            versions(v){}
        virtual ~Note() = 0;

        QString getId() const { return id; }
        QString getTitle() const { return title; }
        QDateTime getCreatedOn() const { return createdOn; }
        QDateTime getLastModifOn() const { return lastModifOn; }
        std::vector<Version*>* getVersions() const { return versions; }

        void setId(QString i) { id = i; }
        void setTitle(QString t) { title = t; }
        void setCreatedOn(QDateTime co) { createdOn = co; }
        void setLastModifOn(QDateTime lmo) { lastModifOn = lmo; }

        virtual QString toString() const = 0;

};

class Article : public Note {
    protected :
        QString text;

    public :
        Article(QString i = "", QString t = "", QDateTime co = QDateTime::currentDateTime(), QDateTime lmo = QDateTime::currentDateTime(), QString txt = "",std::vector<Version*>* versions = new std::vector<Version*>) : Note(i,t,co,lmo,versions), text(txt) {}
        ~Article();

        QString getText() const { return text; }
        void setText(QString t) { text = t; }
        QString toString() const;
};

class Multimedia : public Note {
    protected :
        QString description;
        QString fileName;
        enum TypeMultimedia type;

    public :
        Multimedia(QString i = "", QString t = "", QDateTime co = QDateTime::currentDateTime(), QDateTime lmo = QDateTime::currentDateTime(), QString desc = "", QString ptf = "", TypeMultimedia tm = PICTURE,std::vector<Version*>* versions = new std::vector<Version*>) : Note(i,t,co,lmo,versions), description(desc), fileName(ptf), type(tm) {}

        ~Multimedia();

        QString getDescription() const { return description; }
        QString getFileName() const { return fileName; }
        enum TypeMultimedia getType() const { return type; }
        QString getTypeToQString() const { if(type==PICTURE) return "picture"; if(type==VIDEO) return "video"; return "audio"; }

        void setDesc(QString d) { description = d;}
        void setFileName(QString f) { fileName = f; }
        QString toString() const;
};


class Task : public Note {
    protected :
        QString action;
        unsigned int priority;
        QDateTime toBeDoneOn;
        enum TaskStatus status;

    public :
        Task(QString i = "", QString t = "", QDateTime co = QDateTime::currentDateTime(), QDateTime lmo = QDateTime::currentDateTime(), QString a ="", unsigned int p = 0, QDateTime tbdo = QDateTime::currentDateTime(), TaskStatus s = PENDING, std::vector<Version*>* versions = new std::vector<Version*>) : Note(i,t,co,lmo,versions), action(a), priority(p), toBeDoneOn(tbdo), status(s)  {}

        ~Task();

        //Getters
        QString getAction() const { return action; }
        unsigned int getPriority() const { return priority; }
        QDateTime getDeadline() const { return toBeDoneOn; }
        TaskStatus getStatus() const {return status;}
        QString getStatusToString() const { if(status==PENDING) return "PENDING"; if(status==PROGRESS) return "PROGRESS"; if(status==FINISHED) return "FINISHED"; return "UNKNOWN";}

        void setAction(QString a) {action = a;}
        void setPriority(unsigned int p) {priority = p;}
        void setDeadline(QDateTime d) {toBeDoneOn = d;}
        void setStatus(TaskStatus s) {status = s;}
        QString toString() const;


};

#endif // P_NOTES
