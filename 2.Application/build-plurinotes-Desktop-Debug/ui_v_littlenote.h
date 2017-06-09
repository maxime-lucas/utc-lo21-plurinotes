/********************************************************************************
** Form generated from reading UI file 'v_littlenote.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_LITTLENOTE_H
#define UI_V_LITTLENOTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_V_Littlenote
{
public:
    QLabel *labelType;
    QLabel *labelID;

    void setupUi(QWidget *V_Littlenote)
    {
        if (V_Littlenote->objectName().isEmpty())
            V_Littlenote->setObjectName(QString::fromUtf8("V_Littlenote"));
        V_Littlenote->resize(150, 100);
        labelType = new QLabel(V_Littlenote);
        labelType->setObjectName(QString::fromUtf8("labelType"));
        labelType->setGeometry(QRect(0, 0, 151, 20));
        QFont font;
        font.setPointSize(9);
        font.setItalic(true);
        labelType->setFont(font);
        labelType->setAlignment(Qt::AlignCenter);
        labelID = new QLabel(V_Littlenote);
        labelID->setObjectName(QString::fromUtf8("labelID"));
        labelID->setGeometry(QRect(0, 20, 151, 81));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        labelID->setFont(font1);
        labelID->setAlignment(Qt::AlignCenter);

        retranslateUi(V_Littlenote);

        QMetaObject::connectSlotsByName(V_Littlenote);
    } // setupUi

    void retranslateUi(QWidget *V_Littlenote)
    {
        V_Littlenote->setWindowTitle(QApplication::translate("V_Littlenote", "Form", 0, QApplication::UnicodeUTF8));
        labelType->setText(QApplication::translate("V_Littlenote", "Article", 0, QApplication::UnicodeUTF8));
        labelID->setText(QApplication::translate("V_Littlenote", "1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class V_Littlenote: public Ui_V_Littlenote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_LITTLENOTE_H
