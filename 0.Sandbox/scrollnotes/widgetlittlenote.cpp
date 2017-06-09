#include "widgetlittlenote.h"

WidgetLittleNote::WidgetLittleNote(QString l, enum eType t) : QWidget() {

<<<<<<< HEAD
    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);

    QWidget* centralWidget = new QWidget();
    layout->addWidget(centralWidget);

    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralWidget->setLayout(centralLayout);

    centralWidget->setStyleSheet("border: 2px solid black");

    labelID = new QLabel(l,this);

    if( t == article )
        labelType = new QLabel("Article",this);
    else if( t == multimedia )
        labelType = new QLabel("Multimedia",this);
    else
        labelType = new QLabel("Task",this);
    centralLayout->addWidget(labelType);
    centralLayout->addWidget(labelID);
    this->setFixedSize(100,100);
=======
    // Création des labels
    this->labelID = new QLabel(l);

    if( t == article ) this->labelType = new QLabel("Article");
    else if( t == multimedia ) this->labelType = new QLabel("Multimedia");
    else this->labelType = new QLabel("Task");

    // Création et mise en place du layout
    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);

    // Ajout des widgets au layout
    layout->addWidget(labelType);
    layout->addWidget(labelID);
    layout->setMargin(0);
    layout->setSpacing(0);

    // Mise en forme
    this->setFixedSize(100,100);
    this->setStyleSheet("border:1px solid black;");

    labelID->setStyleSheet("font-size:20px;");
    labelID->setAlignment(Qt::AlignCenter);

    labelType->setAlignment(Qt::AlignCenter);

>>>>>>> max

}

WidgetLittleNote::~WidgetLittleNote(){}
