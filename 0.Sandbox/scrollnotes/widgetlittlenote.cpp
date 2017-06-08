#include "widgetlittlenote.h"

WidgetLittleNote::WidgetLittleNote(QString l, enum eType t) : QWidget() {

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

}

WidgetLittleNote::~WidgetLittleNote(){}
