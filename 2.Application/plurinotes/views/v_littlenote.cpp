
#include "v_littlenote.h"

V_Littlenote::V_Littlenote(QWidget*p,QString s, enum eTypeNote t ) : QPushButton(p) {
    setFixedSize(80,80);
    layout = new QVBoxLayout;
    setLayout(layout);

    labelID = new QLabel(s);
    labelID->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    QFont font;
    font.setPixelSize(32);
    labelID->setFont(font);

    if( t == article ) {
        labelType = new QLabel("Article");
    } else if (t == multimedia) {
        labelType = new QLabel("Multimedia");
    } else {
        labelType = new QLabel("Task");
    }
    labelType->setAlignment(Qt::AlignCenter);

    font.setPixelSize(9);
    font.setItalic(true);
    labelType->setFont(font);

    layout->addWidget(labelType);
    layout->addWidget(labelID);
}
