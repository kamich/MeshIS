/********************************************************************************
** Form generated from reading UI file 'helloqt.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOQT_H
#define UI_HELLOQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelloQTClass
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QFrame *line;
    QFrame *line_2;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuRecently_opened_files;

    void setupUi(QMainWindow *HelloQTClass)
    {
        if (HelloQTClass->objectName().isEmpty())
            HelloQTClass->setObjectName(QStringLiteral("HelloQTClass"));
        HelloQTClass->resize(549, 514);
        actionOpen = new QAction(HelloQTClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(HelloQTClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(HelloQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(40, 50, 461, 381));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 10, 701, 20));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 450, 701, 20));
        line_2->setFrameShadow(QFrame::Sunken);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        HelloQTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(HelloQTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HelloQTClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(HelloQTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 549, 26));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuRecently_opened_files = new QMenu(menuMenu);
        menuRecently_opened_files->setObjectName(QStringLiteral("menuRecently_opened_files"));
        HelloQTClass->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addSeparator();
        menuMenu->addAction(actionOpen);
        menuMenu->addAction(menuRecently_opened_files->menuAction());
        menuMenu->addSeparator();
        menuMenu->addAction(actionExit);

        retranslateUi(HelloQTClass);
        QObject::connect(actionExit, SIGNAL(triggered()), HelloQTClass, SLOT(close()));

        QMetaObject::connectSlotsByName(HelloQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *HelloQTClass)
    {
        HelloQTClass->setWindowTitle(QApplication::translate("HelloQTClass", "HelloQT", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("HelloQTClass", "Open", Q_NULLPTR));
        actionOpen->setShortcut(QApplication::translate("HelloQTClass", "Ctrl+O", Q_NULLPTR));
        actionExit->setText(QApplication::translate("HelloQTClass", "Exit", Q_NULLPTR));
        actionExit->setShortcut(QApplication::translate("HelloQTClass", "Ctrl+E", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("HelloQTClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("HelloQTClass", "File", Q_NULLPTR));
        menuRecently_opened_files->setTitle(QApplication::translate("HelloQTClass", "Recently opened files", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HelloQTClass: public Ui_HelloQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOQT_H
