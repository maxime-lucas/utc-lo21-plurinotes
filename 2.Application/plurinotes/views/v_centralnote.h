#ifndef V_CENTRALNOTE_H
#define V_CENTRALNOTE_H

#include <QWidget>

namespace Ui {
class V_CentralNote;
}

class V_CentralNote : public QWidget
{
    Q_OBJECT

public:
    explicit V_CentralNote(QWidget *parent = 0);
    ~V_CentralNote();

private:
    Ui::V_CentralNote *ui;
};

#endif // V_CENTRALNOTE_H
