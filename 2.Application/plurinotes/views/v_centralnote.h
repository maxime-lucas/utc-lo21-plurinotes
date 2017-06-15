#ifndef V_CENTRALNOTE_H
#define V_CENTRALNOTE_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QFormLayout>
#include "models/p_notes.h"
#include "views/v_mainwindow.h"

namespace Ui {
    class V_CentralNote;
}

/*!
   \class V_CentralNote
 * \brief Cette Class permet l'affichage du form destiné à afficher une note.
 */
class V_CentralNote : public QWidget {

    Q_OBJECT

    public:
        explicit V_CentralNote(QWidget *parent = 0,V_Mainwindow *m = 0);
        Ui::V_CentralNote* getUi() const { return ui; }
        V_Mainwindow* getMainwindow() const { return parentView; }
        virtual ~V_CentralNote() = 0;

    protected:
        Ui::V_CentralNote *ui;
        V_Mainwindow *parentView;

    public slots:
        /*!
         * \brief deleteNote
         * Slot qui va appeler la fonction du contrôler pour supprimer une note.
         */
        void deleteNote();
        /*!
         * \brief editNote
         * Slot qui va déterminer la nature de la note affichée et appeler la bonne fonction d'édition en conséquence.
         */
        void editNote();

};

/*!
 * \class V_CentralArticle
 * \brief Class permettant l'affichage d'une note du type article.
 */
class V_CentralArticle : public V_CentralNote {

    Q_OBJECT

public:
    V_CentralArticle(Article*,V_Mainwindow*);
    ~V_CentralArticle();
    /*!
     * \brief editArticle
     *  Fonction chargée de récupérer les nouvelles données et de les envoyer au contrôler pour une édition de cette note.
     */
    void editArticle();

private:
    QPlainTextEdit* text;


};

/*!
 * \class V_CentralMultimedia
 * \brief Class permettant l'affichage d'une note du type multimedia.
 */

class V_CentralMultimedia : public V_CentralNote {

    Q_OBJECT

public:
    V_CentralMultimedia(Multimedia*,V_Mainwindow*);
    ~V_CentralMultimedia();
    /*!
     * \brief editArticle
     *  Fonction chargée de récupérer les nouvelles données et de les envoyer au contrôler pour une édition de cette note.
     */
    void editMultimedia();
private:
    QTextEdit *desc;
    TypeMultimedia type;
    QString pathToFile;


};

/*!
 * \class V_CentralTask
 * \brief Class permettant l'affichage d'une note du type task.
 */

class V_CentralTask : public V_CentralNote {

    Q_OBJECT

    public:
    V_CentralTask(Task*,V_Mainwindow*);
    ~V_CentralTask();
    /*!
     * \brief editArticle
     *  Fonction chargée de récupérer les nouvelles données et de les envoyer au contrôler pour une édition de cette note.
     */
    void editTask();

private:
    QLineEdit* action;
    QDateTimeEdit* deadline;
    QRadioButton* prog;
    QRadioButton* pend;
    QRadioButton* fini;
    QSpinBox* priority;

};

#endif // V_CENTRALNOTE_H
