#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QPushButton>
#include "widgetlittlenote.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QScrollArea *frame = new QScrollArea();
    frame->setFixedSize(500, 200);
    QWidget *contenu = new QWidget;
    QVBoxLayout *mLayout = new QVBoxLayout();
    contenu->setLayout(mLayout);
    enum eType type;

    for(int i = 0 ; i < 4 ; i++)
    {
        QHBoxLayout *layout = new QHBoxLayout();
        mLayout->addLayout(layout);

        for(int j = 0 ; j < 3 ; j++)
        {
            if(j == 0) type = article;
            else if(j == 1) type = multimedia;
            else type = task;

            layout->addWidget(new WidgetLittleNote("1",type));
        }
    }
    // Si tu essayes d'appeler setWidget avant que les boutons
    // soient ajoutés, rien ne s'affiche
    // (voir doc de QScrollArea::setWidget)
    frame->setWidget(contenu);
    frame->setWidget(contenu);

    frame->show();

    return app.exec();
}
