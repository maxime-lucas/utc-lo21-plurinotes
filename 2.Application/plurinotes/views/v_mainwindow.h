#ifndef V_MAINWINDOW_H
#define V_MAINWINDOW_H

#include "v_articleform.h"
#include "main.h"
#include "v_multiplenotes.h"
#include "v_centralnote.h"
#include "../controllers/c_mainwindow.h"

namespace Ui {
class V_Mainwindow;
}

class C_Mainwindow;
class V_ArticleForm;

class V_Mainwindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit V_Mainwindow(QWidget *parent = 0, C_Mainwindow *c = 0);
        ~V_Mainwindow();

        // Getters
        Ui::V_Mainwindow* getUi() const { return ui; }
        V_Multiplenotes *getActiveNotes() const { return activeNotes; }
        V_Multiplenotes *getTasks() const { return tasks; }
        V_Multiplenotes *getArchivedNotes() const { return archivedNotes; }
        V_ArticleForm* getFormArticle() const { return articleForm; }
        C_Mainwindow* getController() const { return controller; }

    private:
        Ui::V_Mainwindow *ui;
        QHBoxLayout* centralLayout;
        QVBoxLayout* leftLayout;
        QWidget* leftWidget;

        QLabel* labelActiveNotes;
        QLabel* labelTasks;
        QLabel* labelArchivedNotes;

        V_Multiplenotes *activeNotes;
        V_Multiplenotes *tasks;
        V_Multiplenotes *archivedNotes;

        V_ArticleForm* articleForm;
        QWidget *centralNote;

        C_Mainwindow *controller;

        void createActions();

    public slots:
        void openNewArticle();
        void refreshCentralNote(QString);
};

#endif // V_MAINWINDOW_H
