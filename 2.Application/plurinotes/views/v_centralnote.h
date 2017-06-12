#ifndef V_CENTRALNOTE_H
#define V_CENTRALNOTE_H

#include <QWidget>
#include "models/p_notes.h"
#include "views/v_mainwindow.h"

namespace Ui {
    class V_CentralNote;
}

class V_CentralNote : public QWidget {
    Q_OBJECT

    public:
        explicit V_CentralNote(QWidget *parent = 0,V_Mainwindow *m = 0);
        Ui::V_CentralNote* getUi() const { return ui; }
        virtual ~V_CentralNote() = 0;

    public slots:
        void deleteNote();

    private:
        Ui::V_CentralNote *ui;
        V_Mainwindow *parentView;
};

class V_CentralArticle : public V_CentralNote {
    public:
    V_CentralArticle(Article*,V_Mainwindow*);
    ~V_CentralArticle();
};

class V_CentralMultimedia : public V_CentralNote {
    public:
    V_CentralMultimedia(Multimedia*,V_Mainwindow*);
    ~V_CentralMultimedia();
};

class V_CentralTask : public V_CentralNote {
    public:
    V_CentralTask(Task*,V_Mainwindow*);
    ~V_CentralTask();
};

#endif // V_CENTRALNOTE_H
