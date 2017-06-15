#ifndef P_NOTES
#define P_NOTES

#include "main.h"
#include "p_versions.h"
#include <QString>
#include <QDateTime>


/*!
 * \file p_notes.h
 * \brief Gestion des notes de tous types
 * \author FAYAX
 * \version 1.0
 */


class Note;
class Article;
class Multimedia;
class Task;


/*!
 * \class NotesManager
 * \brief Classe mère des NotesManager, qui permet de gérer les différents états des notes par héritage
 *
 */

class NotesManager {

    private:
        std::vector<Note*>* tab;

    public:

        NotesManager();
        virtual ~NotesManager() = 0;

        std::vector<Note*>* getTab() const { return tab; }

};


/*!
 * \class ActiveNotesManager
 * \brief Classe Manager pour les Notes actives
 *
 */
class ActiveNotesManager : public NotesManager {
    public:
        ActiveNotesManager();
        ~ActiveNotesManager();
};

/*!
 * \class ArchivedNotesManager
 * \brief Classe Manager pour les notes archivées
 *
 */
class ArchivedNotesManager : public NotesManager {
    public:
        ArchivedNotesManager();
        ~ArchivedNotesManager();
};


/*!
 * \class DeletedNotesManager
 * \brief Classe Manager pour les notes supprimées
 *
 */
class DeletedNotesManager : public NotesManager {
    public:
        DeletedNotesManager();
        ~DeletedNotesManager();
};


/*!
 * \class Version
 * \brief
 *
 */
class Version;


/*!
 * \class Note
 * \brief Classe mère des notes, qui reprend les attributs & méthodes communs
 * Classe principale des notes, elle permet de définir l'ensemble des parties communes aux types de notes, le reste se faisant par héritage
 */
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

/*!
 * \class Article
 * \brief Classe héritée de Note
 * Les articles sont des notes avec champs texte
 */
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

/*!
 * \class Multimédia
 * \brief Classe héritée de Note
 * Les multimédias sont des notes avec une description et un type de contenu multimédia
 */

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

/*!
 * \class Tâche
 * \brief Classe héritée de Note
 * Les tâches sont des notes avec une action, une priorité et des dates indicatives
 */

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
