#ifndef V_MAINWINDOW_H
#define V_MAINWINDOW_H

#include "v_article.h"
#include "main.h"
#include "v_multiplenotes.h"

namespace Ui {
class V_Mainwindow;
}

class V_Mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit V_Mainwindow(QWidget *parent = 0);
    ~V_Mainwindow();
    Ui::V_Mainwindow* getUi() const { return ui; }

    V_Multiplenotes *getActiveNotes() const { return activeNotes; }
    V_Multiplenotes *getTasks() const { return tasks; }
    V_Multiplenotes *getArchivedNotes() const { return archivedNotes; }

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

    void createActions();

public slots:
    void AfficherFormArticle();

};

#endif // V_MAINWINDOW_H
