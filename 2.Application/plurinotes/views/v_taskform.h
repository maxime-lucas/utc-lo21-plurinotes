#ifndef V_TASKFORM_H
#define V_TASKFORM_H

#include <QTimeEdit>
#include <QDialog>
#include "v_mainwindow.h"

namespace Ui {
    class V_TaskForm;
}

class V_Mainwindow;

class V_TaskForm : public QDialog
{
    Q_OBJECT

public:
    explicit V_TaskForm(QWidget *parent = 0, V_Mainwindow *c = 0);
    Ui::V_TaskForm *getUi() const {return ui;}
    ~V_TaskForm();

private:
    Ui::V_TaskForm *ui;
    V_Mainwindow * parent;

public slots:
    void checkFeilds();
};

#endif // V_TASKFORM_H
