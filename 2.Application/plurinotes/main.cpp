#include "main.h"

#include <QApplication>

#include "controllers/c_mainwindow.h"


int main(int argc, char *argv[]) {

    QApplication app(argc,argv);
    C_Mainwindow *controller = new C_Mainwindow(&app);
    controller->getView()->show();

    Note *n1 = controller->getApp()->getXMLManager()->getNoteById("1");
    Note *n2 = controller->getApp()->getXMLManager()->getNoteById("2");
    Relation *r1 = new Relation("1","Titre","Desc",TRUE);
    Couple *c1 = new Couple("Label",n1,n2);

    r1->getCouples()->push_back(c1);

    controller->getApp()->getXMLManager()->insertIntoRelation(r1);
    controller->getApp()->getXMLManager()->insertIntoCouple(c1);
    controller->getApp()->getXMLManager()->insertIntoRelationCouple(r1,c1);

    return app.exec();
}
