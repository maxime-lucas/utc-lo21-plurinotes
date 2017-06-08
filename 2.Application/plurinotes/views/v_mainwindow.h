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
        // Widget onglet
        QTabWidget* tab;

        // Widget pour faire les onglets
        QWidget* mainView;
        QWidget* secondaryView;

        // Layout
        QHBoxLayout* mainLayout;
        QVBoxLayout* leftLayout;

        // Menu tout en haut
        QMenu* fileMenu;

        // Partie Gauche
        QLabel* activeNotesLabel;
        QListWidget* activeNotes;
        QLabel* taskLabel;
        QListWidget* task;
        QLabel* archivedNotesLabel;
        QListWidget* archivedNotes;

        void createActions();
        void createMenus();
};

#endif // V_MAINWINDOW

