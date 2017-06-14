/********************************************************************************
** Form generated from reading UI file 'v_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V_MAINWINDOW_H
#define UI_V_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
            V_Mainwindow->setObjectName(QStringLiteral("V_Mainwindow"));
        V_Mainwindow->resize(1100, 600);
        QIcon icon;
        icon.addFile(QStringLiteral("../ressources/windowicon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        V_Mainwindow->setWindowIcon(icon);
        V_Mainwindow->setStyleSheet(QStringLiteral(""));
        actionQuit = new QAction(V_Mainwindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionArticle = new QAction(V_Mainwindow);
        actionArticle->setObjectName(QStringLiteral("actionArticle"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../ressources/newArticle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArticle->setIcon(icon1);
        actionMultimedia = new QAction(V_Mainwindow);
        actionMultimedia->setObjectName(QStringLiteral("actionMultimedia"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../ressources/newMultimedia.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMultimedia->setIcon(icon2);
        actionTask = new QAction(V_Mainwindow);
        actionTask->setObjectName(QStringLiteral("actionTask"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../ressources/newTask.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTask->setIcon(icon3);
        actionShow_Asc_Desc_View = new QAction(V_Mainwindow);
        actionShow_Asc_Desc_View->setObjectName(QStringLiteral("actionShow_Asc_Desc_View"));
        actionShow_Asc_Desc_View->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral("../ressources/asc_desc.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_Asc_Desc_View->setIcon(icon4);
        actionShow_Relations_View = new QAction(V_Mainwindow);
        actionShow_Relations_View->setObjectName(QStringLiteral("actionShow_Relations_View"));
        actionShow_Relations_View->setCheckable(true);
        actionRelation = new QAction(V_Mainwindow);
        actionRelation->setObjectName(QStringLiteral("actionRelation"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../ressources/newRelation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRelation->setIcon(icon5);
        actionCouple = new QAction(V_Mainwindow);
        actionCouple->setObjectName(QStringLiteral("actionCouple"));
        centralwidget = new QWidget(V_Mainwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setStyleSheet(QStringLiteral(""));
        V_Mainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(V_Mainwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1100, 25));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuNew = new QMenu(menu_File);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        V_Mainwindow->setMenuBar(menubar);
        toolBar = new QToolBar(V_Mainwindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
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
        V_Mainwindow->setWindowTitle(QApplication::translate("V_Mainwindow", "PluriNotes - FAYAX", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("V_Mainwindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionQuit->setToolTip(QApplication::translate("V_Mainwindow", "Quit the app", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("V_Mainwindow", "Esc", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionArticle->setText(QApplication::translate("V_Mainwindow", "Article", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionArticle->setToolTip(QApplication::translate("V_Mainwindow", "Add a new Article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionMultimedia->setText(QApplication::translate("V_Mainwindow", "Multimedia", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionMultimedia->setToolTip(QApplication::translate("V_Mainwindow", "Add a new Multimedia", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionTask->setText(QApplication::translate("V_Mainwindow", "Task", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionTask->setToolTip(QApplication::translate("V_Mainwindow", "Add a new Task", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionShow_Asc_Desc_View->setText(QApplication::translate("V_Mainwindow", "Show Asc/Desc View", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionShow_Asc_Desc_View->setShortcut(QApplication::translate("V_Mainwindow", "N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionShow_Relations_View->setText(QApplication::translate("V_Mainwindow", "Show Relations View", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShow_Relations_View->setToolTip(QApplication::translate("V_Mainwindow", "Show Relations View", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionShow_Relations_View->setShortcut(QApplication::translate("V_Mainwindow", "R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionRelation->setText(QApplication::translate("V_Mainwindow", "Relation", Q_NULLPTR));
        actionCouple->setText(QApplication::translate("V_Mainwindow", "Couple", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("V_Mainwindow", "&File", Q_NULLPTR));
        menuNew->setTitle(QApplication::translate("V_Mainwindow", "New...", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("V_Mainwindow", "View", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("V_Mainwindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class V_Mainwindow: public Ui_V_Mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V_MAINWINDOW_H
