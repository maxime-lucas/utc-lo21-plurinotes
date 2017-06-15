/********************************************************************************
** Form generated from reading UI file 'v_articleform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_ARTICLEFORM_H
#define UI_V_ARTICLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_V_ArticleForm
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
    QLabel *labelText;
    QPlainTextEdit *textText;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *V_ArticleForm)
    {
        if (V_ArticleForm->objectName().isEmpty())
            V_ArticleForm->setObjectName(QStringLiteral("V_ArticleForm"));
        V_ArticleForm->resize(400, 300);
        verticalLayoutWidget = new QWidget(V_ArticleForm);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 8, 381, 281));
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

        labelText = new QLabel(verticalLayoutWidget);
        labelText->setObjectName(QStringLiteral("labelText"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelText);

        textText = new QPlainTextEdit(verticalLayoutWidget);
        textText->setObjectName(QStringLiteral("textText"));

        formLayout->setWidget(2, QFormLayout::FieldRole, textText);


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


        retranslateUi(V_ArticleForm);

        QMetaObject::connectSlotsByName(V_ArticleForm);
    } // setupUi

    void retranslateUi(QDialog *V_ArticleForm)
    {
        V_ArticleForm->setWindowTitle(QApplication::translate("V_ArticleForm", "Article", 0));
        labelWindowTitle->setText(QApplication::translate("V_ArticleForm", "Article", 0));
        labelID->setText(QApplication::translate("V_ArticleForm", "ID :", 0));
        labelTitle->setText(QApplication::translate("V_ArticleForm", "Title :", 0));
        labelText->setText(QApplication::translate("V_ArticleForm", "Text :", 0));
        btnCancel->setText(QApplication::translate("V_ArticleForm", "Cancel", 0));
        btnSave->setText(QApplication::translate("V_ArticleForm", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class V_ArticleForm: public Ui_V_ArticleForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_ARTICLEFORM_H
