/********************************************************************************
** Form generated from reading UI file 'v_relationform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_RELATIONFORM_H
#define UI_V_RELATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_v_relationform
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *princpalLayout;
    QLabel *labelWindowTitle;
    QFormLayout *formLayout;
    QLabel *labelTitle;
    QLineEdit *lineTitle;
    QLabel *labelDesc;
    QTextEdit *textEdit;
    QLabel *labelOriented;
    QHBoxLayout *btnLayout;
    QRadioButton *btnYes;
    QRadioButton *btnNo;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *v_relationform)
    {
        if (v_relationform->objectName().isEmpty())
            v_relationform->setObjectName(QStringLiteral("v_relationform"));
        v_relationform->resize(400, 300);
        verticalLayoutWidget = new QWidget(v_relationform);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 281));
        princpalLayout = new QVBoxLayout(verticalLayoutWidget);
        princpalLayout->setObjectName(QStringLiteral("princpalLayout"));
        princpalLayout->setContentsMargins(0, 0, 0, 0);
        labelWindowTitle = new QLabel(verticalLayoutWidget);
        labelWindowTitle->setObjectName(QStringLiteral("labelWindowTitle"));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        labelWindowTitle->setFont(font);
        labelWindowTitle->setAlignment(Qt::AlignCenter);

        princpalLayout->addWidget(labelWindowTitle);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelTitle = new QLabel(verticalLayoutWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelTitle);

        lineTitle = new QLineEdit(verticalLayoutWidget);
        lineTitle->setObjectName(QStringLiteral("lineTitle"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineTitle);

        labelDesc = new QLabel(verticalLayoutWidget);
        labelDesc->setObjectName(QStringLiteral("labelDesc"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelDesc);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit);

        labelOriented = new QLabel(verticalLayoutWidget);
        labelOriented->setObjectName(QStringLiteral("labelOriented"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelOriented);

        btnLayout = new QHBoxLayout();
        btnLayout->setObjectName(QStringLiteral("btnLayout"));
        btnYes = new QRadioButton(verticalLayoutWidget);
        btnYes->setObjectName(QStringLiteral("btnYes"));

        btnLayout->addWidget(btnYes);

        btnNo = new QRadioButton(verticalLayoutWidget);
        btnNo->setObjectName(QStringLiteral("btnNo"));

        btnLayout->addWidget(btnNo);


        formLayout->setLayout(2, QFormLayout::FieldRole, btnLayout);


        princpalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnCancel = new QPushButton(verticalLayoutWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        btnSave = new QPushButton(verticalLayoutWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));

        horizontalLayout->addWidget(btnSave);


        princpalLayout->addLayout(horizontalLayout);


        retranslateUi(v_relationform);

        QMetaObject::connectSlotsByName(v_relationform);
    } // setupUi

    void retranslateUi(QDialog *v_relationform)
    {
        v_relationform->setWindowTitle(QApplication::translate("v_relationform", "Dialog", 0));
        labelWindowTitle->setText(QApplication::translate("v_relationform", "Relation", 0));
        labelTitle->setText(QApplication::translate("v_relationform", "Title", 0));
        labelDesc->setText(QApplication::translate("v_relationform", "Description", 0));
        labelOriented->setText(QApplication::translate("v_relationform", "Oriented ?", 0));
        btnYes->setText(QApplication::translate("v_relationform", "yes", 0));
        btnNo->setText(QApplication::translate("v_relationform", "No", 0));
        btnCancel->setText(QApplication::translate("v_relationform", "Cancel", 0));
        btnSave->setText(QApplication::translate("v_relationform", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class v_relationform: public Ui_v_relationform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_RELATIONFORM_H
