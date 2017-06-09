/********************************************************************************
** Form generated from reading UI file 'v_articleform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_ARTICLEFORM_H
#define UI_V_ARTICLEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_V_ArticleForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Title;
    QFormLayout *formLayout;
    QLabel *labelID;
    QTextEdit *textID;
    QLabel *labelTitle;
    QTextEdit *textTitle;
    QLabel *labelText;
    QLabel *labelWindowTitle;
    QPlainTextEdit *textText;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *V_ArticleForm)
    {
        if (V_ArticleForm->objectName().isEmpty())
            V_ArticleForm->setObjectName(QString::fromUtf8("V_ArticleForm"));
        V_ArticleForm->resize(400, 300);
        verticalLayoutWidget = new QWidget(V_ArticleForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 8, 381, 281));
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
        labelID = new QLabel(verticalLayoutWidget);
        labelID->setObjectName(QString::fromUtf8("labelID"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelID);

        textID = new QTextEdit(verticalLayoutWidget);
        textID->setObjectName(QString::fromUtf8("textID"));
        textID->setMaximumSize(QSize(16777215, 30));
        textID->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, textID);

        labelTitle = new QLabel(verticalLayoutWidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelTitle);

        textTitle = new QTextEdit(verticalLayoutWidget);
        textTitle->setObjectName(QString::fromUtf8("textTitle"));
        textTitle->setMaximumSize(QSize(16777215, 30));

        formLayout->setWidget(1, QFormLayout::FieldRole, textTitle);

        labelText = new QLabel(verticalLayoutWidget);
        labelText->setObjectName(QString::fromUtf8("labelText"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelText);

        textText = new QPlainTextEdit(verticalLayoutWidget);
        textText->setObjectName(QString::fromUtf8("textText"));

        formLayout->setWidget(2, QFormLayout::FieldRole, textText);


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


        retranslateUi(V_ArticleForm);

        QMetaObject::connectSlotsByName(V_ArticleForm);
    } // setupUi

    void retranslateUi(QDialog *V_ArticleForm)
    {
        V_ArticleForm->setWindowTitle(QApplication::translate("V_ArticleForm", "Article", 0, QApplication::UnicodeUTF8));
        labelWindowTitle->setText(QApplication::translate("V_ArticleForm", "Article", 0, QApplication::UnicodeUTF8));
        labelID->setText(QApplication::translate("V_ArticleForm", "ID :", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("V_ArticleForm", "Title :", 0, QApplication::UnicodeUTF8));
        labelText->setText(QApplication::translate("V_ArticleForm", "Text :", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("V_ArticleForm", "Cancel", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("V_ArticleForm", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class V_ArticleForm: public Ui_V_ArticleForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_ARTICLEFORM_H
