/********************************************************************************
** Form generated from reading UI file 'editmachines.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITMACHINES_H
#define UI_EDITMACHINES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditMachines
{
public:
    QWidget *zCentralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *zTitleLayout;
    QSpacerItem *zSpacer_2;
    QLabel *zLabel;
    QSpacerItem *zSpacer;
    QTableWidget *tableView;
    QHBoxLayout *zActionLayout;
    QSpacerItem *zSpacer_5;
    QLabel *zLabel_4;
    QComboBox *writeCBox;
    QSpacerItem *zSpacer_3;
    QLabel *zLabel_3;
    QComboBox *moveCBox;
    QSpacerItem *zSpacer_4;
    QLabel *zLabel_2;
    QComboBox *nextCBox;
    QSpacerItem *zSpacer_6;
    QHBoxLayout *zStateLayout;
    QSpacerItem *zSpacer_8;
    QLabel *zLabel_6;
    QComboBox *inStateCBox;
    QSpacerItem *zSpacer_7;
    QLabel *zLabel_5;
    QComboBox *hltStateCBox;
    QSpacerItem *zSpacer_9;
    QHBoxLayout *zButtonLayout;
    QPushButton *changeBut;
    QPushButton *saveBut;

    void setupUi(QMainWindow *EditMachines)
    {
        if (EditMachines->objectName().isEmpty())
            EditMachines->setObjectName(QStringLiteral("EditMachines"));
        EditMachines->resize(800, 600);
        zCentralwidget = new QWidget(EditMachines);
        zCentralwidget->setObjectName(QStringLiteral("zCentralwidget"));
        verticalLayout = new QVBoxLayout(zCentralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        zTitleLayout = new QHBoxLayout();
        zTitleLayout->setObjectName(QStringLiteral("zTitleLayout"));
        zSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zTitleLayout->addItem(zSpacer_2);

        zLabel = new QLabel(zCentralwidget);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        zLabel->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(16);
        zLabel->setFont(font);
        zLabel->setFrameShape(QFrame::Panel);
        zLabel->setFrameShadow(QFrame::Raised);
        zLabel->setAlignment(Qt::AlignCenter);
        zLabel->setMargin(2);

        zTitleLayout->addWidget(zLabel);

        zSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zTitleLayout->addItem(zSpacer);


        verticalLayout->addLayout(zTitleLayout);

        tableView = new QTableWidget(zCentralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        zActionLayout = new QHBoxLayout();
        zActionLayout->setObjectName(QStringLiteral("zActionLayout"));
        zSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zActionLayout->addItem(zSpacer_5);

        zLabel_4 = new QLabel(zCentralwidget);
        zLabel_4->setObjectName(QStringLiteral("zLabel_4"));
        zLabel_4->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(14);
        zLabel_4->setFont(font1);
        zLabel_4->setFrameShape(QFrame::Panel);
        zLabel_4->setFrameShadow(QFrame::Raised);
        zLabel_4->setAlignment(Qt::AlignCenter);

        zActionLayout->addWidget(zLabel_4);

        writeCBox = new QComboBox(zCentralwidget);
        writeCBox->setObjectName(QStringLiteral("writeCBox"));
        writeCBox->setMaximumSize(QSize(51, 33));
        writeCBox->setFont(font1);

        zActionLayout->addWidget(writeCBox);

        zSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zActionLayout->addItem(zSpacer_3);

        zLabel_3 = new QLabel(zCentralwidget);
        zLabel_3->setObjectName(QStringLiteral("zLabel_3"));
        zLabel_3->setMinimumSize(QSize(0, 0));
        zLabel_3->setFont(font1);
        zLabel_3->setFrameShape(QFrame::Panel);
        zLabel_3->setFrameShadow(QFrame::Raised);
        zLabel_3->setAlignment(Qt::AlignCenter);

        zActionLayout->addWidget(zLabel_3);

        moveCBox = new QComboBox(zCentralwidget);
        moveCBox->setObjectName(QStringLiteral("moveCBox"));
        moveCBox->setMaximumSize(QSize(93, 33));
        moveCBox->setFont(font1);

        zActionLayout->addWidget(moveCBox);

        zSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zActionLayout->addItem(zSpacer_4);

        zLabel_2 = new QLabel(zCentralwidget);
        zLabel_2->setObjectName(QStringLiteral("zLabel_2"));
        zLabel_2->setMinimumSize(QSize(0, 0));
        zLabel_2->setFont(font1);
        zLabel_2->setFrameShape(QFrame::Panel);
        zLabel_2->setFrameShadow(QFrame::Raised);
        zLabel_2->setAlignment(Qt::AlignCenter);

        zActionLayout->addWidget(zLabel_2);

        nextCBox = new QComboBox(zCentralwidget);
        nextCBox->setObjectName(QStringLiteral("nextCBox"));
        nextCBox->setMaximumSize(QSize(51, 33));
        nextCBox->setFont(font1);

        zActionLayout->addWidget(nextCBox);

        zSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zActionLayout->addItem(zSpacer_6);


        verticalLayout->addLayout(zActionLayout);

        zStateLayout = new QHBoxLayout();
        zStateLayout->setObjectName(QStringLiteral("zStateLayout"));
        zSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zStateLayout->addItem(zSpacer_8);

        zLabel_6 = new QLabel(zCentralwidget);
        zLabel_6->setObjectName(QStringLiteral("zLabel_6"));
        zLabel_6->setMinimumSize(QSize(0, 0));
        zLabel_6->setMaximumSize(QSize(16777215, 16777215));
        zLabel_6->setFont(font1);
        zLabel_6->setFrameShape(QFrame::Panel);
        zLabel_6->setFrameShadow(QFrame::Raised);
        zLabel_6->setAlignment(Qt::AlignCenter);

        zStateLayout->addWidget(zLabel_6);

        inStateCBox = new QComboBox(zCentralwidget);
        inStateCBox->setObjectName(QStringLiteral("inStateCBox"));
        inStateCBox->setMaximumSize(QSize(51, 31));
        inStateCBox->setFont(font1);

        zStateLayout->addWidget(inStateCBox);

        zSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zStateLayout->addItem(zSpacer_7);

        zLabel_5 = new QLabel(zCentralwidget);
        zLabel_5->setObjectName(QStringLiteral("zLabel_5"));
        zLabel_5->setMinimumSize(QSize(0, 0));
        zLabel_5->setFont(font1);
        zLabel_5->setFrameShape(QFrame::Panel);
        zLabel_5->setFrameShadow(QFrame::Raised);
        zLabel_5->setAlignment(Qt::AlignCenter);

        zStateLayout->addWidget(zLabel_5);

        hltStateCBox = new QComboBox(zCentralwidget);
        hltStateCBox->setObjectName(QStringLiteral("hltStateCBox"));
        hltStateCBox->setMaximumSize(QSize(51, 31));
        hltStateCBox->setFont(font1);

        zStateLayout->addWidget(hltStateCBox);

        zSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zStateLayout->addItem(zSpacer_9);


        verticalLayout->addLayout(zStateLayout);

        zButtonLayout = new QHBoxLayout();
        zButtonLayout->setObjectName(QStringLiteral("zButtonLayout"));
        changeBut = new QPushButton(zCentralwidget);
        changeBut->setObjectName(QStringLiteral("changeBut"));
        QFont font2;
        font2.setPointSize(12);
        changeBut->setFont(font2);

        zButtonLayout->addWidget(changeBut);

        saveBut = new QPushButton(zCentralwidget);
        saveBut->setObjectName(QStringLiteral("saveBut"));
        saveBut->setFont(font2);

        zButtonLayout->addWidget(saveBut);


        verticalLayout->addLayout(zButtonLayout);

        EditMachines->setCentralWidget(zCentralwidget);

        retranslateUi(EditMachines);

        QMetaObject::connectSlotsByName(EditMachines);
    } // setupUi

    void retranslateUi(QMainWindow *EditMachines)
    {
        EditMachines->setWindowTitle(QApplication::translate("EditMachines", "MainWindow", nullptr));
        zLabel->setText(QApplication::translate("EditMachines", " Select the cells you want to edit ", nullptr));
        zLabel_4->setText(QApplication::translate("EditMachines", " Write Symbol ", nullptr));
        zLabel_3->setText(QApplication::translate("EditMachines", " Move Tape ", nullptr));
        zLabel_2->setText(QApplication::translate("EditMachines", " Next State ", nullptr));
        zLabel_6->setText(QApplication::translate("EditMachines", " Initial State ", nullptr));
        zLabel_5->setText(QApplication::translate("EditMachines", " Halt State ", nullptr));
        changeBut->setText(QApplication::translate("EditMachines", "Change", nullptr));
        saveBut->setText(QApplication::translate("EditMachines", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditMachines: public Ui_EditMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMACHINES_H
