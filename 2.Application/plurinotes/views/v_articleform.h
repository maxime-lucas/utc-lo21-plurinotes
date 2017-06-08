#ifndef V_ARTICLEFORM_H
#define V_ARTICLEFORM_H

#include <QDialog>
#include "v_mainwindow.h"

namespace Ui {
class V_ArticleForm;
}

class V_Mainwindow;

class V_ArticleForm : public QDialog
{
    Q_OBJECT

public:
    explicit V_ArticleForm(QWidget *parent = 0, V_Mainwindow *c = 0);
    Ui::V_ArticleForm *getUi() const { return ui; }
    ~V_ArticleForm();

private:
    Ui::V_ArticleForm *ui;
    V_Mainwindow *parent;

public slots:
    void checkFields();
};

#endif // V_ARTICLEFORM_H
