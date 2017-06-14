#ifndef V_MULTIPLERELATION_H
#define V_MULTIPLERELATION_H

#include <QWidget>

namespace Ui {
    class v_multiplerelation;
}

class V_Multiplerelation : public QWidget {

    Q_OBJECT

public:
    explicit V_Multiplerelation(QWidget *parent =0);
    ~V_Multiplerelation();

    Ui::v_multiplerelation* getUi() const { return ui; }

private:
    Ui::v_multiplerelation *ui;

};

#endif // V_MULTIPLERELATION_H
