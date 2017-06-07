#include "main.h"
#include "controllers/c_mainwindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc,argv);

    C_Mainwindow *controller = new C_Mainwindow(&app);

    //controller->getView()->show();

    return app.exec();
}
