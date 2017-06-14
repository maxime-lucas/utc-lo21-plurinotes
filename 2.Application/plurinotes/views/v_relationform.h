#ifndef V_RELATIONFORM_H
#define V_RELATIONFORM_H

#include <QDialog>
#include "v_mainwindow.h"

namespace Ui {
class v_relationform;
}

class V_Mainwindow;

class V_RelationForm : public QDialog
{
    Q_OBJECT

public:
    explicit V_RelationForm(QWidget *parent = 0, V_Mainwindow *c = 0);
    Ui::v_relationform *getUi() const { return ui; }
    ~V_RelationForm();

private:
    Ui::v_relationform *ui;
    V_Mainwindow *parent;

public slots:
    void checkFields();
};

#endif // V_RELATIONFORM_H
