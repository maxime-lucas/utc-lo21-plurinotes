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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
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
    QListView *listeRelation;
    QLabel *labelCouple;
    QListView *listCouple;
    QGridLayout *centralView;
    QPushButton *btnEdit;
    QLabel *labelID;
    QPushButton *btnDelete;
    QLineEdit *textTitle;
    QLabel *labelType;
    QWidget *contentView;

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

        listeRelation = new QListView(horizontalLayoutWidget);
        listeRelation->setObjectName(QStringLiteral("listeRelation"));
        listeRelation->setEnabled(true);
        listeRelation->setBaseSize(QSize(20, 200));

        relationView->addWidget(listeRelation);

        labelCouple = new QLabel(horizontalLayoutWidget);
        labelCouple->setObjectName(QStringLiteral("labelCouple"));

        relationView->addWidget(labelCouple);

        listCouple = new QListView(horizontalLayoutWidget);
        listCouple->setObjectName(QStringLiteral("listCouple"));

        relationView->addWidget(listCouple);


        centralLayout->addLayout(relationView);

        centralView = new QGridLayout();
        centralView->setObjectName(QStringLiteral("centralView"));
        btnEdit = new QPushButton(horizontalLayoutWidget);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));

        centralView->addWidget(btnEdit, 4, 1, 1, 1);

        labelID = new QLabel(horizontalLayoutWidget);
        labelID->setObjectName(QStringLiteral("labelID"));
        labelID->setMaximumSize(QSize(16777215, 30));
        labelID->setAlignment(Qt::AlignCenter);

        centralView->addWidget(labelID, 0, 1, 1, 1);

        btnDelete = new QPushButton(horizontalLayoutWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));

        centralView->addWidget(btnDelete, 4, 0, 1, 1);

        textTitle = new QLineEdit(horizontalLayoutWidget);
        textTitle->setObjectName(QStringLiteral("textTitle"));
        textTitle->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        textTitle->setFont(font);
        textTitle->setStyleSheet(QStringLiteral("margin:0 auto;"));
        textTitle->setAlignment(Qt::AlignCenter);

        centralView->addWidget(textTitle, 1, 0, 1, 2);

        labelType = new QLabel(horizontalLayoutWidget);
        labelType->setObjectName(QStringLiteral("labelType"));
        labelType->setMaximumSize(QSize(16777215, 30));
        labelType->setAlignment(Qt::AlignCenter);

        centralView->addWidget(labelType, 0, 0, 1, 1);

        contentView = new QWidget(horizontalLayoutWidget);
        contentView->setObjectName(QStringLiteral("contentView"));

        centralView->addWidget(contentView, 3, 0, 1, 2);


        centralLayout->addLayout(centralView);

        centralLayout->setStretch(1, 100);

        retranslateUi(v_mainrelation);

        QMetaObject::connectSlotsByName(v_mainrelation);
    } // setupUi

    void retranslateUi(QWidget *v_mainrelation)
    {
        v_mainrelation->setWindowTitle(QApplication::translate("v_mainrelation", "Form", Q_NULLPTR));
        labelRelation->setText(QApplication::translate("v_mainrelation", "Relations", Q_NULLPTR));
        labelCouple->setText(QApplication::translate("v_mainrelation", "Couples", Q_NULLPTR));
        btnEdit->setText(QApplication::translate("v_mainrelation", "Edit", Q_NULLPTR));
        labelID->setText(QApplication::translate("v_mainrelation", "ID : 1", Q_NULLPTR));
        btnDelete->setText(QApplication::translate("v_mainrelation", "Delete", Q_NULLPTR));
        textTitle->setText(QApplication::translate("v_mainrelation", "Title", Q_NULLPTR));
        labelType->setText(QApplication::translate("v_mainrelation", "Type", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class v_mainrelation: public Ui_v_mainrelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MAINRELATION_H
