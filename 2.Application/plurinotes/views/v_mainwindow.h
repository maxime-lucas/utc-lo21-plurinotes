#ifndef V_MAINWINDOW_H
#define V_MAINWINDOW_H

#include "v_articleform.h"
#include "v_multimediaform.h"
#include "v_taskform.h"
#include "main.h"
#include "v_multiplenotes.h"
#include "v_multiplerelation.h"
#include "v_centralnote.h"
#include "v_mainrelation.h"
#include "../controllers/c_mainwindow.h"

namespace Ui {
class V_Mainwindow;
}

class C_Mainwindow;
class V_ArticleForm;
class V_MultimediaForm;
class V_TaskForm;
class V_Multiplerelation;
class V_MainView;

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
        V_MultimediaForm* getFormMultimedia() const{ return multimediaForm; }
        V_TaskForm* getFormTask() const{return taskForm;}
        C_Mainwindow* getController() const { return controller; }
        void init();

    private:
        Ui::V_Mainwindow *ui;
        QHBoxLayout* centralMainLayout;
        QVBoxLayout* centralSecondLayout;

        QVBoxLayout* leftLayout;
        QVBoxLayout* rightLayout;
        QWidget* leftWidget;
        QWidget* rightWidget;

        QLabel* labelActiveNotes;
        QLabel* labelTasks;
        QLabel* labelArchivedNotes;

        V_Multiplenotes *activeNotes;
        V_Multiplenotes *tasks;
        V_Multiplenotes *archivedNotes;

        V_Multiplerelation *relation;

        V_MainView* relationView;

        V_ArticleForm* articleForm;
        V_MultimediaForm* multimediaForm;
        V_TaskForm* taskForm;
        C_Mainwindow *controller;
        QWidget *centralNote;

        void createActions();

    public slots:
        void openNewArticle();
        void openNewMultimedia();
        void openNewTask();
        void refreshCentralNote(QString);
        void setEmptyCentralNote();
        void toggleAscDescView();
        void toggleRelationsView();
};

#endif // V_MAINWINDOW_H
