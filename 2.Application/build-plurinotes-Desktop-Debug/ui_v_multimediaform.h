/********************************************************************************
** Form generated from reading UI file 'v_multimediaform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_MULTIMEDIAFORM_H
#define UI_V_MULTIMEDIAFORM_H

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
            V_MultimediaForm->setObjectName(QString::fromUtf8("V_MultimediaForm"));
        V_MultimediaForm->resize(421, 346);
        verticalLayoutWidget = new QWidget(V_MultimediaForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 401, 326));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelWindowTitle = new QLabel(verticalLayoutWidget);
        labelWindowTitle->setObjectName(QString::fromUtf8("labelWindowTitle"));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        labelWindowTitle->setFont(font);
        labelWindowTitle->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::SpanningRole, labelWindowTitle);

        labelID = new QLabel(verticalLayoutWidget);
        labelID->setObjectName(QString::fromUtf8("labelID"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelID);

        textID = new QTextEdit(verticalLayoutWidget);
        textID->setObjectName(QString::fromUtf8("textID"));
        textID->setMaximumSize(QSize(16777215, 30));
        textID->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, textID);

        labelTitle = new QLabel(verticalLayoutWidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelTitle);

        textTitle = new QTextEdit(verticalLayoutWidget);
        textTitle->setObjectName(QString::fromUtf8("textTitle"));
        textTitle->setMaximumSize(QSize(16777215, 30));

        formLayout->setWidget(3, QFormLayout::FieldRole, textTitle);

        typeLabel = new QLabel(verticalLayoutWidget);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, typeLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        audioBtn = new QRadioButton(verticalLayoutWidget);
        audioBtn->setObjectName(QString::fromUtf8("audioBtn"));

        horizontalLayout_2->addWidget(audioBtn);

        imageBtn = new QRadioButton(verticalLayoutWidget);
        imageBtn->setObjectName(QString::fromUtf8("imageBtn"));

        horizontalLayout_2->addWidget(imageBtn);

        videoBtn = new QRadioButton(verticalLayoutWidget);
        videoBtn->setObjectName(QString::fromUtf8("videoBtn"));

        horizontalLayout_2->addWidget(videoBtn);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        fileLineEdit = new QLineEdit(verticalLayoutWidget);
        fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));

        horizontalLayout_3->addWidget(fileLineEdit);

        btnOpen = new QPushButton(verticalLayoutWidget);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));

        horizontalLayout_3->addWidget(btnOpen);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout_3);

        labelFile = new QLabel(verticalLayoutWidget);
        labelFile->setObjectName(QString::fromUtf8("labelFile"));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelFile);

        textDesc = new QTextEdit(verticalLayoutWidget);
        textDesc->setObjectName(QString::fromUtf8("textDesc"));

        formLayout->setWidget(4, QFormLayout::FieldRole, textDesc);

        labelDesc = new QLabel(verticalLayoutWidget);
        labelDesc->setObjectName(QString::fromUtf8("labelDesc"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelDesc);


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


        retranslateUi(V_MultimediaForm);

        QMetaObject::connectSlotsByName(V_MultimediaForm);
    } // setupUi

    void retranslateUi(QDialog *V_MultimediaForm)
    {
        V_MultimediaForm->setWindowTitle(QApplication::translate("V_MultimediaForm", "Multimedia", 0, QApplication::UnicodeUTF8));
        labelWindowTitle->setText(QApplication::translate("V_MultimediaForm", "MultiMedia", 0, QApplication::UnicodeUTF8));
        labelID->setText(QApplication::translate("V_MultimediaForm", "ID :", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("V_MultimediaForm", "Title :", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("V_MultimediaForm", "Type :", 0, QApplication::UnicodeUTF8));
        audioBtn->setText(QApplication::translate("V_MultimediaForm", "Audio", 0, QApplication::UnicodeUTF8));
        imageBtn->setText(QApplication::translate("V_MultimediaForm", "Image", 0, QApplication::UnicodeUTF8));
        videoBtn->setText(QApplication::translate("V_MultimediaForm", "Video", 0, QApplication::UnicodeUTF8));
        btnOpen->setText(QApplication::translate("V_MultimediaForm", "Open", 0, QApplication::UnicodeUTF8));
        labelFile->setText(QApplication::translate("V_MultimediaForm", "File: ", 0, QApplication::UnicodeUTF8));
        labelDesc->setText(QApplication::translate("V_MultimediaForm", "Description : ", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("V_MultimediaForm", "Cancel", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("V_MultimediaForm", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class V_MultimediaForm: public Ui_V_MultimediaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MULTIMEDIAFORM_H
