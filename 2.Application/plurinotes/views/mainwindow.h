#ifndef MAINWINDOW
#define MAINWINDOW

#include "main.h"

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:
        MainWindow();

        QListWidget* getActiveNotes() const { return activeNotes; }

    private:
        QHBoxLayout* mainLayout;
        QVBoxLayout* leftLayout;

        QMenu* fileMenu;

        QListWidget* activeNotes;
        QListWidget* task;
        QListWidget* archivedNotes;

        QAction* exitAct;

        void createActions();
        void createMenus();
};

#endif // MAINWINDOW

