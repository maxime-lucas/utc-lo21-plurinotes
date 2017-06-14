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

class V_CentralView : public QWidget {

    Q_OBJECT

    public:
        explicit V_CentralView(QWidget *parent = 0,V_MainView *m = 0);
        Ui::V_CentralRelation* getUi() const { return ui; }
        V_MainView* getMainwindow() const { return parentView; }
        bool isRelationView() const { return relationView; }

        void setIsRelationView(bool v) {relationView = v; }

        virtual ~V_CentralView() = 0;

    private:
        Ui::V_CentralRelation *ui;
        V_MainView *parentView;
        bool relationView;

    public slots:
        void deleteView();
        void editView();

};

class V_Centralrelation : public V_CentralView {

    Q_OBJECT

public:
    V_Centralrelation(Relation*,V_MainView*);
    ~V_Centralrelation();
    void editRelation();

private:
    QPlainTextEdit* desc;
    QLabel* oriented;
};

class V_CentralCouple : public V_CentralView {

    Q_OBJECT

public:
    V_CentralCouple(Couple*,V_MainView*);
    ~V_CentralCouple();
    void editCouple();
private:
    QLineEdit* label;
    QLabel* note1;
    QLabel* note2;
    Couple* c;

};


#endif // V_CENTRALRELATION_H
