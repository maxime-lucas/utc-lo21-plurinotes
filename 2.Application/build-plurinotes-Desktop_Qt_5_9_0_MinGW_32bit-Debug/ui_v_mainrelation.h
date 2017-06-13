/********************************************************************************
** Form generated from reading UI file 'v_mainrelation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_MAINRELATION_H
#define UI_V_MAINRELATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QListView *Relations;
    QLabel *labelCouple;
    QListWidget *listCouple;
    QHBoxLayout *coupleLayout;
    QVBoxLayout *coupleView;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *coupleButon;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *v_mainrelation)
    {
        if (v_mainrelation->objectName().isEmpty())
            v_mainrelation->setObjectName(QStringLiteral("v_mainrelation"));
        v_mainrelation->resize(800, 600);
        horizontalLayoutWidget = new QWidget(v_mainrelation);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 581));
        centralLayout = new QHBoxLayout(horizontalLayoutWidget);
        centralLayout->setObjectName(QStringLiteral("centralLayout"));
        centralLayout->setSizeConstraint(QLayout::SetFixedSize);
        centralLayout->setContentsMargins(0, 0, 0, 0);
        relationView = new QVBoxLayout();
        relationView->setObjectName(QStringLiteral("relationView"));
        relationView->setSizeConstraint(QLayout::SetMinimumSize);
        labelRelation = new QLabel(horizontalLayoutWidget);
        labelRelation->setObjectName(QStringLiteral("labelRelation"));

        relationView->addWidget(labelRelation);

        Relations = new QListView(horizontalLayoutWidget);
        Relations->setObjectName(QStringLiteral("Relations"));
        Relations->setEnabled(true);
        Relations->setBaseSize(QSize(20, 200));

        relationView->addWidget(Relations);

        labelCouple = new QLabel(horizontalLayoutWidget);
        labelCouple->setObjectName(QStringLiteral("labelCouple"));

        relationView->addWidget(labelCouple);

        listCouple = new QListWidget(horizontalLayoutWidget);
        listCouple->setObjectName(QStringLiteral("listCouple"));
        listCouple->setBaseSize(QSize(200, 200));

        relationView->addWidget(listCouple);


        centralLayout->addLayout(relationView);

        coupleLayout = new QHBoxLayout();
        coupleLayout->setSpacing(8);
        coupleLayout->setObjectName(QStringLiteral("coupleLayout"));
        coupleView = new QVBoxLayout();
        coupleView->setObjectName(QStringLiteral("coupleView"));
        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        coupleView->addItem(horizontalSpacer_3);


        coupleLayout->addLayout(coupleView);

        coupleButon = new QVBoxLayout();
        coupleButon->setObjectName(QStringLiteral("coupleButon"));
        btnAdd = new QPushButton(horizontalLayoutWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));

        coupleButon->addWidget(btnAdd);

        btnEdit = new QPushButton(horizontalLayoutWidget);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));

        coupleButon->addWidget(btnEdit);

        btnDelete = new QPushButton(horizontalLayoutWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));

        coupleButon->addWidget(btnDelete);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        coupleButon->addItem(verticalSpacer);


        coupleLayout->addLayout(coupleButon);


        centralLayout->addLayout(coupleLayout);

        centralLayout->setStretch(0, 30);
        centralLayout->setStretch(1, 100);

        retranslateUi(v_mainrelation);

        QMetaObject::connectSlotsByName(v_mainrelation);
    } // setupUi

    void retranslateUi(QWidget *v_mainrelation)
    {
        v_mainrelation->setWindowTitle(QApplication::translate("v_mainrelation", "Form", Q_NULLPTR));
        labelRelation->setText(QApplication::translate("v_mainrelation", "Relations", Q_NULLPTR));
        labelCouple->setText(QApplication::translate("v_mainrelation", "Couples", Q_NULLPTR));
        btnAdd->setText(QApplication::translate("v_mainrelation", "add Couple", Q_NULLPTR));
        btnEdit->setText(QApplication::translate("v_mainrelation", "edit Couple", Q_NULLPTR));
        btnDelete->setText(QApplication::translate("v_mainrelation", "delete Couple", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class v_mainrelation: public Ui_v_mainrelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MAINRELATION_H
