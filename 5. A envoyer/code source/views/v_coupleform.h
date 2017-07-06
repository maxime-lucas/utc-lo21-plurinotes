#ifndef V_COUPLEFORM_H
#define V_COUPLEFORM_H

#include <QDialog>
#include "v_mainwindow.h"

namespace Ui {
class v_coupleform;
}

class V_Mainwindow;
class Relation;

/*!
 * \class V_ArticleForm
 * \brief class responsable de l'affichage du formulaire de création d'un couple.
 */

class V_CoupleForm : public QDialog
{
    Q_OBJECT

public:
    explicit V_CoupleForm(Relation *relation = 0, QWidget *parent = 0, V_Mainwindow *c = 0);
    Ui::v_coupleform *getUi() const { return ui; }
    ~V_CoupleForm();

private:
    Ui::v_coupleform *ui;
    V_Mainwindow *parent;
    Relation* r;

public slots:
    /*!
     * \brief checkFields
     * Slot qui permet une vérification des paramètres entrés et qui appelle la fonction du controler pour creer un nouveau couple
     */
    void checkFields();
};

#endif // V_COUPLEFORM_H
