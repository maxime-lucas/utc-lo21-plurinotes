/********************************************************************************
** Form generated from reading UI file 'v_coupleform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_COUPLEFORM_H
#define UI_V_COUPLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_v_coupleform
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelWindowTitle;
    QFormLayout *formLayout;
    QLabel *labelTitle;
    QLineEdit *labelline;
    QLabel *labelNote1;
    QLabel *labelNote2;
    QComboBox *note1;
    QComboBox *note2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *v_coupleform)
    {
        if (v_coupleform->objectName().isEmpty())
            v_coupleform->setObjectName(QStringLiteral("v_coupleform"));
        v_coupleform->resize(400, 190);
        verticalLayoutWidget = new QWidget(v_coupleform);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelWindowTitle = new QLabel(verticalLayoutWidget);
        labelWindowTitle->setObjectName(QStringLiteral("labelWindowTitle"));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        labelWindowTitle->setFont(font);
        labelWindowTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelWindowTitle);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelTitle = new QLabel(verticalLayoutWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelTitle);

        labelline = new QLineEdit(verticalLayoutWidget);
        labelline->setObjectName(QStringLiteral("labelline"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelline);

        labelNote1 = new QLabel(verticalLayoutWidget);
        labelNote1->setObjectName(QStringLiteral("labelNote1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelNote1);

        labelNote2 = new QLabel(verticalLayoutWidget);
        labelNote2->setObjectName(QStringLiteral("labelNote2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelNote2);

        note1 = new QComboBox(verticalLayoutWidget);
        note1->setObjectName(QStringLiteral("note1"));

        formLayout->setWidget(1, QFormLayout::FieldRole, note1);

        note2 = new QComboBox(verticalLayoutWidget);
        note2->setObjectName(QStringLiteral("note2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, note2);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnCancel = new QPushButton(verticalLayoutWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        btnSave = new QPushButton(verticalLayoutWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(v_coupleform);

        QMetaObject::connectSlotsByName(v_coupleform);
    } // setupUi

    void retranslateUi(QDialog *v_coupleform)
    {
        v_coupleform->setWindowTitle(QApplication::translate("v_coupleform", "Dialog", 0));
        labelWindowTitle->setText(QApplication::translate("v_coupleform", "Couple", 0));
        labelTitle->setText(QApplication::translate("v_coupleform", "Label", 0));
        labelNote1->setText(QApplication::translate("v_coupleform", "Note1", 0));
        labelNote2->setText(QApplication::translate("v_coupleform", "Note2", 0));
        btnCancel->setText(QApplication::translate("v_coupleform", "Cancel", 0));
        btnSave->setText(QApplication::translate("v_coupleform", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class v_coupleform: public Ui_v_coupleform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_COUPLEFORM_H
