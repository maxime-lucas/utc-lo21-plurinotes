/********************************************************************************
** Form generated from reading UI file 'v_centralnote.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_CENTRALNOTE_H
#define UI_V_CENTRALNOTE_H

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
            V_CentralNote->setObjectName(QString::fromUtf8("V_CentralNote"));
        V_CentralNote->setWindowModality(Qt::NonModal);
        V_CentralNote->resize(560, 611);
        V_CentralNote->setLayoutDirection(Qt::LeftToRight);
        gridLayoutWidget = new QWidget(V_CentralNote);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 541, 593));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnEdit = new QPushButton(gridLayoutWidget);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));

        gridLayout->addWidget(btnEdit, 5, 1, 1, 1);

        labelCreatedOn = new QLabel(gridLayoutWidget);
        labelCreatedOn->setObjectName(QString::fromUtf8("labelCreatedOn"));
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
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(10);
        label1->setFont(font1);
        label1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label1, 2, 0, 1, 1);

        label2 = new QLabel(gridLayoutWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setMaximumSize(QSize(16777215, 20));
        label2->setFont(font1);
        label2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label2, 2, 1, 1, 1);

        labelLastModifOn = new QLabel(gridLayoutWidget);
        labelLastModifOn->setObjectName(QString::fromUtf8("labelLastModifOn"));
        labelLastModifOn->setMaximumSize(QSize(16777215, 20));
        labelLastModifOn->setFont(font);
        labelLastModifOn->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelLastModifOn, 3, 1, 1, 1);

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

        textTitle = new QLineEdit(gridLayoutWidget);
        textTitle->setObjectName(QString::fromUtf8("textTitle"));
        textTitle->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        textTitle->setFont(font2);
        textTitle->setStyleSheet(QString::fromUtf8("margin:0 auto;"));
        textTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(textTitle, 1, 0, 1, 2);

        btnDelete = new QPushButton(gridLayoutWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        gridLayout->addWidget(btnDelete, 5, 0, 1, 1);

        formWidget = new QWidget(gridLayoutWidget);
        formWidget->setObjectName(QString::fromUtf8("formWidget"));

        gridLayout->addWidget(formWidget, 4, 0, 1, 2);


        retranslateUi(V_CentralNote);

        QMetaObject::connectSlotsByName(V_CentralNote);
    } // setupUi

    void retranslateUi(QWidget *V_CentralNote)
    {
        V_CentralNote->setWindowTitle(QApplication::translate("V_CentralNote", "Form", 0, QApplication::UnicodeUTF8));
        btnEdit->setText(QApplication::translate("V_CentralNote", "Edit", 0, QApplication::UnicodeUTF8));
        labelCreatedOn->setText(QApplication::translate("V_CentralNote", "00/00/0000 at 00:00:00", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("V_CentralNote", "Created on :", 0, QApplication::UnicodeUTF8));
        label2->setText(QApplication::translate("V_CentralNote", "Last Modif on :", 0, QApplication::UnicodeUTF8));
        labelLastModifOn->setText(QApplication::translate("V_CentralNote", "00/00/0000 at 00:00:00", 0, QApplication::UnicodeUTF8));
        labelID->setText(QApplication::translate("V_CentralNote", "ID : 1", 0, QApplication::UnicodeUTF8));
        labelType->setText(QApplication::translate("V_CentralNote", "Type", 0, QApplication::UnicodeUTF8));
        textTitle->setText(QApplication::translate("V_CentralNote", "Title", 0, QApplication::UnicodeUTF8));
        btnDelete->setText(QApplication::translate("V_CentralNote", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class V_CentralNote: public Ui_V_CentralNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_CENTRALNOTE_H
