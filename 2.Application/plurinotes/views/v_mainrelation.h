#ifndef V_MAINRELATION_H
#define V_MAINRELATION_H

#include <QWidget>

namespace Ui {
    class v_mainrelation;
}

class V_MainRelation : public QWidget {

    Q_OBJECT

public:
    explicit V_MainRelation(QWidget *parent = 0);
    ~V_MainRelation();

    Ui::v_mainrelation* getUi() const {return ui;}

private:
    Ui::v_mainrelation* ui;
};


#endif // V_MAINRELATION_H
