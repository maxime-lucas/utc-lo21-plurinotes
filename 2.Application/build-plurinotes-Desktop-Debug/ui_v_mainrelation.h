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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
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
            v_mainrelation->setObjectName(QString::fromUtf8("v_mainrelation"));
        v_mainrelation->resize(800, 600);
        horizontalLayoutWidget = new QWidget(v_mainrelation);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 581));
        centralLayout = new QHBoxLayout(horizontalLayoutWidget);
        centralLayout->setObjectName(QString::fromUtf8("centralLayout"));
        centralLayout->setSizeConstraint(QLayout::SetFixedSize);
        centralLayout->setContentsMargins(0, 0, 0, 0);
        relationView = new QVBoxLayout();
        relationView->setObjectName(QString::fromUtf8("relationView"));
        relationView->setSizeConstraint(QLayout::SetMinimumSize);
        labelRelation = new QLabel(horizontalLayoutWidget);
        labelRelation->setObjectName(QString::fromUtf8("labelRelation"));

        relationView->addWidget(labelRelation);

        Relations = new QListView(horizontalLayoutWidget);
        Relations->setObjectName(QString::fromUtf8("Relations"));
        Relations->setEnabled(true);
        Relations->setBaseSize(QSize(20, 200));

        relationView->addWidget(Relations);

        labelCouple = new QLabel(horizontalLayoutWidget);
        labelCouple->setObjectName(QString::fromUtf8("labelCouple"));

        relationView->addWidget(labelCouple);

        listCouple = new QListWidget(horizontalLayoutWidget);
        listCouple->setObjectName(QString::fromUtf8("listCouple"));
        listCouple->setBaseSize(QSize(200, 200));

        relationView->addWidget(listCouple);


        centralLayout->addLayout(relationView);

        coupleLayout = new QHBoxLayout();
        coupleLayout->setSpacing(8);
        coupleLayout->setObjectName(QString::fromUtf8("coupleLayout"));
        coupleView = new QVBoxLayout();
        coupleView->setObjectName(QString::fromUtf8("coupleView"));
        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        coupleView->addItem(horizontalSpacer_3);


        coupleLayout->addLayout(coupleView);

        coupleButon = new QVBoxLayout();
        coupleButon->setObjectName(QString::fromUtf8("coupleButon"));
        btnAdd = new QPushButton(horizontalLayoutWidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        coupleButon->addWidget(btnAdd);

        btnEdit = new QPushButton(horizontalLayoutWidget);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));

        coupleButon->addWidget(btnEdit);

        btnDelete = new QPushButton(horizontalLayoutWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

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
        v_mainrelation->setWindowTitle(QApplication::translate("v_mainrelation", "Form", 0, QApplication::UnicodeUTF8));
        labelRelation->setText(QApplication::translate("v_mainrelation", "Relations", 0, QApplication::UnicodeUTF8));
        labelCouple->setText(QApplication::translate("v_mainrelation", "Couples", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("v_mainrelation", "add Couple", 0, QApplication::UnicodeUTF8));
        btnEdit->setText(QApplication::translate("v_mainrelation", "edit Couple", 0, QApplication::UnicodeUTF8));
        btnDelete->setText(QApplication::translate("v_mainrelation", "delete Couple", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class v_mainrelation: public Ui_v_mainrelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MAINRELATION_H
