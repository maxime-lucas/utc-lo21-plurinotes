#ifndef V_LITTLENOTE
#define V_LITTLENOTE

#endif // V_LITTLENOTE

#include "main.h"

#include <QPushButton>
#include <QLabel>
#include <QLayout>

/*!
 * \clas V_Littlenote
 * \brief class responsable de l'affichage du bouton représentant les notes dans le menu de gauche.
 */
class V_Littlenote : public QPushButton {

        private:
        QLabel* labelType;
        QLabel* labelID;

        QVBoxLayout* layout;

        public:
        V_Littlenote(QWidget*p=0,QString = "",enum eTypeNote =article);
};

/*!
 * \clas V_Littletask
 * \brief class responsable de l'affichage du bouton représentant les taches dans le menu de gauche.
 */
class V_Littletask : public QPushButton {
private:
    QLabel* labelTitle;
    QLabel* labelDate;
    QLabel* labelPriority;

    QVBoxLayout* layout;

public:
    V_Littletask(QWidget* p=0 ,QString = "", QString = "", unsigned int = 0);
};
