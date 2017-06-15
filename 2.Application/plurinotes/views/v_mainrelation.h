#ifndef V_MAINRELATION_H
#define V_MAINRELATION_H

#include "main.h"
#include "v_centralrelation.h"
#include <QLayoutItem>
#include <QListWidget>
#include "../controllers/c_mainwindow.h"

class C_Mainwindow;

namespace Ui {
    class v_mainrelation;
}

class V_MainView : public QWidget {

    Q_OBJECT

public:
    explicit V_MainView(QWidget *parent = 0, C_Mainwindow *c = 0);
    ~V_MainView();

    C_Mainwindow* getController() const {return controller;}
    Ui::v_mainrelation* getUi() const {return ui;}

    void setEmptyCentralView();
    void refreshCentralRelation(QString);
    void refreshCentralCouple(QString);
    void refreshRelation();
    void refreshListCouple(QString);

private:
    Ui::v_mainrelation* ui;
    C_Mainwindow* controller;
    QWidget* centralView;
    QHBoxLayout* centralRLayout;
    QVBoxLayout* leftLayout;
    QWidget* leftWidget;


public slots:
    void refreshCouple(QListWidgetItem*);
    void afficheCouple(QListWidgetItem*);
};


#endif // V_MAINRELATION_H
