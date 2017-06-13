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
    //QWidget* getContainer() const { return container; }
    //QGridLayout *getGridLayout() const { return gridLayout; }
    //void setGridLayout(QGridLayout *g) { gridLayout = g; }

private:
    Ui::v_multiplerelation *ui;
    //QWidget *container;
    //QGridLayout *gridLayout;
};

#endif // V_MULTIPLERELATION_H
