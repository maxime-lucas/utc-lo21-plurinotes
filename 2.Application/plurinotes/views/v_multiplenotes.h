#ifndef V_MULTIPLENOTES_H
#define V_MULTIPLENOTES_H

#include <QWidget>
#include <QGridLayout>

namespace Ui {
    class v_multiplenotes;
}
/*!
 * \class V_Multiplenotes
 * \brief class gérant l'affichage des différentes littlenote
 * Fait appel a v_multiplenotes.ui
 */
class V_Multiplenotes : public QWidget
{
    Q_OBJECT

public:
    explicit V_Multiplenotes(QWidget *parent = 0);
    ~V_Multiplenotes();
    Ui::v_multiplenotes* getUi() const { return ui; }
    QWidget* getContainer() const { return container; }
    QGridLayout *getGridLayout() const { return gridLayout; }
    void setGridLayout(QGridLayout *g) { gridLayout = g; }

private:
    Ui::v_multiplenotes *ui;
    QWidget *container;
    QGridLayout *gridLayout;
};

#endif // V_MULTIPLENOTES_H
