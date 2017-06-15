/********************************************************************************
** Form generated from reading UI file 'v_coupleform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_COUPLEFORM_H
#define UI_V_COUPLEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

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
            v_coupleform->setObjectName(QString::fromUtf8("v_coupleform"));
        v_coupleform->resize(400, 213);
        verticalLayoutWidget = new QWidget(v_coupleform);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 192));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelWindowTitle = new QLabel(verticalLayoutWidget);
        labelWindowTitle->setObjectName(QString::fromUtf8("labelWindowTitle"));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        labelWindowTitle->setFont(font);
        labelWindowTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelWindowTitle);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelTitle = new QLabel(verticalLayoutWidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelTitle);

        labelline = new QLineEdit(verticalLayoutWidget);
        labelline->setObjectName(QString::fromUtf8("labelline"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelline);

        labelNote1 = new QLabel(verticalLayoutWidget);
        labelNote1->setObjectName(QString::fromUtf8("labelNote1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelNote1);

        labelNote2 = new QLabel(verticalLayoutWidget);
        labelNote2->setObjectName(QString::fromUtf8("labelNote2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelNote2);

        note1 = new QComboBox(verticalLayoutWidget);
        note1->setObjectName(QString::fromUtf8("note1"));

        formLayout->setWidget(1, QFormLayout::FieldRole, note1);

        note2 = new QComboBox(verticalLayoutWidget);
        note2->setObjectName(QString::fromUtf8("note2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, note2);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCancel = new QPushButton(verticalLayoutWidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        btnSave = new QPushButton(verticalLayoutWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(v_coupleform);

        QMetaObject::connectSlotsByName(v_coupleform);
    } // setupUi

    void retranslateUi(QDialog *v_coupleform)
    {
        v_coupleform->setWindowTitle(QApplication::translate("v_coupleform", "Couple", 0, QApplication::UnicodeUTF8));
        labelWindowTitle->setText(QApplication::translate("v_coupleform", "Couple", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("v_coupleform", "Label", 0, QApplication::UnicodeUTF8));
        labelNote1->setText(QApplication::translate("v_coupleform", "Note1", 0, QApplication::UnicodeUTF8));
        labelNote2->setText(QApplication::translate("v_coupleform", "Note2", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("v_coupleform", "Cancel", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("v_coupleform", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class v_coupleform: public Ui_v_coupleform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_COUPLEFORM_H
