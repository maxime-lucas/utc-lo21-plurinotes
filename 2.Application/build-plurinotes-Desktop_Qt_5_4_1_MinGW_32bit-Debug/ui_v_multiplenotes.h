/********************************************************************************
** Form generated from reading UI file 'v_multiplenotes.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_MULTIPLENOTES_H
#define UI_V_MULTIPLENOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_v_multiplenotes
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *v_multiplenotes)
    {
        if (v_multiplenotes->objectName().isEmpty())
            v_multiplenotes->setObjectName(QStringLiteral("v_multiplenotes"));
        v_multiplenotes->resize(200, 170);
        v_multiplenotes->setStyleSheet(QStringLiteral(""));
        scrollArea = new QScrollArea(v_multiplenotes);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(-1, -1, 201, 171));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 199, 169));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(v_multiplenotes);

        QMetaObject::connectSlotsByName(v_multiplenotes);
    } // setupUi

    void retranslateUi(QWidget *v_multiplenotes)
    {
        v_multiplenotes->setWindowTitle(QApplication::translate("v_multiplenotes", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class v_multiplenotes: public Ui_v_multiplenotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MULTIPLENOTES_H
