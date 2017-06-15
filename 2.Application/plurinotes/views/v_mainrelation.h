#ifndef V_MAINRELATION_H
#define V_MAINRELATION_H

#include "main.h"
#include "v_centralrelation.h"
#include <QLayoutItem>
#include <QListWidget>
#include "../controllers/c_mainwindow.h"

class C_Mainwindow;

namespace Ui {
    class v_mainrelation;
}

/*!
 * \class V_MainView
 * \brief class responsable de la vue secondaire gérant les notes a partir d'un form.
 */

class V_MainView : public QWidget {

    Q_OBJECT

public:
    explicit V_MainView(QWidget *parent = 0, C_Mainwindow *c = 0);
    ~V_MainView();

    C_Mainwindow* getController() const {return controller;}
    Ui::v_mainrelation* getUi() const {return ui;}
    /*!
     * \brief setEmptyCentralView
     * Fonction permetant l'initialisation du layout central.
     */
    void setEmptyCentralView();
    /*!
     * \brief refreshRelation
     * Fonction qui va rafraichir la liste des relations sur la gauche.
     */
    void refreshRelation();
    /*!
     * \brief refreshListCouple
     * Fonction qui va rafraichir la liste des couples en fonction de la relation choisie.
     */
    void refreshListCouple(QString);

private:
    Ui::v_mainrelation* ui;
    C_Mainwindow* controller;
    QWidget* centralView;
    QHBoxLayout* centralRLayout;
    QVBoxLayout* leftLayout;
    QWidget* leftWidget;


public slots:
    /*!
     * \brief refreshCouple
     * Slot permettant l'affichage des couples d'une relation lors du clique sur une relation.
     * Permets également l'affichage de la relation en vue centrale.
     */
    void refreshCouple(QListWidgetItem*);
    /*!
     * \brief afficheCouple
     * Slot permettant l'affichage d'un couple en vue centrale lors du clique sur un couple.
     */
    void afficheCouple(QListWidgetItem*);
};


#endif // V_MAINRELATION_H
