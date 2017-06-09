/********************************************************************************
** Form generated from reading UI file 'v_multimediaform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_MULTIMEDIAFORM_H
#define UI_V_MULTIMEDIAFORM_H

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

class Ui_V_MultimediaForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelWindowTitle;
    QLabel *labelID;
    QTextEdit *textID;
    QLabel *labelTitle;
    QTextEdit *textTitle;
    QLabel *typeLabel;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *audioBtn;
    QRadioButton *imageBtn;
    QRadioButton *videoBtn;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *fileLineEdit;
    QPushButton *btnOpen;
    QLabel *labelFile;
    QTextEdit *textDesc;
    QLabel *labelDesc;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *V_MultimediaForm)
    {
        if (V_MultimediaForm->objectName().isEmpty())
            V_MultimediaForm->setObjectName(QStringLiteral("V_MultimediaForm"));
        V_MultimediaForm->resize(421, 298);
        verticalLayoutWidget = new QWidget(V_MultimediaForm);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 401, 275));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelWindowTitle = new QLabel(verticalLayoutWidget);
        labelWindowTitle->setObjectName(QStringLiteral("labelWindowTitle"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelWindowTitle->setFont(font);
        labelWindowTitle->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::SpanningRole, labelWindowTitle);

        labelID = new QLabel(verticalLayoutWidget);
        labelID->setObjectName(QStringLiteral("labelID"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelID);

        textID = new QTextEdit(verticalLayoutWidget);
        textID->setObjectName(QStringLiteral("textID"));
        textID->setMaximumSize(QSize(16777215, 30));
        textID->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, textID);

        labelTitle = new QLabel(verticalLayoutWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelTitle);

        textTitle = new QTextEdit(verticalLayoutWidget);
        textTitle->setObjectName(QStringLiteral("textTitle"));
        textTitle->setMaximumSize(QSize(16777215, 30));

        formLayout->setWidget(3, QFormLayout::FieldRole, textTitle);

        typeLabel = new QLabel(verticalLayoutWidget);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, typeLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        audioBtn = new QRadioButton(verticalLayoutWidget);
        audioBtn->setObjectName(QStringLiteral("audioBtn"));

        horizontalLayout_2->addWidget(audioBtn);

        imageBtn = new QRadioButton(verticalLayoutWidget);
        imageBtn->setObjectName(QStringLiteral("imageBtn"));

        horizontalLayout_2->addWidget(imageBtn);

        videoBtn = new QRadioButton(verticalLayoutWidget);
        videoBtn->setObjectName(QStringLiteral("videoBtn"));

        horizontalLayout_2->addWidget(videoBtn);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        fileLineEdit = new QLineEdit(verticalLayoutWidget);
        fileLineEdit->setObjectName(QStringLiteral("fileLineEdit"));

        horizontalLayout_3->addWidget(fileLineEdit);

        btnOpen = new QPushButton(verticalLayoutWidget);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));

        horizontalLayout_3->addWidget(btnOpen);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout_3);

        labelFile = new QLabel(verticalLayoutWidget);
        labelFile->setObjectName(QStringLiteral("labelFile"));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelFile);

        textDesc = new QTextEdit(verticalLayoutWidget);
        textDesc->setObjectName(QStringLiteral("textDesc"));

        formLayout->setWidget(4, QFormLayout::FieldRole, textDesc);

        labelDesc = new QLabel(verticalLayoutWidget);
        labelDesc->setObjectName(QStringLiteral("labelDesc"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelDesc);


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


        retranslateUi(V_MultimediaForm);

        QMetaObject::connectSlotsByName(V_MultimediaForm);
    } // setupUi

    void retranslateUi(QDialog *V_MultimediaForm)
    {
        V_MultimediaForm->setWindowTitle(QApplication::translate("V_MultimediaForm", "Dialog", Q_NULLPTR));
        labelWindowTitle->setText(QApplication::translate("V_MultimediaForm", "MultiMedia", Q_NULLPTR));
        labelID->setText(QApplication::translate("V_MultimediaForm", "ID :", Q_NULLPTR));
        labelTitle->setText(QApplication::translate("V_MultimediaForm", "Title :", Q_NULLPTR));
        typeLabel->setText(QApplication::translate("V_MultimediaForm", "Type :", Q_NULLPTR));
        audioBtn->setText(QApplication::translate("V_MultimediaForm", "Audio", Q_NULLPTR));
        imageBtn->setText(QApplication::translate("V_MultimediaForm", "Image", Q_NULLPTR));
        videoBtn->setText(QApplication::translate("V_MultimediaForm", "Video", Q_NULLPTR));
        btnOpen->setText(QApplication::translate("V_MultimediaForm", "Open", Q_NULLPTR));
        labelFile->setText(QApplication::translate("V_MultimediaForm", "File: ", Q_NULLPTR));
        labelDesc->setText(QApplication::translate("V_MultimediaForm", "Description : ", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("V_MultimediaForm", "Cancel", Q_NULLPTR));
        btnSave->setText(QApplication::translate("V_MultimediaForm", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class V_MultimediaForm: public Ui_V_MultimediaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MULTIMEDIAFORM_H
