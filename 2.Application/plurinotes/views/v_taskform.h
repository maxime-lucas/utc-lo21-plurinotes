#ifndef V_TASKFORM_H
#define V_TASKFORM_H

#include <QTimeEdit>
#include <QDialog>
#include "v_mainwindow.h"

namespace Ui {
    class V_TaskForm;
}

class V_Mainwindow;
/*!
 * \class V_TaskForm
 * \brief class responsable de l'affichage du formulaire de création d'une tache.
 */
class V_TaskForm : public QDialog
{
    Q_OBJECT

public:
    explicit V_TaskForm(QWidget *parent = 0, V_Mainwindow *c = 0);
    Ui::V_TaskForm *getUi() const {return ui;}
    ~V_TaskForm();

private:
    Ui::V_TaskForm *ui;
    V_Mainwindow * parent;

public slots:
    /*!
     * \brief checkFields
     * Slot qui permet une vérification des paramètres entrés et qui appelle la fonction du controler pour creer une nouvelle tache
     */
    void checkFields();
};

#endif // V_TASKFORM_H
