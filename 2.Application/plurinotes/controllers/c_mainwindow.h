#ifndef C_MAINWINDOW
#define C_MAINWINDOW

#include "views/v_mainwindow.h"
#include "models/p_core.h"

class V_Mainwindow;

class C_Mainwindow {

    private:
        QApplication* qapp;
        V_Mainwindow* view; // view
        PluriNotes* app; // model

        QAction* newAct;
        QAction* exitAct;

    public:
        C_Mainwindow(QApplication*);

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

        void deleteByID(QString);
};

#endif // C_MAINWINDOW

