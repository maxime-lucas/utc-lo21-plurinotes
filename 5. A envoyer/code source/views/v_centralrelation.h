#ifndef V_CENTRALRELATION_H
#define V_CENTRALRELATION_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include "models/p_relations.h"
#include "views/v_mainrelation.h"

class V_MainView;

namespace Ui {
    class V_CentralRelation;
}

/*!
   \class V_CentralView
 * \brief Cette Class permet l'affichage du form destiné à afficher une Relation ou un Couple.
 */

class V_CentralView : public QWidget {

    Q_OBJECT

    private:
        Ui::V_CentralRelation *ui;
        V_MainView *parentView;
        bool relationView;

    public:
        explicit V_CentralView(QWidget *parent = 0,V_MainView *m = 0);
        Ui::V_CentralRelation* getUi() const { return ui; }
        V_MainView* getMainwindow() const { return parentView; }
        /*!
         * \brief isRelationView
         * \return Renvoie true si on affiche une relation.
         */
        bool isRelationView() const { return relationView; }
        /*!
         * \brief setIsRelationView
         * \param v
         *  Permets l'édition du champ booléen pour déterminer si on affiche une relation ou un couple.
         */
        void setIsRelationView(bool v) {relationView = v; }

        virtual ~V_CentralView() = 0;

    public slots:
        /*!
         * \brief deleteView
         * Slot qui va déterminer la nature de la relation/couple affiché(e) et appeler la bonne fonction de supression en conséquence.
         */
        void deleteView();
        /*!
         * \brief editView
         * Slot qui va déterminer la nature de la relation/couple affiché(e) et appeler la bonne fonction d'édition en conséquence.
         */
        void editView();

};

/*!
 * \class V_Centralrelation
 * \brief Class permettant l'affichage d'une relation.
 */

class V_Centralrelation : public V_CentralView {

    Q_OBJECT

public:
    V_Centralrelation(Relation*,V_MainView*);
    ~V_Centralrelation();
    /*!
     * \brief editRelation
     *  Fonction chargée de récupérer les nouvelles données et de les envoyer au contrôler pour une édition de cette relation.
     */
    void editRelation();

private:
    QPlainTextEdit* desc;
    QLabel* oriented;
};

/*!
 * \class V_Centralrelation
 * \brief Class permettant l'affichage d'un Couple.
 */

class V_CentralCouple : public V_CentralView {

    Q_OBJECT

public:
    V_CentralCouple(Relation*,Couple*,V_MainView*);
    ~V_CentralCouple();
    /*!
     * \brief editCouple
     *  Fonction chargée de récupérer les nouvelles données et de les envoyer au contrôler pour une édition de ce couple.
     */
    void editCouple();
private:
    QLineEdit* label;
    QLabel* note1;
    QLabel* note2;
    Couple* c;
    Relation* r;

};


#endif // V_CENTRALRELATION_H
