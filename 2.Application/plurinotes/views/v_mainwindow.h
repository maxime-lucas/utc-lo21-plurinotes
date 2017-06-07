#ifndef V_MAINWINDOW
#define V_MAINWINDOW

#include "main.h"

class V_Mainwindow : public QMainWindow {

    Q_OBJECT

    public:
        V_Mainwindow();

        QListWidget* getActiveNotes() const { return activeNotes; }
        QMenu* getFileMenu() const { return fileMenu; }

    private:
        QTabWidget* tab;

        QWidget* mainView;
        QWidget* secondaryView;

        QHBoxLayout* mainLayout;
        QVBoxLayout* leftLayout;

        QMenu* fileMenu;

        QListWidget* activeNotes;
        QListWidget* task;
        QListWidget* archivedNotes;

        void createActions();
        void createMenus();
};

#endif // V_MAINWINDOW

