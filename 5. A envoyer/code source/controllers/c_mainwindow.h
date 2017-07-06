#ifndef C_MAINWINDOW
#define C_MAINWINDOW

/*!
 * \file c_mainwindow.h
 * \brief Header pour le controller principal de l'application
 * \author FAYAX
 * \version 1.0
 */

#include "views/v_mainwindow.h"
#include "models/p_core.h"

class V_Mainwindow;


/*!
 * \class C_Mainwindow
 * \brief Classe représentant le controller principal de l'application
 *
 * Cette classe s'occupe de faire le lien entre le model (ensemble de classes représentant les données du XML et stockées en mémoire) et la view
 */

class C_Mainwindow {

    private:
        QApplication* qapp;
        V_Mainwindow* view; /*!< View */
        PluriNotes* app; /*!< Model*/

    public:
        /*!
         * \brief Constructeur
         *
         * Constructeur de la classe C_Mainwindow
         *
         * \param app : Object QApplication créé dans la fonction main()
         */
        C_Mainwindow(QApplication* app);

        V_Mainwindow* getView() const { return view; }
        PluriNotes* getApp() const { return app; }
        QApplication* getQApp() const { return qapp; }

        void createActions();
        void createMenus();
        void refreshActiveNotes();
        void refreshTask();
        void refreshRelations();
        void refreshCouples();

        /*!
         * \brief Sauvegarde
         */
            /*!
             * Sauvegarde d'un article
             */
        void saveNewArticle(Article*);
            /*!
             * Sauvegarde d'un Multimedia
             */
        void saveNewMultimedia(Multimedia*);
            /*!
             * Sauvegarde d'une tâche
             */
        void saveNewTask(Task*);
            /*!
             * Sauvegarde d'une relation
             */
        void saveNewRelation(Relation*);
            /*!
             * Sauvegarde d'un couple
             */
        void addCouple(Couple*,QString);



        /*!
         * \brief Edition
         */
            /*!
             * Edition d'un article
             */
        void editArticle(QString,Article*);
            /*!
             * Edition d'un multimedia
             */
        void editMultimedia(QString,Multimedia*);
            /*!
             * Edition d'une tâche
             */
        void editTask(QString,Task*);
            /*!
             * Edition d'une relation
             */
        void editRelation(Relation*);
            /*!
             * Edition d'un couple
             */
        void editCouple(Couple*,QString);


            /*!
             * \brief restoreNoteVersion
             * Restaure l'état d'une version en supprimant les versions suivantes grâce à l'Id de la version et le numéro de la version
             */
        void restoreNoteVersion(QString,QString);


        /*!
         * \brief Suppression
         */
            /*!
             * Supprime une version ainsi que les versions suivantes grâce à l'Id de la version et le numéro de la version
             */
        void deleteNoteVersion(QString,QString);
            /*!
             * Supprime une note, peu importe son type, grâce à son Id
             */
        void deleteByID(QString);
            /*!
             * Supprime une relation grâce à son Id
             */
        void deleteRelationByID(QString);
            /*!
             * Supprime un couple grâce à son Id
             */
        void deleteCoupleByID(QString);
};

#endif // C_MAINWINDOW

