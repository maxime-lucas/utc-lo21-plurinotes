#include "main.h"
#include "models/p_core.h"
#include "views/mainwindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc,argv);

    //PluriNotes plurinotes;
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
