#ifndef V_COUPLEFORM_H
#define V_COUPLEFORM_H

#include <QDialog>
#include "v_mainwindow.h"

namespace Ui {
class v_coupleform;
}

class V_Mainwindow;
class Relation;

class V_CoupleForm : public QDialog
{
    Q_OBJECT

public:
    explicit V_CoupleForm(Relation *relation = 0, QWidget *parent = 0, V_Mainwindow *c = 0);
    Ui::v_coupleform *getUi() const { return ui; }
    ~V_CoupleForm();

private:
    Ui::v_coupleform *ui;
    V_Mainwindow *parent;
    Relation* r;

public slots:
    void checkFields();
};

#endif // V_COUPLEFORM_H
