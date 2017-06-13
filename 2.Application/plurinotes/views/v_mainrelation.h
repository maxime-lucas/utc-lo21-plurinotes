#ifndef V_MAINRELATION_H
#define V_MAINRELATION_H

#include <QWidget>
#include <QMessageBox>
#include <QList>
#include <QStringListModel>

#include "../controllers/c_mainwindow.h"

class C_Mainwindow;

namespace Ui {
    class v_mainrelation;
}

class V_MainRelation : public QWidget {

    Q_OBJECT

public:
    explicit V_MainRelation(QWidget *parent = 0, C_Mainwindow *c = 0);
    ~V_MainRelation();

    Ui::v_mainrelation* getUi() const {return ui;}

private:
    Ui::v_mainrelation* ui;
    C_Mainwindow* controller;
    QStringList relations;
    QStringList* couples;

public slots:
    void refreshCouple();
};


#endif // V_MAINRELATION_H
