#ifndef V_CENTRALNOTE_H
#define V_CENTRALNOTE_H

#include <QWidget>
#include <QPlainTextEdit>
#include "models/p_notes.h"
#include "models/p_versions.h"
#include "views/v_mainwindow.h"

namespace Ui {
    class V_CentralNote;
}

class V_CentralNote : public QWidget {
    Q_OBJECT
    public:
        explicit V_CentralNote(QWidget *parent = 0, V_Mainwindow *m = 0);
        Ui::V_CentralNote* getUi() const { return ui; }
        V_Mainwindow* getMainwindow() const { return par;}
        virtual ~V_CentralNote() = 0;

    private:
        Ui::V_CentralNote *ui;
        V_Mainwindow* par;
};

class V_CentralArticle : public V_CentralNote {    
private:
    QPlainTextEdit* textText;
public:
    V_CentralArticle(Article*);
    ~V_CentralArticle();

    QPlainTextEdit* getText() const {return textText;}

public slots:
    void editArticle();
    void clearModif();
};

class V_CentralMultimedia : public V_CentralNote {
    public:
    V_CentralMultimedia(Multimedia*);
    ~V_CentralMultimedia();
};

#endif // V_CENTRALNOTE_H
