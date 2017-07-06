#ifndef V_MULTIMEDIAFORM_H
#define V_MULTIMEDIAFORM_H

#include <QDialog>
#include <QFileDialog>
#include "v_mainwindow.h"

namespace Ui {
class V_MultimediaForm;
}

/*!
 * \class V_ArticleForm
 * \brief class responsable de l'affichage du formulaire de création d'un Multimedia.
 */

class V_Mainwindow;

class V_MultimediaForm : public QDialog
{
    Q_OBJECT

public:
    explicit V_MultimediaForm(QWidget *parent = 0, V_Mainwindow *c = 0);
    Ui::V_MultimediaForm *getUi() const {return ui;}
    ~V_MultimediaForm();

private:
    Ui::V_MultimediaForm *ui;
    V_Mainwindow *parent;

public slots:
    /*!
     * \brief checkFields
     * Slot qui permet une vérification des paramètres entrés et qui appelle la fonction du controler pour creer d'une nouvelle note Multimedia.
     */
    void checkFields();
    /*!
     * \brief openFile
     * Slot permetant d'ouvrir l'interface d'ajout de fichier.
     */
    void openFile();
};

#endif // V_MULTIMEDIAFORM_H
