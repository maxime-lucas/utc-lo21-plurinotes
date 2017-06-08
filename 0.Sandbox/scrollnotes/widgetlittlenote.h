#ifndef WIDGETLITTLENOTE
#define WIDGETLITTLENOTE

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

enum eType { article, multimedia, task };

class WidgetLittleNote : public QWidget {

    private :
    QLabel* labelID;
    QLabel* labelType;
    enum eType type;

    public :
    WidgetLittleNote(QString,eType);
    ~WidgetLittleNote();

};

#endif // WIDGETLITTLENOTE

