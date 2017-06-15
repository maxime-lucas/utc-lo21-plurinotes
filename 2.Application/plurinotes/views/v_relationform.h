#ifndef V_RELATIONFORM_H
#define V_RELATIONFORM_H

#include <QDialog>
#include "v_mainwindow.h"

namespace Ui {
class v_relationform;
}

class V_Mainwindow;
/*!
 * \class V_RelationForm
 * \brief class responsable de l'affichage du formulaire de création d'une relation.
 */

class V_RelationForm : public QDialog
{
    Q_OBJECT

public:
    explicit V_RelationForm(QWidget *parent = 0, V_Mainwindow *c = 0);
    Ui::v_relationform *getUi() const { return ui; }
    ~V_RelationForm();

private:
    Ui::v_relationform *ui;
    V_Mainwindow *parent;

public slots:
    /*!
     * \brief checkFields
     * Slot qui permet une vérification des paramètres entrés et qui appelle la fonction du controler pour creer une nouvelle relation.
     */
    void checkFields();
};

#endif // V_RELATIONFORM_H
