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
        void saveNewArticle(Article*);
        void saveNewMultimedia(Multimedia*);
};

#endif // C_MAINWINDOW

