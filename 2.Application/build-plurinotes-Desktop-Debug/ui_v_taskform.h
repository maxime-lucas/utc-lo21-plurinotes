/********************************************************************************
** Form generated from reading UI file 'v_taskform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_TASKFORM_H
#define UI_V_TASKFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_V_TaskForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelWindowTitle;
    QLabel *iDLabel;
    QLineEdit *iDLineEdit;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *actionLabel;
    QLineEdit *actionLineEdit;
    QHBoxLayout *priorityLayout;
    QSlider *prioritySlider;
    QLCDNumber *lcdNumber;
    QLabel *priorityLabel;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *yesBtn;
    QRadioButton *noBtn;
    QDateTimeEdit *toBeDoneOnDateTimeEdit;
    QLabel *toBeDoneOnLabel_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *V_TaskForm)
    {
        if (V_TaskForm->objectName().isEmpty())
            V_TaskForm->setObjectName(QString::fromUtf8("V_TaskForm"));
        V_TaskForm->resize(423, 272);
        verticalLayoutWidget = new QWidget(V_TaskForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 401, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelWindowTitle = new QLabel(verticalLayoutWidget);
        labelWindowTitle->setObjectName(QString::fromUtf8("labelWindowTitle"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelWindowTitle->setFont(font);
        labelWindowTitle->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::SpanningRole, labelWindowTitle);

        iDLabel = new QLabel(verticalLayoutWidget);
        iDLabel->setObjectName(QString::fromUtf8("iDLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, iDLabel);

        iDLineEdit = new QLineEdit(verticalLayoutWidget);
        iDLineEdit->setObjectName(QString::fromUtf8("iDLineEdit"));
        iDLineEdit->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, iDLineEdit);

        titleLabel = new QLabel(verticalLayoutWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, titleLabel);

        titleLineEdit = new QLineEdit(verticalLayoutWidget);
        titleLineEdit->setObjectName(QString::fromUtf8("titleLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, titleLineEdit);

        actionLabel = new QLabel(verticalLayoutWidget);
        actionLabel->setObjectName(QString::fromUtf8("actionLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, actionLabel);

        actionLineEdit = new QLineEdit(verticalLayoutWidget);
        actionLineEdit->setObjectName(QString::fromUtf8("actionLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, actionLineEdit);

        priorityLayout = new QHBoxLayout();
        priorityLayout->setObjectName(QString::fromUtf8("priorityLayout"));
        prioritySlider = new QSlider(verticalLayoutWidget);
        prioritySlider->setObjectName(QString::fromUtf8("prioritySlider"));
        prioritySlider->setOrientation(Qt::Horizontal);

        priorityLayout->addWidget(prioritySlider);

        lcdNumber = new QLCDNumber(verticalLayoutWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        priorityLayout->addWidget(lcdNumber);


        formLayout->setLayout(10, QFormLayout::FieldRole, priorityLayout);

        priorityLabel = new QLabel(verticalLayoutWidget);
        priorityLabel->setObjectName(QString::fromUtf8("priorityLabel"));

        formLayout->setWidget(10, QFormLayout::LabelRole, priorityLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        yesBtn = new QRadioButton(verticalLayoutWidget);
        yesBtn->setObjectName(QString::fromUtf8("yesBtn"));

        horizontalLayout_3->addWidget(yesBtn);

        noBtn = new QRadioButton(verticalLayoutWidget);
        noBtn->setObjectName(QString::fromUtf8("noBtn"));

        horizontalLayout_3->addWidget(noBtn);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_3);

        toBeDoneOnDateTimeEdit = new QDateTimeEdit(verticalLayoutWidget);
        toBeDoneOnDateTimeEdit->setObjectName(QString::fromUtf8("toBeDoneOnDateTimeEdit"));
        toBeDoneOnDateTimeEdit->setEnabled(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, toBeDoneOnDateTimeEdit);

        toBeDoneOnLabel_2 = new QLabel(verticalLayoutWidget);
        toBeDoneOnLabel_2->setObjectName(QString::fromUtf8("toBeDoneOnLabel_2"));

        formLayout->setWidget(8, QFormLayout::LabelRole, toBeDoneOnLabel_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label);


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


        retranslateUi(V_TaskForm);

        QMetaObject::connectSlotsByName(V_TaskForm);
    } // setupUi

    void retranslateUi(QDialog *V_TaskForm)
    {
        V_TaskForm->setWindowTitle(QApplication::translate("V_TaskForm", "Dialog", 0, QApplication::UnicodeUTF8));
        labelWindowTitle->setText(QApplication::translate("V_TaskForm", "Task", 0, QApplication::UnicodeUTF8));
        iDLabel->setText(QApplication::translate("V_TaskForm", "ID :", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("V_TaskForm", "Title :", 0, QApplication::UnicodeUTF8));
        actionLabel->setText(QApplication::translate("V_TaskForm", "Action :", 0, QApplication::UnicodeUTF8));
        priorityLabel->setText(QApplication::translate("V_TaskForm", "Priority :", 0, QApplication::UnicodeUTF8));
        yesBtn->setText(QApplication::translate("V_TaskForm", "Yes", 0, QApplication::UnicodeUTF8));
        noBtn->setText(QApplication::translate("V_TaskForm", "No", 0, QApplication::UnicodeUTF8));
        toBeDoneOnLabel_2->setText(QApplication::translate("V_TaskForm", "to be done on :", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("V_TaskForm", "Add Deadline ?", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("V_TaskForm", "Cancel", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("V_TaskForm", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class V_TaskForm: public Ui_V_TaskForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_TASKFORM_H
