#include "main.h"
#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow() {
    setFixedSize(1366,768);
    setWindowTitle("PluriNotes - FAYA / YAYA / MAX");

    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();
}

void MainWindow::createActions()
{
    exitAct = new QAction(tr("&Quit"), this);
    //exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Quit the app"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()) );
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAct);
}
