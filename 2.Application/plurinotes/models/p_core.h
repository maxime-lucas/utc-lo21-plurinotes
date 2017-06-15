

#ifndef P_CORE
#define P_CORE

#include "main.h"
#include "p_notes.h"
#include "p_relations.h"
#include "p_xml.h"



/*!
 * \class Plurinotes
 *
 */
class PluriNotes {

    private:
        ActiveNotesManager* activeNotesManager;
        ArchivedNotesManager* archivedNotesManager;
        DeletedNotesManager* deletedNotesManager;
        RelationManager* relationManager;
        XMLManager* xmlManager;

    public:
        PluriNotes();
        ~PluriNotes();

        ActiveNotesManager* getActiveNotesManager() const { return activeNotesManager; }
        ArchivedNotesManager* getArchivedNotesManager() const { return archivedNotesManager; }
        DeletedNotesManager* getDeletedNotesManage() const { return deletedNotesManager; }
        RelationManager* getRelationManager() const {return relationManager;}
        XMLManager* getXMLManager() const { return xmlManager; }
        Note* getNoteByID(QString);
        Relation* getRelationByID(QString);
        Couple* getCoupleByID(QString,Relation*);
        Version* getNoteVersionByID(QString,QString);

        void reloadFromDatabase();
        static void debug(QString);
};

#endif // P_CORE

