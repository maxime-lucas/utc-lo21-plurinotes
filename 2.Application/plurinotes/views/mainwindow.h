#ifndef MAINWINDOW
#define MAINWINDOW

#include "main.h"

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:
        MainWindow();

    private:
        QMenu* fileMenu;
        QAction* exitAct;

        void createActions();
        void createMenus();
};

#endif // MAINWINDOW

