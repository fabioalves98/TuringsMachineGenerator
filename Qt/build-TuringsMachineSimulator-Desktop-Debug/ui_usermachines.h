/********************************************************************************
** Form generated from reading UI file 'usermachines.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMACHINES_H
#define UI_USERMACHINES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMachines
{
public:
    QWidget *centralwidget;
    QPushButton *fileOpener;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *UserMachines)
    {
        if (UserMachines->objectName().isEmpty())
            UserMachines->setObjectName(QStringLiteral("UserMachines"));
        UserMachines->resize(1280, 720);
        centralwidget = new QWidget(UserMachines);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        fileOpener = new QPushButton(centralwidget);
        fileOpener->setObjectName(QStringLiteral("fileOpener"));
        fileOpener->setGeometry(QRect(210, 260, 80, 25));
        UserMachines->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserMachines);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        UserMachines->setMenuBar(menubar);
        statusbar = new QStatusBar(UserMachines);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UserMachines->setStatusBar(statusbar);
        toolBar = new QToolBar(UserMachines);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        UserMachines->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(UserMachines);

        QMetaObject::connectSlotsByName(UserMachines);
    } // setupUi

    void retranslateUi(QMainWindow *UserMachines)
    {
        UserMachines->setWindowTitle(QApplication::translate("UserMachines", "MainWindow", Q_NULLPTR));
        fileOpener->setText(QApplication::translate("UserMachines", "TableDebug", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("UserMachines", "File", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("UserMachines", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserMachines: public Ui_UserMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMACHINES_H
