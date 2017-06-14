/********************************************************************************
** Form generated from reading UI file 'v_relationform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_RELATIONFORM_H
#define UI_V_RELATIONFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

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
            v_relationform->setObjectName(QString::fromUtf8("v_relationform"));
        v_relationform->resize(400, 300);
        verticalLayoutWidget = new QWidget(v_relationform);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 281));
        princpalLayout = new QVBoxLayout(verticalLayoutWidget);
        princpalLayout->setObjectName(QString::fromUtf8("princpalLayout"));
        princpalLayout->setContentsMargins(0, 0, 0, 0);
        labelWindowTitle = new QLabel(verticalLayoutWidget);
        labelWindowTitle->setObjectName(QString::fromUtf8("labelWindowTitle"));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        labelWindowTitle->setFont(font);
        labelWindowTitle->setAlignment(Qt::AlignCenter);

        princpalLayout->addWidget(labelWindowTitle);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelTitle = new QLabel(verticalLayoutWidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelTitle);

        lineTitle = new QLineEdit(verticalLayoutWidget);
        lineTitle->setObjectName(QString::fromUtf8("lineTitle"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineTitle);

        labelDesc = new QLabel(verticalLayoutWidget);
        labelDesc->setObjectName(QString::fromUtf8("labelDesc"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelDesc);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit);

        labelOriented = new QLabel(verticalLayoutWidget);
        labelOriented->setObjectName(QString::fromUtf8("labelOriented"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelOriented);

        btnLayout = new QHBoxLayout();
        btnLayout->setObjectName(QString::fromUtf8("btnLayout"));
        btnYes = new QRadioButton(verticalLayoutWidget);
        btnYes->setObjectName(QString::fromUtf8("btnYes"));

        btnLayout->addWidget(btnYes);

        btnNo = new QRadioButton(verticalLayoutWidget);
        btnNo->setObjectName(QString::fromUtf8("btnNo"));

        btnLayout->addWidget(btnNo);


        formLayout->setLayout(2, QFormLayout::FieldRole, btnLayout);


        princpalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCancel = new QPushButton(verticalLayoutWidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        btnSave = new QPushButton(verticalLayoutWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);


        princpalLayout->addLayout(horizontalLayout);


        retranslateUi(v_relationform);

        QMetaObject::connectSlotsByName(v_relationform);
    } // setupUi

    void retranslateUi(QDialog *v_relationform)
    {
        v_relationform->setWindowTitle(QApplication::translate("v_relationform", "Dialog", 0, QApplication::UnicodeUTF8));
        labelWindowTitle->setText(QApplication::translate("v_relationform", "Relation", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("v_relationform", "Title", 0, QApplication::UnicodeUTF8));
        labelDesc->setText(QApplication::translate("v_relationform", "Description", 0, QApplication::UnicodeUTF8));
        labelOriented->setText(QApplication::translate("v_relationform", "Oriented ?", 0, QApplication::UnicodeUTF8));
        btnYes->setText(QApplication::translate("v_relationform", "yes", 0, QApplication::UnicodeUTF8));
        btnNo->setText(QApplication::translate("v_relationform", "No", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("v_relationform", "Cancel", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("v_relationform", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class v_relationform: public Ui_v_relationform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_RELATIONFORM_H
