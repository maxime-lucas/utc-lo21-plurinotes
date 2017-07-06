

#ifndef P_CORE
#define P_CORE

#include "main.h"
#include "p_notes.h"
#include "p_relations.h"
#include "p_xml.h"



/*!
 * \class Plurinotes
 * \brief Class permettant l'initialisation de l'application notamment de tous les managers.
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

        /*!
         * \brief getNoteByID
         * \return retourne la note identifié par un ID.
         */
        Note* getNoteByID(QString);

        /*!
         * \brief getRelationByID
         * \return Retourne la relation identifé par un ID.
         */
        Relation* getRelationByID(QString);

        /*!
         * \brief getCoupleByID
         * \return retourne le Couple identifié par un ID dans une relation
         */
        Couple* getCoupleByID(QString,Relation*);

        /*!
         * \brief getNoteVersionByID
         * \return retourne une version d'une Note en fonction de l'ID de la note et du numero de la version
         */
        Version* getNoteVersionByID(QString,QString);

        /*!
         * \brief reloadFromDatabase
         * Cette fonction permet de recuperer les données enregistré dans l'XML
         */
        void reloadFromDatabase();

        static void debug(QString);
};

#endif // P_CORE

