#include "main.h"

#include <QApplication>

#include "controllers/c_mainwindow.h"


int main(int argc, char *argv[]) {

    QApplication app(argc,argv);
    C_Mainwindow *controller = new C_Mainwindow(&app);

    //controller->getView()->show();

    Couple *c1 = controller->getApp()->getXMLManager()->getCoupleById("1/2");

    PluriNotes::debug(c1->toString());

    return app.exec();
}
