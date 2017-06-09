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
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

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
    QWidget *widget;

    void setupUi(QWidget *V_CentralNote)
    {
        if (V_CentralNote->objectName().isEmpty())
            V_CentralNote->setObjectName(QString::fromUtf8("V_CentralNote"));
        V_CentralNote->setWindowModality(Qt::NonModal);
        V_CentralNote->resize(561, 560);
        V_CentralNote->setMaximumSize(QSize(600, 560));
        V_CentralNote->setLayoutDirection(Qt::LeftToRight);
        gridLayoutWidget = new QWidget(V_CentralNote);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 541, 541));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(gridLayoutWidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelTitle, 1, 0, 1, 2);

        label1 = new QLabel(gridLayoutWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(10);
        label1->setFont(font1);
        label1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label1, 2, 0, 1, 1);

        btnDelete = new QPushButton(gridLayoutWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        gridLayout->addWidget(btnDelete, 5, 0, 1, 1);

        label2 = new QLabel(gridLayoutWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setMaximumSize(QSize(16777215, 20));
        label2->setFont(font1);
        label2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label2, 2, 1, 1, 1);

        labelLastModifOn = new QLabel(gridLayoutWidget);
        labelLastModifOn->setObjectName(QString::fromUtf8("labelLastModifOn"));
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
        labelType->setObjectName(QString::fromUtf8("labelType"));
        labelType->setMaximumSize(QSize(16777215, 30));
        labelType->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelType, 0, 0, 1, 1);

        labelID = new QLabel(gridLayoutWidget);
        labelID->setObjectName(QString::fromUtf8("labelID"));
        labelID->setMaximumSize(QSize(16777215, 30));
        labelID->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelID, 0, 1, 1, 1);

        labelCreatedOn = new QLabel(gridLayoutWidget);
        labelCreatedOn->setObjectName(QString::fromUtf8("labelCreatedOn"));
        labelCreatedOn->setMaximumSize(QSize(16777215, 20));
        labelCreatedOn->setFont(font2);
        labelCreatedOn->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelCreatedOn, 3, 0, 1, 1);

        btnEdit = new QPushButton(gridLayoutWidget);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));

        gridLayout->addWidget(btnEdit, 5, 1, 1, 1);

        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(539, 382));
        widget->setMaximumSize(QSize(539, 382));

        gridLayout->addWidget(widget, 4, 0, 1, 2);

        gridLayoutWidget->raise();
        labelType->raise();
        labelID->raise();
        labelTitle->raise();
        label1->raise();
        label2->raise();
        labelCreatedOn->raise();
        labelLastModifOn->raise();
        btnDelete->raise();
        btnEdit->raise();

        retranslateUi(V_CentralNote);

        QMetaObject::connectSlotsByName(V_CentralNote);
    } // setupUi

    void retranslateUi(QWidget *V_CentralNote)
    {
        V_CentralNote->setWindowTitle(QApplication::translate("V_CentralNote", "Form", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("V_CentralNote", "Title", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("V_CentralNote", "Created on :", 0, QApplication::UnicodeUTF8));
        btnDelete->setText(QApplication::translate("V_CentralNote", "Delete", 0, QApplication::UnicodeUTF8));
        label2->setText(QApplication::translate("V_CentralNote", "Last Modif on :", 0, QApplication::UnicodeUTF8));
        labelLastModifOn->setText(QApplication::translate("V_CentralNote", "00/00/0000 at 00:00:00", 0, QApplication::UnicodeUTF8));
        labelType->setText(QApplication::translate("V_CentralNote", "Type", 0, QApplication::UnicodeUTF8));
        labelID->setText(QApplication::translate("V_CentralNote", "ID : 1", 0, QApplication::UnicodeUTF8));
        labelCreatedOn->setText(QApplication::translate("V_CentralNote", "00/00/0000 at 00:00:00", 0, QApplication::UnicodeUTF8));
        btnEdit->setText(QApplication::translate("V_CentralNote", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class V_CentralNote: public Ui_V_CentralNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_CENTRALNOTE_H
