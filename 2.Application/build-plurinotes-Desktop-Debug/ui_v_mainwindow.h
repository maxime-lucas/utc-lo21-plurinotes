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
    QAction *actionShow_Asc_Desc_View;
    QAction *actionShow_Relations_View;
    QAction *actionRelation;
    QAction *actionCouple;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuNew;
    QMenu *menuView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *V_Mainwindow)
    {
        if (V_Mainwindow->objectName().isEmpty())
            V_Mainwindow->setObjectName(QString::fromUtf8("V_Mainwindow"));
        V_Mainwindow->resize(1100, 600);
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
        actionShow_Asc_Desc_View = new QAction(V_Mainwindow);
        actionShow_Asc_Desc_View->setObjectName(QString::fromUtf8("actionShow_Asc_Desc_View"));
        actionShow_Asc_Desc_View->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../ressources/asc_desc.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_Asc_Desc_View->setIcon(icon4);
        actionShow_Relations_View = new QAction(V_Mainwindow);
        actionShow_Relations_View->setObjectName(QString::fromUtf8("actionShow_Relations_View"));
        actionShow_Relations_View->setCheckable(true);
        actionRelation = new QAction(V_Mainwindow);
        actionRelation->setObjectName(QString::fromUtf8("actionRelation"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../ressources/newRelation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRelation->setIcon(icon5);
        actionCouple = new QAction(V_Mainwindow);
        actionCouple->setObjectName(QString::fromUtf8("actionCouple"));
        centralwidget = new QWidget(V_Mainwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        V_Mainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(V_Mainwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1100, 25));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuNew = new QMenu(menu_File);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        V_Mainwindow->setMenuBar(menubar);
        toolBar = new QToolBar(V_Mainwindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        V_Mainwindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menuView->menuAction());
        menu_File->addAction(menuNew->menuAction());
        menu_File->addSeparator();
        menu_File->addAction(actionQuit);
        menuNew->addAction(actionArticle);
        menuNew->addAction(actionMultimedia);
        menuNew->addAction(actionTask);
        menuNew->addSeparator();
        menuNew->addAction(actionRelation);
        menuNew->addAction(actionCouple);
        menuView->addAction(actionShow_Asc_Desc_View);
        menuView->addAction(actionShow_Relations_View);
        toolBar->addAction(actionArticle);
        toolBar->addSeparator();
        toolBar->addAction(actionMultimedia);
        toolBar->addSeparator();
        toolBar->addAction(actionTask);
        toolBar->addSeparator();
        toolBar->addAction(actionRelation);
        toolBar->addSeparator();
        toolBar->addAction(actionShow_Asc_Desc_View);

        retranslateUi(V_Mainwindow);

        QMetaObject::connectSlotsByName(V_Mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *V_Mainwindow)
    {
        V_Mainwindow->setWindowTitle(QApplication::translate("V_Mainwindow", "PluriNotes - FAYAX", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("V_Mainwindow", "Quit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionQuit->setToolTip(QApplication::translate("V_Mainwindow", "Quit the app", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionQuit->setShortcut(QApplication::translate("V_Mainwindow", "Esc", 0, QApplication::UnicodeUTF8));
        actionArticle->setText(QApplication::translate("V_Mainwindow", "Article", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionArticle->setToolTip(QApplication::translate("V_Mainwindow", "Add a new Article", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionMultimedia->setText(QApplication::translate("V_Mainwindow", "Multimedia", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionMultimedia->setToolTip(QApplication::translate("V_Mainwindow", "Add a new Multimedia", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionTask->setText(QApplication::translate("V_Mainwindow", "Task", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionTask->setToolTip(QApplication::translate("V_Mainwindow", "Add a new Task", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionShow_Asc_Desc_View->setText(QApplication::translate("V_Mainwindow", "Show Asc/Desc View", 0, QApplication::UnicodeUTF8));
        actionShow_Asc_Desc_View->setShortcut(QApplication::translate("V_Mainwindow", "N", 0, QApplication::UnicodeUTF8));
        actionShow_Relations_View->setText(QApplication::translate("V_Mainwindow", "Show Relations View", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionShow_Relations_View->setToolTip(QApplication::translate("V_Mainwindow", "Show Relations View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionShow_Relations_View->setShortcut(QApplication::translate("V_Mainwindow", "R", 0, QApplication::UnicodeUTF8));
        actionRelation->setText(QApplication::translate("V_Mainwindow", "Relation", 0, QApplication::UnicodeUTF8));
        actionCouple->setText(QApplication::translate("V_Mainwindow", "Couple", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("V_Mainwindow", "&File", 0, QApplication::UnicodeUTF8));
        menuNew->setTitle(QApplication::translate("V_Mainwindow", "New...", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("V_Mainwindow", "View", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("V_Mainwindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class V_Mainwindow: public Ui_V_Mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MAINWINDOW_H
