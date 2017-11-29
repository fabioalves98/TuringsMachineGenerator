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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMachines
{
public:
    QWidget *centralwidget;
    QPushButton *fileOpener;
    QListWidget *tableList;
    QLabel *label;
    QTableWidget *tableView;
    QLabel *label_2;
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
        fileOpener->setGeometry(QRect(10, 590, 80, 25));
        tableList = new QListWidget(centralwidget);
        tableList->setObjectName(QStringLiteral("tableList"));
        tableList->setGeometry(QRect(10, 40, 261, 541));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 261, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);
        tableView = new QTableWidget(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(280, 40, 441, 281));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 10, 441, 31));
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setAlignment(Qt::AlignCenter);
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
        fileOpener->setText(QApplication::translate("UserMachines", "Add Table", Q_NULLPTR));
        label->setText(QApplication::translate("UserMachines", "Machine's Tables", Q_NULLPTR));
        label_2->setText(QApplication::translate("UserMachines", "Table's Specification", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("UserMachines", "File", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("UserMachines", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserMachines: public Ui_UserMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMACHINES_H
