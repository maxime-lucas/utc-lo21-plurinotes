/********************************************************************************
** Form generated from reading UI file 'v_mainrelation.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_MAINRELATION_H
#define UI_V_MAINRELATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_v_mainrelation
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *centralLayout;
    QVBoxLayout *relationView;
    QLabel *labelRelation;
    QListView *listeRelation;
    QLabel *labelCouple;
    QListView *listCouple;
    QGridLayout *gridLayout;
    QWidget *formWidget;

    void setupUi(QWidget *v_mainrelation)
    {
        if (v_mainrelation->objectName().isEmpty())
            v_mainrelation->setObjectName(QString::fromUtf8("v_mainrelation"));
        v_mainrelation->resize(800, 600);
        v_mainrelation->setBaseSize(QSize(800, 600));
        v_mainrelation->setLayoutDirection(Qt::LeftToRight);
        horizontalLayoutWidget = new QWidget(v_mainrelation);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 581));
        centralLayout = new QHBoxLayout(horizontalLayoutWidget);
        centralLayout->setObjectName(QString::fromUtf8("centralLayout"));
        centralLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        centralLayout->setContentsMargins(0, 0, 0, 0);
        relationView = new QVBoxLayout();
        relationView->setObjectName(QString::fromUtf8("relationView"));
        relationView->setSizeConstraint(QLayout::SetMinimumSize);
        labelRelation = new QLabel(horizontalLayoutWidget);
        labelRelation->setObjectName(QString::fromUtf8("labelRelation"));

        relationView->addWidget(labelRelation);

        listeRelation = new QListView(horizontalLayoutWidget);
        listeRelation->setObjectName(QString::fromUtf8("listeRelation"));
        listeRelation->setEnabled(true);
        listeRelation->setBaseSize(QSize(20, 200));

        relationView->addWidget(listeRelation);

        labelCouple = new QLabel(horizontalLayoutWidget);
        labelCouple->setObjectName(QString::fromUtf8("labelCouple"));

        relationView->addWidget(labelCouple);

        listCouple = new QListView(horizontalLayoutWidget);
        listCouple->setObjectName(QString::fromUtf8("listCouple"));

        relationView->addWidget(listCouple);


        centralLayout->addLayout(relationView);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formWidget = new QWidget(horizontalLayoutWidget);
        formWidget->setObjectName(QString::fromUtf8("formWidget"));

        gridLayout->addWidget(formWidget, 1, 0, 1, 2);


        centralLayout->addLayout(gridLayout);

        centralLayout->setStretch(1, 100);

        retranslateUi(v_mainrelation);

        QMetaObject::connectSlotsByName(v_mainrelation);
    } // setupUi

    void retranslateUi(QWidget *v_mainrelation)
    {
        v_mainrelation->setWindowTitle(QApplication::translate("v_mainrelation", "Form", 0, QApplication::UnicodeUTF8));
        labelRelation->setText(QApplication::translate("v_mainrelation", "Relations", 0, QApplication::UnicodeUTF8));
        labelCouple->setText(QApplication::translate("v_mainrelation", "Couples", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class v_mainrelation: public Ui_v_mainrelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MAINRELATION_H
