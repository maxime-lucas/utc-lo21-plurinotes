/********************************************************************************
** Form generated from reading UI file 'littlenote.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LITTLENOTE_H
#define UI_LITTLENOTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *labelType;
    QLabel *labelID;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(100, 100);
        Form->setStyleSheet(QString::fromUtf8("background-color:rgb(108, 255, 214);\n"
"border:1px solid black;"));
        labelType = new QLabel(Form);
        labelType->setObjectName(QString::fromUtf8("labelType"));
        labelType->setGeometry(QRect(0, 0, 100, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(10);
        font.setItalic(true);
        labelType->setFont(font);
        labelType->setStyleSheet(QString::fromUtf8("background-color:rgb(94, 223, 187);\n"
"font-style:italic;"));
        labelType->setAlignment(Qt::AlignCenter);
        labelID = new QLabel(Form);
        labelID->setObjectName(QString::fromUtf8("labelID"));
        labelID->setGeometry(QRect(0, 20, 100, 80));
        QFont font1;
        font1.setPointSize(28);
        font1.setBold(true);
        font1.setWeight(75);
        labelID->setFont(font1);
        labelID->setAlignment(Qt::AlignCenter);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        labelType->setText(QApplication::translate("Form", "Article", 0, QApplication::UnicodeUTF8));
        labelID->setText(QApplication::translate("Form", "1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LITTLENOTE_H
