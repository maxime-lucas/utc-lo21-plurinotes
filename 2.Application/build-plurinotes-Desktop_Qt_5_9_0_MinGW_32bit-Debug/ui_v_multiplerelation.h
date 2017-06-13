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
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_v_multiplerelation
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelDescendants;
    QTreeWidget *treeDescendant;
    QLabel *labelAscendants;
    QTreeWidget *treeAscendant;

    void setupUi(QWidget *v_multiplerelation)
    {
        if (v_multiplerelation->objectName().isEmpty())
            v_multiplerelation->setObjectName(QStringLiteral("v_multiplerelation"));
        v_multiplerelation->resize(210, 560);
        verticalLayoutWidget = new QWidget(v_multiplerelation);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 211, 561));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelDescendants = new QLabel(verticalLayoutWidget);
        labelDescendants->setObjectName(QStringLiteral("labelDescendants"));
        labelDescendants->setMinimumSize(QSize(0, 20));
        labelDescendants->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(labelDescendants);

        treeDescendant = new QTreeWidget(verticalLayoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeDescendant->setHeaderItem(__qtreewidgetitem);
        treeDescendant->setObjectName(QStringLiteral("treeDescendant"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeDescendant->sizePolicy().hasHeightForWidth());
        treeDescendant->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(treeDescendant);

        labelAscendants = new QLabel(verticalLayoutWidget);
        labelAscendants->setObjectName(QStringLiteral("labelAscendants"));
        labelAscendants->setMinimumSize(QSize(0, 20));
        labelAscendants->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(labelAscendants);

        treeAscendant = new QTreeWidget(verticalLayoutWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        treeAscendant->setHeaderItem(__qtreewidgetitem1);
        treeAscendant->setObjectName(QStringLiteral("treeAscendant"));
        sizePolicy.setHeightForWidth(treeAscendant->sizePolicy().hasHeightForWidth());
        treeAscendant->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(treeAscendant);


        retranslateUi(v_multiplerelation);

        QMetaObject::connectSlotsByName(v_multiplerelation);
    } // setupUi

    void retranslateUi(QWidget *v_multiplerelation)
    {
        v_multiplerelation->setWindowTitle(QApplication::translate("v_multiplerelation", "Form", Q_NULLPTR));

        labelDescendants->setText(QApplication::translate("v_multiplerelation", "Descendants", Q_NULLPTR));
        labelAscendants->setText(QApplication::translate("v_multiplerelation", "Ascendants", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class v_multiplerelation: public Ui_v_multiplerelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MULTIPLERELATION_H
