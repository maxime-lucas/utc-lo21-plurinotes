#ifndef V_LITTLENOTE
#define V_LITTLENOTE

#endif // V_LITTLENOTE

#include "main.h"

class V_Littlenote : public QPushButton {

        private:
        QLabel* labelType;
        QLabel* labelID;

        QVBoxLayout* layout;

        public:
        V_Littlenote(QWidget*p=0,QString = "",enum eTypeNote =article);
};
