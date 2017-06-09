/********************************************************************************
** Form generated from reading UI file 'v_multiform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_MULTIFORM_H
#define UI_V_MULTIFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MutlimediaForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelWindowTitle;
    QFormLayout *formLayout;
    QLabel *labelID;
    QTextEdit *textID;
    QLabel *labelTitle;
    QTextEdit *textTitle;
    QLabel *typeLabel;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QLabel *fileLabel;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QTextEdit *textTitle_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QWidget *MutlimediaForm)
    {
        if (MutlimediaForm->objectName().isEmpty())
            MutlimediaForm->setObjectName(QStringLiteral("MutlimediaForm"));
        MutlimediaForm->resize(385, 202);
        verticalLayoutWidget = new QWidget(MutlimediaForm);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 380, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelWindowTitle = new QLabel(verticalLayoutWidget);
        labelWindowTitle->setObjectName(QStringLiteral("labelWindowTitle"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelWindowTitle->setFont(font);
        labelWindowTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelWindowTitle);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelID = new QLabel(verticalLayoutWidget);
        labelID->setObjectName(QStringLiteral("labelID"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelID);

        textID = new QTextEdit(verticalLayoutWidget);
        textID->setObjectName(QStringLiteral("textID"));
        textID->setMaximumSize(QSize(16777215, 30));
        textID->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, textID);

        labelTitle = new QLabel(verticalLayoutWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelTitle);

        textTitle = new QTextEdit(verticalLayoutWidget);
        textTitle->setObjectName(QStringLiteral("textTitle"));
        textTitle->setMaximumSize(QSize(16777215, 30));

        formLayout->setWidget(1, QFormLayout::FieldRole, textTitle);

        typeLabel = new QLabel(verticalLayoutWidget);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, typeLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_3->addWidget(radioButton_2);

        radioButton = new QRadioButton(verticalLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_3->addWidget(radioButton);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        fileLabel = new QLabel(verticalLayoutWidget);
        fileLabel->setObjectName(QStringLiteral("fileLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, fileLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        textTitle_2 = new QTextEdit(verticalLayoutWidget);
        textTitle_2->setObjectName(QStringLiteral("textTitle_2"));
        textTitle_2->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(textTitle_2);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);


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


        retranslateUi(MutlimediaForm);

        QMetaObject::connectSlotsByName(MutlimediaForm);
    } // setupUi

    void retranslateUi(QWidget *MutlimediaForm)
    {
        MutlimediaForm->setWindowTitle(QApplication::translate("MutlimediaForm", "Form", Q_NULLPTR));
        labelWindowTitle->setText(QApplication::translate("MutlimediaForm", "Multimedia", Q_NULLPTR));
        labelID->setText(QApplication::translate("MutlimediaForm", "ID :", Q_NULLPTR));
        labelTitle->setText(QApplication::translate("MutlimediaForm", "Title :", Q_NULLPTR));
        typeLabel->setText(QApplication::translate("MutlimediaForm", "Type :", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MutlimediaForm", "Video", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MutlimediaForm", "Image", Q_NULLPTR));
        fileLabel->setText(QApplication::translate("MutlimediaForm", "File :", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MutlimediaForm", "Open", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("MutlimediaForm", "Cancel", Q_NULLPTR));
        btnSave->setText(QApplication::translate("MutlimediaForm", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MutlimediaForm: public Ui_MutlimediaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MULTIFORM_H
