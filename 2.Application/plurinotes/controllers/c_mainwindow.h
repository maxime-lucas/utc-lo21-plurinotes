#ifndef C_MAINWINDOW
#define C_MAINWINDOW

#include "views/v_mainwindow.h"
#include "models/p_core.h"

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

        void createActions();
        void createMenus();
};

#endif // C_MAINWINDOW

