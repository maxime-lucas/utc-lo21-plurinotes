/********************************************************************************
** Form generated from reading UI file 'v_centralnote.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_CENTRALNOTE_H
#define UI_V_CENTRALNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_V_CentralNote
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelTitle;
    QLabel *label1;
    QPushButton *btnDelete;
    QLabel *label2;
    QLabel *labelLastModifOn;
    QLabel *labelType;
    QLabel *labelID;
    QLabel *labelCreatedOn;
    QPushButton *btnEdit;
    QWidget *formWidget;

    void setupUi(QWidget *V_CentralNote)
    {
        if (V_CentralNote->objectName().isEmpty())
            V_CentralNote->setObjectName(QStringLiteral("V_CentralNote"));
        V_CentralNote->setWindowModality(Qt::NonModal);
        V_CentralNote->resize(560, 560);
        V_CentralNote->setMaximumSize(QSize(600, 560));
        V_CentralNote->setLayoutDirection(Qt::LeftToRight);
        gridLayoutWidget = new QWidget(V_CentralNote);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 541, 541));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(gridLayoutWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelTitle, 1, 0, 1, 2);

        label1 = new QLabel(gridLayoutWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(10);
        label1->setFont(font1);
        label1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label1, 2, 0, 1, 1);

        btnDelete = new QPushButton(gridLayoutWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));

        gridLayout->addWidget(btnDelete, 5, 0, 1, 1);

        label2 = new QLabel(gridLayoutWidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setMaximumSize(QSize(16777215, 20));
        label2->setFont(font1);
        label2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label2, 2, 1, 1, 1);

        labelLastModifOn = new QLabel(gridLayoutWidget);
        labelLastModifOn->setObjectName(QStringLiteral("labelLastModifOn"));
        labelLastModifOn->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        labelLastModifOn->setFont(font2);
        labelLastModifOn->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelLastModifOn, 3, 1, 1, 1);

        labelType = new QLabel(gridLayoutWidget);
        labelType->setObjectName(QStringLiteral("labelType"));
        labelType->setMaximumSize(QSize(16777215, 30));
        labelType->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelType, 0, 0, 1, 1);

        labelID = new QLabel(gridLayoutWidget);
        labelID->setObjectName(QStringLiteral("labelID"));
        labelID->setMaximumSize(QSize(16777215, 30));
        labelID->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelID, 0, 1, 1, 1);

        labelCreatedOn = new QLabel(gridLayoutWidget);
        labelCreatedOn->setObjectName(QStringLiteral("labelCreatedOn"));
        labelCreatedOn->setMaximumSize(QSize(16777215, 20));
        labelCreatedOn->setFont(font2);
        labelCreatedOn->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelCreatedOn, 3, 0, 1, 1);

        btnEdit = new QPushButton(gridLayoutWidget);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));

        gridLayout->addWidget(btnEdit, 5, 1, 1, 1);

        formWidget = new QWidget(gridLayoutWidget);
        formWidget->setObjectName(QStringLiteral("formWidget"));
        formWidget->setMinimumSize(QSize(539, 382));
        formWidget->setMaximumSize(QSize(539, 382));

        gridLayout->addWidget(formWidget, 4, 0, 1, 2);


        retranslateUi(V_CentralNote);

        QMetaObject::connectSlotsByName(V_CentralNote);
    } // setupUi

    void retranslateUi(QWidget *V_CentralNote)
    {
        V_CentralNote->setWindowTitle(QApplication::translate("V_CentralNote", "Form", Q_NULLPTR));
        labelTitle->setText(QApplication::translate("V_CentralNote", "Title", Q_NULLPTR));
        label1->setText(QApplication::translate("V_CentralNote", "Created on :", Q_NULLPTR));
        btnDelete->setText(QApplication::translate("V_CentralNote", "Delete", Q_NULLPTR));
        label2->setText(QApplication::translate("V_CentralNote", "Last Modif on :", Q_NULLPTR));
        labelLastModifOn->setText(QApplication::translate("V_CentralNote", "00/00/0000 at 00:00:00", Q_NULLPTR));
        labelType->setText(QApplication::translate("V_CentralNote", "Type", Q_NULLPTR));
        labelID->setText(QApplication::translate("V_CentralNote", "ID : 1", Q_NULLPTR));
        labelCreatedOn->setText(QApplication::translate("V_CentralNote", "00/00/0000 at 00:00:00", Q_NULLPTR));
        btnEdit->setText(QApplication::translate("V_CentralNote", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class V_CentralNote: public Ui_V_CentralNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_CENTRALNOTE_H
