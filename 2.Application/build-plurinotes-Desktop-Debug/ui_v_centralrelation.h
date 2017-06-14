/********************************************************************************
** Form generated from reading UI file 'v_centralrelation.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_CENTRALRELATION_H
#define UI_V_CENTRALRELATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

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
            V_CentralRelation->setObjectName(QString::fromUtf8("V_CentralRelation"));
        V_CentralRelation->resize(560, 481);
        gridLayoutWidget = new QWidget(V_CentralRelation);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 541, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnEdit = new QPushButton(gridLayoutWidget);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));

        gridLayout->addWidget(btnEdit, 3, 1, 1, 1);

        textTitle = new QLineEdit(gridLayoutWidget);
        textTitle->setObjectName(QString::fromUtf8("textTitle"));
        textTitle->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        textTitle->setFont(font);
        textTitle->setStyleSheet(QString::fromUtf8("margin:0 auto;"));
        textTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(textTitle, 1, 0, 1, 2);

        labelID = new QLabel(gridLayoutWidget);
        labelID->setObjectName(QString::fromUtf8("labelID"));
        labelID->setMaximumSize(QSize(16777215, 30));
        labelID->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelID, 0, 1, 1, 1);

        labelType = new QLabel(gridLayoutWidget);
        labelType->setObjectName(QString::fromUtf8("labelType"));
        labelType->setMaximumSize(QSize(16777215, 30));
        labelType->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelType, 0, 0, 1, 1);

        btnDelete = new QPushButton(gridLayoutWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        gridLayout->addWidget(btnDelete, 3, 0, 1, 1);

        formWidget = new QWidget(gridLayoutWidget);
        formWidget->setObjectName(QString::fromUtf8("formWidget"));

        gridLayout->addWidget(formWidget, 2, 0, 1, 2);


        retranslateUi(V_CentralRelation);

        QMetaObject::connectSlotsByName(V_CentralRelation);
    } // setupUi

    void retranslateUi(QWidget *V_CentralRelation)
    {
        V_CentralRelation->setWindowTitle(QApplication::translate("V_CentralRelation", "Form", 0, QApplication::UnicodeUTF8));
        btnEdit->setText(QApplication::translate("V_CentralRelation", "Edit", 0, QApplication::UnicodeUTF8));
        textTitle->setText(QApplication::translate("V_CentralRelation", "Title", 0, QApplication::UnicodeUTF8));
        labelID->setText(QApplication::translate("V_CentralRelation", "ID : 1", 0, QApplication::UnicodeUTF8));
        labelType->setText(QApplication::translate("V_CentralRelation", "Type", 0, QApplication::UnicodeUTF8));
        btnDelete->setText(QApplication::translate("V_CentralRelation", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class V_CentralRelation: public Ui_V_CentralRelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_CENTRALRELATION_H
