/********************************************************************************
** Form generated from reading UI file 'v_multiplerelation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_MULTIPLERELATION_H
#define UI_V_MULTIPLERELATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_v_multiplerelation
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeDescendant;
    QTreeWidget *treeAscendant;

    void setupUi(QWidget *v_multiplerelation)
    {
        if (v_multiplerelation->objectName().isEmpty())
            v_multiplerelation->setObjectName(QStringLiteral("v_multiplerelation"));
        v_multiplerelation->resize(224, 560);
        verticalLayoutWidget = new QWidget(v_multiplerelation);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 221, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeDescendant = new QTreeWidget(verticalLayoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("Descendants"));
        treeDescendant->setHeaderItem(__qtreewidgetitem);
        treeDescendant->setObjectName(QStringLiteral("treeDescendant"));

        verticalLayout->addWidget(treeDescendant);

        treeAscendant = new QTreeWidget(verticalLayoutWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("Ascendants"));
        treeAscendant->setHeaderItem(__qtreewidgetitem1);
        treeAscendant->setObjectName(QStringLiteral("treeAscendant"));

        verticalLayout->addWidget(treeAscendant);


        retranslateUi(v_multiplerelation);

        QMetaObject::connectSlotsByName(v_multiplerelation);
    } // setupUi

    void retranslateUi(QWidget *v_multiplerelation)
    {
        v_multiplerelation->setWindowTitle(QApplication::translate("v_multiplerelation", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class v_multiplerelation: public Ui_v_multiplerelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MULTIPLERELATION_H
