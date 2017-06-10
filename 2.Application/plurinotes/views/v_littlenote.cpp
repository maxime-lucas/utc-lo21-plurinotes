
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

V_Littletask::V_Littletask(QWidget *p, QString t, QString d,unsigned int pri) : QPushButton(p) {
    setFixedSize(80,80);
    layout = new QVBoxLayout;
    setLayout(layout);

    labelTitle = new QLabel(t);
    labelTitle->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    QFont font;
    font.setPixelSize(20);
    labelTitle->setFont(font);

    labelDate = new QLabel(d);

    labelDate->setAlignment(Qt::AlignCenter);

    font.setPixelSize(7);
    font.setItalic(true);
    labelDate->setFont(font);

    QString conv = QString::number(pri);

    labelPriority = new QLabel(conv);

    labelPriority->setAlignment(Qt::AlignCenter);

    font.setPixelSize(10);
    font.setItalic(true);
    labelPriority->setFont(font);

    layout->addWidget(labelTitle);
    layout->addWidget(labelDate);
    layout->addWidget(labelPriority);
}
