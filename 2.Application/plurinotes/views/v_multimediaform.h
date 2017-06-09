#ifndef V_MULTIMEDIAFORM_H
#define V_MULTIMEDIAFORM_H

#include <QDialog>
#include <QFileDialog>
#include "v_mainwindow.h"

namespace Ui {
class V_MultimediaForm;
}

class V_Mainwindow;

class V_MultimediaForm : public QDialog
{
    Q_OBJECT

public:
    explicit V_MultimediaForm(QWidget *parent = 0, V_Mainwindow *c = 0);
    Ui::V_MultimediaForm *getUi() const {return ui;}
    ~V_MultimediaForm();

private:
    Ui::V_MultimediaForm *ui;
    V_Mainwindow *parent;

public slots:
    void checkFields();
    void openFile();
};

#endif // V_MULTIMEDIAFORM_H
