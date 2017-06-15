/********************************************************************************
** Form generated from reading UI file 'v_centralrelation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_CENTRALRELATION_H
#define UI_V_CENTRALRELATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_V_CentralRelation
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnEdit;
    QLineEdit *textTitle;
    QLabel *labelID;
    QLabel *labelType;
    QPushButton *btnDelete;
    QWidget *formWidget;

    void setupUi(QWidget *V_CentralRelation)
    {
        if (V_CentralRelation->objectName().isEmpty())
            V_CentralRelation->setObjectName(QStringLiteral("V_CentralRelation"));
        V_CentralRelation->resize(560, 481);
        gridLayoutWidget = new QWidget(V_CentralRelation);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 541, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnEdit = new QPushButton(gridLayoutWidget);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));

        gridLayout->addWidget(btnEdit, 3, 1, 1, 1);

        textTitle = new QLineEdit(gridLayoutWidget);
        textTitle->setObjectName(QStringLiteral("textTitle"));
        textTitle->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        textTitle->setFont(font);
        textTitle->setStyleSheet(QStringLiteral("margin:0 auto;"));
        textTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(textTitle, 1, 0, 1, 2);

        labelID = new QLabel(gridLayoutWidget);
        labelID->setObjectName(QStringLiteral("labelID"));
        labelID->setMaximumSize(QSize(16777215, 30));
        labelID->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelID, 0, 1, 1, 1);

        labelType = new QLabel(gridLayoutWidget);
        labelType->setObjectName(QStringLiteral("labelType"));
        labelType->setMaximumSize(QSize(16777215, 30));
        labelType->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelType, 0, 0, 1, 1);

        btnDelete = new QPushButton(gridLayoutWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));

        gridLayout->addWidget(btnDelete, 3, 0, 1, 1);

        formWidget = new QWidget(gridLayoutWidget);
        formWidget->setObjectName(QStringLiteral("formWidget"));

        gridLayout->addWidget(formWidget, 2, 0, 1, 2);


        retranslateUi(V_CentralRelation);

        QMetaObject::connectSlotsByName(V_CentralRelation);
    } // setupUi

    void retranslateUi(QWidget *V_CentralRelation)
    {
        V_CentralRelation->setWindowTitle(QApplication::translate("V_CentralRelation", "Form", 0));
        btnEdit->setText(QApplication::translate("V_CentralRelation", "Edit", 0));
        textTitle->setText(QApplication::translate("V_CentralRelation", "Title", 0));
        labelID->setText(QApplication::translate("V_CentralRelation", "ID : 1", 0));
        labelType->setText(QApplication::translate("V_CentralRelation", "Type", 0));
        btnDelete->setText(QApplication::translate("V_CentralRelation", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class V_CentralRelation: public Ui_V_CentralRelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_CENTRALRELATION_H
