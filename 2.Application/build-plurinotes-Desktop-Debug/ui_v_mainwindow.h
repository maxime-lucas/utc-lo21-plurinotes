/********************************************************************************
** Form generated from reading UI file 'v_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_MAINWINDOW_H
#define UI_V_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_V_Mainwindow
{
public:
    QAction *actionQuit;
    QAction *actionArticle;
    QAction *actionMultimedia;
    QAction *actionTask;
    QAction *actionRelation;
    QAction *actionDefault_view;
    QAction *actionRelations_view;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuNew;
    QToolBar *toolBar;

    void setupUi(QMainWindow *V_Mainwindow)
    {
        if (V_Mainwindow->objectName().isEmpty())
            V_Mainwindow->setObjectName(QString::fromUtf8("V_Mainwindow"));
        V_Mainwindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../ressources/windowicon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        V_Mainwindow->setWindowIcon(icon);
        V_Mainwindow->setStyleSheet(QString::fromUtf8(""));
        actionQuit = new QAction(V_Mainwindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionArticle = new QAction(V_Mainwindow);
        actionArticle->setObjectName(QString::fromUtf8("actionArticle"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../ressources/newArticle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArticle->setIcon(icon1);
        actionMultimedia = new QAction(V_Mainwindow);
        actionMultimedia->setObjectName(QString::fromUtf8("actionMultimedia"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../ressources/newMultimedia.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMultimedia->setIcon(icon2);
        actionTask = new QAction(V_Mainwindow);
        actionTask->setObjectName(QString::fromUtf8("actionTask"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../ressources/newTask.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTask->setIcon(icon3);
        actionRelation = new QAction(V_Mainwindow);
        actionRelation->setObjectName(QString::fromUtf8("actionRelation"));
        actionDefault_view = new QAction(V_Mainwindow);
        actionDefault_view->setObjectName(QString::fromUtf8("actionDefault_view"));
        actionRelations_view = new QAction(V_Mainwindow);
        actionRelations_view->setObjectName(QString::fromUtf8("actionRelations_view"));
        centralwidget = new QWidget(V_Mainwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        V_Mainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(V_Mainwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuNew = new QMenu(menu_File);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        V_Mainwindow->setMenuBar(menubar);
        toolBar = new QToolBar(V_Mainwindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        V_Mainwindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(menuNew->menuAction());
        menu_File->addSeparator();
        menu_File->addAction(actionQuit);
        menuNew->addAction(actionArticle);
        menuNew->addAction(actionMultimedia);
        menuNew->addAction(actionTask);
        menuNew->addSeparator();
        toolBar->addAction(actionArticle);
        toolBar->addSeparator();
        toolBar->addAction(actionMultimedia);
        toolBar->addSeparator();
        toolBar->addAction(actionTask);

        retranslateUi(V_Mainwindow);

        QMetaObject::connectSlotsByName(V_Mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *V_Mainwindow)
    {
        V_Mainwindow->setWindowTitle(QApplication::translate("V_Mainwindow", "PluriNotes - FAYAX", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("V_Mainwindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionArticle->setText(QApplication::translate("V_Mainwindow", "Article", 0, QApplication::UnicodeUTF8));
        actionMultimedia->setText(QApplication::translate("V_Mainwindow", "Multimedia", 0, QApplication::UnicodeUTF8));
        actionTask->setText(QApplication::translate("V_Mainwindow", "Task", 0, QApplication::UnicodeUTF8));
        actionRelation->setText(QApplication::translate("V_Mainwindow", "Relation", 0, QApplication::UnicodeUTF8));
        actionDefault_view->setText(QApplication::translate("V_Mainwindow", "Default view", 0, QApplication::UnicodeUTF8));
        actionRelations_view->setText(QApplication::translate("V_Mainwindow", "Relations view", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("V_Mainwindow", "&File", 0, QApplication::UnicodeUTF8));
        menuNew->setTitle(QApplication::translate("V_Mainwindow", "New...", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("V_Mainwindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class V_Mainwindow: public Ui_V_Mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MAINWINDOW_H
