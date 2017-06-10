#ifndef V_CENTRALNOTE_H
#define V_CENTRALNOTE_H

#include <QWidget>
#include "models/p_notes.h"

namespace Ui {
    class V_CentralNote;
}

class V_CentralNote : public QWidget {
    Q_OBJECT

    public:
        explicit V_CentralNote(QWidget *parent = 0);
        Ui::V_CentralNote* getUi() const { return ui; }
        virtual ~V_CentralNote() = 0;

    private:
        Ui::V_CentralNote *ui;
};

class V_CentralArticle : public V_CentralNote {
    public:
    V_CentralArticle(Article*);
    ~V_CentralArticle();
};

class V_CentralMultimedia : public V_CentralNote {
    public:
    V_CentralMultimedia(Multimedia*);
    ~V_CentralMultimedia();
};

#endif // V_CENTRALNOTE_H
