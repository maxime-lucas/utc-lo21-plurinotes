
#include "v_littlenote.h"

V_Littlenote::V_Littlenote(QWidget*p,QString s, enum eTypeNote t ) : QPushButton(p) {
    setFixedSize(80,80);
    layout = new QVBoxLayout;
    setLayout(layout);

    labelID = new QLabel(s);
    labelID->setAlignment(Qt::AlignCenter);

    if( t == article ) {
        labelType = new QLabel("Article");
    } else if (t == multimedia) {
        labelType = new QLabel("Multimedia");
    } else {
        labelType = new QLabel("Task");
    }
    labelType->setAlignment(Qt::AlignCenter);

    QFont font = labelType->font();
    font.setPointSize(8);
    labelType->setFont(font);

    layout->addWidget(labelType);
    layout->addWidget(labelID);
}
