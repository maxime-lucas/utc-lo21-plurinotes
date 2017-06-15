#include "main.h"

#include <QApplication>

#include "controllers/c_mainwindow.h"


int main(int argc, char *argv[]) {

    QApplication app(argc,argv);
    C_Mainwindow *controller = new C_Mainwindow(&app);

    // controller->getView()->show();

    // TESTS
    Note *n1 = controller->getApp()->getXMLManager()->getNoteById("1");
    Note *n2 = controller->getApp()->getXMLManager()->getNoteById("2");
    Couple *c1 = new Couple("HELLO BOYS",n1,n2);
    controller->getApp()->getXMLManager()->insertIntoCouple(c1);

    return app.exec();
}
