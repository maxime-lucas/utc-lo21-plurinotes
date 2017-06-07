#include "main.h"
#include "models/p_core.h"
#include "views/mainwindow.h"
#include "views/v_article.h"

int main(int argc, char *argv[]) {

    QApplication app(argc,argv);

    //PluriNotes plurinotes;
    MainWindow mainWindow;
    mainWindow.show();

    mainWindow.getActiveNotes()->addItem(new QListWidgetItem("Hello 1",mainWindow.getActiveNotes()));
    mainWindow.getActiveNotes()->addItem(new QListWidgetItem("Hello 2",mainWindow.getActiveNotes()));
    mainWindow.getActiveNotes()->addItem(new QListWidgetItem("Hello 3",mainWindow.getActiveNotes()));
    mainWindow.getActiveNotes()->addItem(new QListWidgetItem("Hello 4",mainWindow.getActiveNotes()));

    Article& a= new Article();
    v_article fenetre(a);
    fenetre.show();

    return app.exec();
}
