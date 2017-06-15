
#ifndef P_XML
#define P_XML

#include "main.h"

#include <QDomDocument>
#include <QWidget>
#include <QFile>

#include "p_notes.h"
#include "p_relations.h"



/*!
 * \class XMLManager
 * \brief cette classe gère les fonctions liées à l'utilisation de notre base de donnée en XML
 *
 * La classe contient l'ensemble des fonctions permettant les modifications de la BDD mais aussi les fonctions utilitaires sur les autres classes comme la récupération d'un couple par son id
 */
class XMLManager : public QWidget {
    private:
    QDomDocument *dom;
    QFile doc;
    QString pathToFile;

    public:
    XMLManager(const QString &);
    ~XMLManager();
    void resetDocument();

    std::vector<Article*> getAllActiveArticles() const;
    std::vector<Multimedia*> getAllActiveMultimedia() const;
    std::vector<Task*> getAllActiveTasks() const;
    Couple* getCoupleById(QString) const;
    Note* getNoteById(QString) const;
    Relation* getRelationByID(QString) const;
    std::vector<Relation*>getAllRelations() const;
    unsigned int getLastId() const;
    unsigned int getLastRelationId() const;
    bool isCoupleInRelation(Relation*,Couple*) const;

    /*!
     * \brief Insertions
     */
        /*!
         * Insertion d'un article
         */
    void insertIntoArticle(Article*);  
        /*!
         * Insertion d'une tâche
         */
    void insertIntoTask(Task*t);
        /*!
         * Insertion d'un multimédia
         */
    void insertIntoMultimedia(Multimedia*);
        /*!
         * Insertion d'une relation
         */
    void insertIntoRelation(Relation*);    
        /*!
         * Insertion d'un couple
         */
    void insertIntoCouple(Couple*);
        /*!
         * Insertion d'un couple dans une relation
         */
    void insertIntoRelationCouple(Relation*,Couple*);



    /*!
     * \brief Suppression
     */
        /*!
         * Suppression d'un article
         */
    void deleteFromArticle(Article*);
        /*!
         * Suppression d'un multimédia
         */
    void deleteFromMultimedia(Multimedia*);
        /*!
         * Suppression d'une tâche
         */
    void deleteFromTask(Task*t);
        /*!
         * Suppression d'un couple
         */
    void deleteFromCouple(Couple*c);


    /*!
     * \brief Mise à jour
     */
        /*!
         * MAJ d'un article
         */
    void updateArticle(Article*,Article*);
        /*!
         * MAJ d'un multimédia
         */
    void updateMultimedia(Multimedia*,Multimedia*);
        /*!
         * MAJ d'une tâche
         */
    void updateTask(Task*,Task*);
        /*!
         * MAJ du label d'un couple en fonction de son ID
         */
    void updateCoupleLabelById(QString,QString);


        /*!
         * Suppression de la version d'une note
         */
    void deleteNoteVersion(Note*,Version*);
        /*!
         * Restauration de la version d'une Note
         */
    void restoreNoteVersion(Note*,Version*);

        /*!
         * Suppression d'un couple
         */
    void deleteCouple(Relation*r,Couple*c);        
        /*!
         * Suppression d'une relation
         */
    void deleteRelation(Relation*r);
};

#endif // P_XML

