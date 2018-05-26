/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOPEN;
    QAction *actionSAVE;
    QAction *actionSadfas;
    QAction *actionDfgdfh;
    QAction *action_Ctrl_N;
    QAction *actionEXIT;
    QAction *actionPaste_Ctrl_P;
    QAction *actionAll_Ctrl_A;
    QAction *actionDelete_Ctrl_D;
    QAction *actionConcel_Ctrl_C;
    QAction *actionFind_Ctrl_F;
    QAction *actionShear_Ctrl_S;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionBold;
    QAction *actionLean;
    QAction *actionUnderline;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionBack;
    QAction *actionGo;
    QAction *actionNEW;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menuAsdf_G;
    QMenu *menuAsdfasdf_G;
    QMenu *menu_H;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(786, 633);
        actionOPEN = new QAction(MainWindow);
        actionOPEN->setObjectName(QStringLiteral("actionOPEN"));
        actionSAVE = new QAction(MainWindow);
        actionSAVE->setObjectName(QStringLiteral("actionSAVE"));
        actionSadfas = new QAction(MainWindow);
        actionSadfas->setObjectName(QStringLiteral("actionSadfas"));
        actionDfgdfh = new QAction(MainWindow);
        actionDfgdfh->setObjectName(QStringLiteral("actionDfgdfh"));
        action_Ctrl_N = new QAction(MainWindow);
        action_Ctrl_N->setObjectName(QStringLiteral("action_Ctrl_N"));
        actionEXIT = new QAction(MainWindow);
        actionEXIT->setObjectName(QStringLiteral("actionEXIT"));
        actionPaste_Ctrl_P = new QAction(MainWindow);
        actionPaste_Ctrl_P->setObjectName(QStringLiteral("actionPaste_Ctrl_P"));
        actionAll_Ctrl_A = new QAction(MainWindow);
        actionAll_Ctrl_A->setObjectName(QStringLiteral("actionAll_Ctrl_A"));
        actionDelete_Ctrl_D = new QAction(MainWindow);
        actionDelete_Ctrl_D->setObjectName(QStringLiteral("actionDelete_Ctrl_D"));
        actionConcel_Ctrl_C = new QAction(MainWindow);
        actionConcel_Ctrl_C->setObjectName(QStringLiteral("actionConcel_Ctrl_C"));
        actionFind_Ctrl_F = new QAction(MainWindow);
        actionFind_Ctrl_F->setObjectName(QStringLiteral("actionFind_Ctrl_F"));
        actionShear_Ctrl_S = new QAction(MainWindow);
        actionShear_Ctrl_S->setObjectName(QStringLiteral("actionShear_Ctrl_S"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/iconimage/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/iconimage/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/iconimage/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName(QStringLiteral("actionBold"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/iconimage/textbold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon3);
        actionLean = new QAction(MainWindow);
        actionLean->setObjectName(QStringLiteral("actionLean"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/iconimage/textitalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLean->setIcon(icon4);
        actionUnderline = new QAction(MainWindow);
        actionUnderline->setObjectName(QStringLiteral("actionUnderline"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/iconimage/textunder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnderline->setIcon(icon5);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/iconimage/editcut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon6);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/iconimage/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon7);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/iconimage/editpaste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon8);
        actionBack = new QAction(MainWindow);
        actionBack->setObjectName(QStringLiteral("actionBack"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/iconimage/editundo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBack->setIcon(icon9);
        actionGo = new QAction(MainWindow);
        actionGo->setObjectName(QStringLiteral("actionGo"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/iconimage/editredo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGo->setIcon(icon10);
        actionNEW = new QAction(MainWindow);
        actionNEW->setObjectName(QStringLiteral("actionNEW"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 786, 23));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menuAsdf_G = new QMenu(menuBar);
        menuAsdf_G->setObjectName(QStringLiteral("menuAsdf_G"));
        menuAsdfasdf_G = new QMenu(menuBar);
        menuAsdfasdf_G->setObjectName(QStringLiteral("menuAsdfasdf_G"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menuAsdf_G->menuAction());
        menuBar->addAction(menuAsdfasdf_G->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addAction(actionNEW);
        menu_F->addAction(actionSAVE);
        menu_F->addAction(actionOPEN);
        menu_F->addSeparator();
        menu_F->addAction(actionEXIT);
        menuAsdf_G->addAction(actionSadfas);
        menuAsdf_G->addAction(actionDfgdfh);
        menuAsdfasdf_G->addAction(actionPaste_Ctrl_P);
        menuAsdfasdf_G->addAction(actionAll_Ctrl_A);
        menuAsdfasdf_G->addAction(actionDelete_Ctrl_D);
        menuAsdfasdf_G->addSeparator();
        menuAsdfasdf_G->addAction(actionConcel_Ctrl_C);
        menuAsdfasdf_G->addAction(actionFind_Ctrl_F);
        menuAsdfasdf_G->addSeparator();
        menuAsdfasdf_G->addAction(actionShear_Ctrl_S);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionBold);
        toolBar->addAction(actionLean);
        toolBar->addAction(actionUnderline);
        toolBar->addSeparator();
        toolBar->addAction(actionCut);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addSeparator();
        toolBar->addAction(actionBack);
        toolBar->addAction(actionGo);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOPEN->setText(QApplication::translate("MainWindow", "Open                   (&Ctrl+O)", 0));
        actionSAVE->setText(QApplication::translate("MainWindow", "Save                     (&Ctrl+S)", 0));
        actionSadfas->setText(QApplication::translate("MainWindow", "Bold      (&Ctrl+B)", 0));
        actionDfgdfh->setText(QApplication::translate("MainWindow", "Italic      (&Ctrl+I)", 0));
        action_Ctrl_N->setText(QApplication::translate("MainWindow", "(&Ctrl+N", 0));
        actionEXIT->setText(QApplication::translate("MainWindow", "Exit                       (&Ctrl+E)", 0));
        actionPaste_Ctrl_P->setText(QApplication::translate("MainWindow", "Paste         (&Ctrl+P)", 0));
        actionAll_Ctrl_A->setText(QApplication::translate("MainWindow", "All              (&Ctrl+A)", 0));
        actionDelete_Ctrl_D->setText(QApplication::translate("MainWindow", "Delete       (&Ctrl+D)", 0));
        actionConcel_Ctrl_C->setText(QApplication::translate("MainWindow", "Concel       (&Ctrl+C)", 0));
        actionFind_Ctrl_F->setText(QApplication::translate("MainWindow", "Find            (&Ctrl+F)", 0));
        actionShear_Ctrl_S->setText(QApplication::translate("MainWindow", "Shear        (&Ctrl+S)", 0));
        actionNew->setText(QApplication::translate("MainWindow", "new", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionBold->setText(QApplication::translate("MainWindow", "bold", 0));
        actionLean->setText(QApplication::translate("MainWindow", "lean", 0));
        actionUnderline->setText(QApplication::translate("MainWindow", "underline", 0));
        actionCut->setText(QApplication::translate("MainWindow", "cut", 0));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "copy", 0));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "paste", 0));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionBack->setText(QApplication::translate("MainWindow", "back", 0));
        actionGo->setText(QApplication::translate("MainWindow", "go", 0));
        actionNEW->setText(QApplication::translate("MainWindow", "New                    (&Ctrl+N)", 0));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266\357\274\210&F\357\274\211", 0));
        menuAsdf_G->setTitle(QApplication::translate("MainWindow", "\345\255\227\344\275\223(&W)", 0));
        menuAsdfasdf_G->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(G&)", 0));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251\357\274\210&H)", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
