/********************************************************************************
** Form generated from reading UI file 'v_centralnote.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_V_CentralNote
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnEdit;
    QLabel *labelCreatedOn;
    QLabel *label1;
    QLabel *label2;
    QLabel *labelLastModifOn;
    QLabel *labelID;
    QLabel *labelType;
    QLineEdit *textTitle;
    QPushButton *btnDelete;
    QWidget *formWidget;

    void setupUi(QWidget *V_CentralNote)
    {
        if (V_CentralNote->objectName().isEmpty())
            V_CentralNote->setObjectName(QStringLiteral("V_CentralNote"));
        V_CentralNote->setWindowModality(Qt::NonModal);
        V_CentralNote->resize(560, 523);
        V_CentralNote->setLayoutDirection(Qt::LeftToRight);
        gridLayoutWidget = new QWidget(V_CentralNote);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 541, 501));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnEdit = new QPushButton(gridLayoutWidget);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));

        gridLayout->addWidget(btnEdit, 5, 1, 1, 1);

        labelCreatedOn = new QLabel(gridLayoutWidget);
        labelCreatedOn->setObjectName(QStringLiteral("labelCreatedOn"));
        labelCreatedOn->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        labelCreatedOn->setFont(font);
        labelCreatedOn->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelCreatedOn, 3, 0, 1, 1);

        label1 = new QLabel(gridLayoutWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(10);
        label1->setFont(font1);
        label1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label1, 2, 0, 1, 1);

        label2 = new QLabel(gridLayoutWidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setMaximumSize(QSize(16777215, 20));
        label2->setFont(font1);
        label2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label2, 2, 1, 1, 1);

        labelLastModifOn = new QLabel(gridLayoutWidget);
        labelLastModifOn->setObjectName(QStringLiteral("labelLastModifOn"));
        labelLastModifOn->setMaximumSize(QSize(16777215, 20));
        labelLastModifOn->setFont(font);
        labelLastModifOn->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelLastModifOn, 3, 1, 1, 1);

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

        textTitle = new QLineEdit(gridLayoutWidget);
        textTitle->setObjectName(QStringLiteral("textTitle"));
        textTitle->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        textTitle->setFont(font2);
        textTitle->setStyleSheet(QStringLiteral("margin:0 auto;"));
        textTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(textTitle, 1, 0, 1, 2);

        btnDelete = new QPushButton(gridLayoutWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));

        gridLayout->addWidget(btnDelete, 5, 0, 1, 1);

        formWidget = new QWidget(gridLayoutWidget);
        formWidget->setObjectName(QStringLiteral("formWidget"));

        gridLayout->addWidget(formWidget, 4, 0, 1, 2);


        retranslateUi(V_CentralNote);

        QMetaObject::connectSlotsByName(V_CentralNote);
    } // setupUi

    void retranslateUi(QWidget *V_CentralNote)
    {
        V_CentralNote->setWindowTitle(QApplication::translate("V_CentralNote", "Form", 0));
        btnEdit->setText(QApplication::translate("V_CentralNote", "Edit", 0));
        labelCreatedOn->setText(QApplication::translate("V_CentralNote", "00/00/0000 at 00:00:00", 0));
        label1->setText(QApplication::translate("V_CentralNote", "Created on :", 0));
        label2->setText(QApplication::translate("V_CentralNote", "Last Modif on :", 0));
        labelLastModifOn->setText(QApplication::translate("V_CentralNote", "00/00/0000 at 00:00:00", 0));
        labelID->setText(QApplication::translate("V_CentralNote", "ID : 1", 0));
        labelType->setText(QApplication::translate("V_CentralNote", "Type", 0));
        textTitle->setText(QApplication::translate("V_CentralNote", "Title", 0));
        btnDelete->setText(QApplication::translate("V_CentralNote", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class V_CentralNote: public Ui_V_CentralNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_CENTRALNOTE_H
