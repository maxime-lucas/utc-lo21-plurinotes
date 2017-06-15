/*!
 *  \file main.cpp
 *  \brief Lancement de l'application
 *  \author FAYAX
 *  \version 1.0
 */
#include "main.h"
#include <QApplication>
#include "controllers/c_mainwindow.h"

/*!
 *  \fn int main(int argc, char *argv[])
 *  \brief Point d'entrée du programme
 */
int main(int argc, char *argv[]) {

    QApplication app(argc,argv);

    C_Mainwindow *controller = new C_Mainwindow(&app);
    controller->getView()->show();

    return app.exec();
}
