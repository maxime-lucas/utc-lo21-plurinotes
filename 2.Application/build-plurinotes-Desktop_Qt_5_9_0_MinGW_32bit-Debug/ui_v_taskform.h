/********************************************************************************
** Form generated from reading UI file 'v_taskform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_TASKFORM_H
#define UI_V_TASKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            V_TaskForm->setObjectName(QStringLiteral("V_TaskForm"));
        V_TaskForm->resize(423, 333);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(V_TaskForm->sizePolicy().hasHeightForWidth());
        V_TaskForm->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(V_TaskForm);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 401, 316));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelWindowTitle = new QLabel(verticalLayoutWidget);
        labelWindowTitle->setObjectName(QStringLiteral("labelWindowTitle"));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        labelWindowTitle->setFont(font);
        labelWindowTitle->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::SpanningRole, labelWindowTitle);

        iDLabel = new QLabel(verticalLayoutWidget);
        iDLabel->setObjectName(QStringLiteral("iDLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, iDLabel);

        iDLineEdit = new QLineEdit(verticalLayoutWidget);
        iDLineEdit->setObjectName(QStringLiteral("iDLineEdit"));
        iDLineEdit->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, iDLineEdit);

        titleLabel = new QLabel(verticalLayoutWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, titleLabel);

        titleLineEdit = new QLineEdit(verticalLayoutWidget);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, titleLineEdit);

        actionLabel = new QLabel(verticalLayoutWidget);
        actionLabel->setObjectName(QStringLiteral("actionLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, actionLabel);

        actionLineEdit = new QLineEdit(verticalLayoutWidget);
        actionLineEdit->setObjectName(QStringLiteral("actionLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, actionLineEdit);

        priorityLayout = new QHBoxLayout();
        priorityLayout->setObjectName(QStringLiteral("priorityLayout"));
        prioritySlider = new QSlider(verticalLayoutWidget);
        prioritySlider->setObjectName(QStringLiteral("prioritySlider"));
        prioritySlider->setOrientation(Qt::Horizontal);

        priorityLayout->addWidget(prioritySlider);

        lcdNumber = new QLCDNumber(verticalLayoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        priorityLayout->addWidget(lcdNumber);


        formLayout->setLayout(10, QFormLayout::FieldRole, priorityLayout);

        priorityLabel = new QLabel(verticalLayoutWidget);
        priorityLabel->setObjectName(QStringLiteral("priorityLabel"));

        formLayout->setWidget(10, QFormLayout::LabelRole, priorityLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        yesBtn = new QRadioButton(verticalLayoutWidget);
        yesBtn->setObjectName(QStringLiteral("yesBtn"));

        horizontalLayout_3->addWidget(yesBtn);

        noBtn = new QRadioButton(verticalLayoutWidget);
        noBtn->setObjectName(QStringLiteral("noBtn"));

        horizontalLayout_3->addWidget(noBtn);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_3);

        toBeDoneOnDateTimeEdit = new QDateTimeEdit(verticalLayoutWidget);
        toBeDoneOnDateTimeEdit->setObjectName(QStringLiteral("toBeDoneOnDateTimeEdit"));
        toBeDoneOnDateTimeEdit->setEnabled(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, toBeDoneOnDateTimeEdit);

        toBeDoneOnLabel_2 = new QLabel(verticalLayoutWidget);
        toBeDoneOnLabel_2->setObjectName(QStringLiteral("toBeDoneOnLabel_2"));

        formLayout->setWidget(8, QFormLayout::LabelRole, toBeDoneOnLabel_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label);


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


        retranslateUi(V_TaskForm);

        QMetaObject::connectSlotsByName(V_TaskForm);
    } // setupUi

    void retranslateUi(QDialog *V_TaskForm)
    {
        V_TaskForm->setWindowTitle(QApplication::translate("V_TaskForm", "Dialog", Q_NULLPTR));
        labelWindowTitle->setText(QApplication::translate("V_TaskForm", "Task", Q_NULLPTR));
        iDLabel->setText(QApplication::translate("V_TaskForm", "ID :", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("V_TaskForm", "Title :", Q_NULLPTR));
        actionLabel->setText(QApplication::translate("V_TaskForm", "Action :", Q_NULLPTR));
        priorityLabel->setText(QApplication::translate("V_TaskForm", "Priority :", Q_NULLPTR));
        yesBtn->setText(QApplication::translate("V_TaskForm", "Yes", Q_NULLPTR));
        noBtn->setText(QApplication::translate("V_TaskForm", "No", Q_NULLPTR));
        toBeDoneOnLabel_2->setText(QApplication::translate("V_TaskForm", "to be done on :", Q_NULLPTR));
        label->setText(QApplication::translate("V_TaskForm", "Add Deadline ?", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("V_TaskForm", "Cancel", Q_NULLPTR));
        btnSave->setText(QApplication::translate("V_TaskForm", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class V_TaskForm: public Ui_V_TaskForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_TASKFORM_H
