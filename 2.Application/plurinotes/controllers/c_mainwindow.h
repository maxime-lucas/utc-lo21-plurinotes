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

        void saveNewArticle(Article*);
        void saveNewMultimedia(Multimedia*);
        void saveNewTask(Task*);
        void saveNewRelation(Relation*);
        void addCouple(Couple*,QString);

        void editArticle(QString,Article*);
        void editMultimedia(QString,Multimedia*);
        void editTask(QString,Task*);
        void editRelation(Relation*);
        void editCouple(Couple*,QString);

        void restoreNoteVersion(QString,QString);
        void deleteNoteVersion(QString,QString);

        void deleteByID(QString);
};

#endif // C_MAINWINDOW

