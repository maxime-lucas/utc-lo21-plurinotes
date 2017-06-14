#ifndef V_MAINWINDOW_H
#define V_MAINWINDOW_H

#include "main.h"

#include <QMainWindow>
#include <QLabel>
#include <QListWidget>

#include "v_articleform.h"
#include "v_multimediaform.h"
#include "v_taskform.h"
#include "v_relationform.h"
#include "v_coupleform.h"
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
class V_RelationForm;
class V_CoupleForm;
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
        V_RelationForm* getFormRelation() const {return relationForm;}
        V_TaskForm* getFormTask() const{return taskForm;}
        V_CoupleForm* getFormCouple() const{return coupleForm;}
        C_Mainwindow* getController() const { return controller; }
        QListWidget* getVersions() const { return versions; }
        void init();

    private:
        Ui::V_Mainwindow *ui;
        C_Mainwindow *controller;

        // LAYOUTS AND WIDGETS

        QHBoxLayout* centralMainLayout; // MAIN VIEW (tab-1)
        QVBoxLayout* centralSecondLayout; // RELATIONS VIEW (tab-2)
        QVBoxLayout* leftLayout; // TO BUILD THE LEFT WIDGET (activeNotes,Tasks,....)
        QVBoxLayout* rightLayout; // TO BUILD THE RIGHT WIDGET (Asc & Desc)
        QVBoxLayout* bottomLayout; // TO BUILD THE BOTTOM WIDGET (Versions for each note)
        QVBoxLayout* middleLayout; // TO BUILD THE MIDDLE WIDGET = CENTRAL NOTE + VERSIONS
        QVBoxLayout *centralNoteLayout; // TO BUILD THE CENTRAL NOTE

        QWidget* leftWidget; // (SEE ABOVE)
        QWidget* rightWidget; // (SEE ABOVE)
        QWidget* bottomWidget; // (SEE ABOVE)
        QWidget* middleWidget; // (SEE ABOVE)
        QWidget *centralNote; // (SEE ABOVE)

        // ALL FOR LEFT WIDGET

        QLabel* labelActiveNotes;
        QLabel* labelTasks;
        QLabel* labelArchivedNotes;

        V_Multiplenotes *activeNotes;
        V_Multiplenotes *tasks;
        V_Multiplenotes *archivedNotes;

        // ALL FOR RIGHT WIDGET

        V_Multiplerelation *relation;

        // ALL FOR BOTTOM WIDGET

        QLabel* labelVersions;
        QListWidget* versions;

        // ALL FOR FORM PROMPTS

        V_ArticleForm* articleForm;
        V_MultimediaForm* multimediaForm;
        V_TaskForm* taskForm;

        V_RelationForm* relationForm;
        V_CoupleForm* coupleForm;

        // ALL FOR RELATIONS VIEWS

        V_MainView* relationView;

    public slots:
        void openNewArticle();
        void openNewMultimedia();
        void openNewTask();
        void openNewRelation();
        void openNewCouple();
        void refreshCentralNote(QString);
        void refreshVersions(QString);
        void setEmptyCentralNote();
        void toggleAscDescView();
        void toggleRelationsView();
        void restoreVersion(QListWidgetItem*);
};

#endif // V_MAINWINDOW_H
