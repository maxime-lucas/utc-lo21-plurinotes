#ifndef V_CENTRALNOTE_H
#define V_CENTRALNOTE_H

#include <QWidget>
#include <QPlainTextEdit>
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
        V_Mainwindow* getMainwindow() const { return parentView; }
        virtual ~V_CentralNote() = 0;

    private:
        Ui::V_CentralNote *ui;
        V_Mainwindow *parentView;

    public slots:
        void deleteNote();

};

class V_CentralArticle : public V_CentralNote {

    Q_OBJECT

public:
    V_CentralArticle(Article*,V_Mainwindow*);
    ~V_CentralArticle();

private:
    QPlainTextEdit *text;

public slots:
    void editArticle();
};

class V_CentralMultimedia : public V_CentralNote {

    Q_OBJECT

public:
    V_CentralMultimedia(Multimedia*,V_Mainwindow*);
    ~V_CentralMultimedia();
private:
    QPlainTextEdit *desc;

public slots:
    void editMultimedia(Multimedia*);
};

class V_CentralTask : public V_CentralNote {

    Q_OBJECT

    public:
    V_CentralTask(Task*,V_Mainwindow*);
    ~V_CentralTask();


};

#endif // V_CENTRALNOTE_H
