/********************************************************************************
** Form generated from reading UI file 'v_mainrelation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_MAINRELATION_H
#define UI_V_MAINRELATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_v_mainrelation
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *centralLayout;
    QVBoxLayout *relationView;
    QLabel *labelRelation;
    QListWidget *listRelation;
    QLabel *labelCouple;
    QListWidget *listWidget;
    QGridLayout *gridLayout;
    QWidget *formWidget;

    void setupUi(QWidget *v_mainrelation)
    {
        if (v_mainrelation->objectName().isEmpty())
            v_mainrelation->setObjectName(QStringLiteral("v_mainrelation"));
        v_mainrelation->resize(800, 600);
        v_mainrelation->setBaseSize(QSize(800, 600));
        v_mainrelation->setLayoutDirection(Qt::LeftToRight);
        horizontalLayoutWidget = new QWidget(v_mainrelation);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 581));
        centralLayout = new QHBoxLayout(horizontalLayoutWidget);
        centralLayout->setObjectName(QStringLiteral("centralLayout"));
        centralLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        centralLayout->setContentsMargins(0, 0, 0, 0);
        relationView = new QVBoxLayout();
        relationView->setObjectName(QStringLiteral("relationView"));
        relationView->setSizeConstraint(QLayout::SetMinimumSize);
        labelRelation = new QLabel(horizontalLayoutWidget);
        labelRelation->setObjectName(QStringLiteral("labelRelation"));

        relationView->addWidget(labelRelation);

        listRelation = new QListWidget(horizontalLayoutWidget);
        listRelation->setObjectName(QStringLiteral("listRelation"));

        relationView->addWidget(listRelation);

        labelCouple = new QLabel(horizontalLayoutWidget);
        labelCouple->setObjectName(QStringLiteral("labelCouple"));

        relationView->addWidget(labelCouple);

        listWidget = new QListWidget(horizontalLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        relationView->addWidget(listWidget);


        centralLayout->addLayout(relationView);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formWidget = new QWidget(horizontalLayoutWidget);
        formWidget->setObjectName(QStringLiteral("formWidget"));

        gridLayout->addWidget(formWidget, 1, 0, 1, 2);


        centralLayout->addLayout(gridLayout);

        centralLayout->setStretch(1, 100);

        retranslateUi(v_mainrelation);

        QMetaObject::connectSlotsByName(v_mainrelation);
    } // setupUi

    void retranslateUi(QWidget *v_mainrelation)
    {
        v_mainrelation->setWindowTitle(QApplication::translate("v_mainrelation", "Form", 0));
        labelRelation->setText(QApplication::translate("v_mainrelation", "Relations", 0));
        labelCouple->setText(QApplication::translate("v_mainrelation", "Couples", 0));
    } // retranslateUi

};

namespace Ui {
    class v_mainrelation: public Ui_v_mainrelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MAINRELATION_H
