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
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacer1;
    QLabel *writeLabel;
    QComboBox *writeCBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *moveLabel;
    QComboBox *moveCBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *nextLabel;
    QComboBox *nextCBox;
    QSpacerItem *spacer2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *inStateLabel;
    QComboBox *inStateCBox;
    QSpacerItem *horizontalSpacer_5;
    QLabel *hltStateLabel;
    QComboBox *hltStateCBox;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *changeBut;
    QPushButton *saveBut;

    void setupUi(QMainWindow *EditMachines)
    {
        if (EditMachines->objectName().isEmpty())
            EditMachines->setObjectName(QStringLiteral("EditMachines"));
        EditMachines->resize(800, 600);
        centralwidget = new QWidget(EditMachines);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(2);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableWidget(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer1);

        writeLabel = new QLabel(centralwidget);
        writeLabel->setObjectName(QStringLiteral("writeLabel"));
        writeLabel->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(14);
        writeLabel->setFont(font1);
        writeLabel->setFrameShape(QFrame::Panel);
        writeLabel->setFrameShadow(QFrame::Raised);
        writeLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(writeLabel);

        writeCBox = new QComboBox(centralwidget);
        writeCBox->setObjectName(QStringLiteral("writeCBox"));
        writeCBox->setMaximumSize(QSize(51, 33));
        writeCBox->setFont(font1);

        horizontalLayout->addWidget(writeCBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        moveLabel = new QLabel(centralwidget);
        moveLabel->setObjectName(QStringLiteral("moveLabel"));
        moveLabel->setMinimumSize(QSize(0, 0));
        moveLabel->setFont(font1);
        moveLabel->setFrameShape(QFrame::Panel);
        moveLabel->setFrameShadow(QFrame::Raised);
        moveLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(moveLabel);

        moveCBox = new QComboBox(centralwidget);
        moveCBox->setObjectName(QStringLiteral("moveCBox"));
        moveCBox->setMaximumSize(QSize(93, 33));
        moveCBox->setFont(font1);

        horizontalLayout->addWidget(moveCBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        nextLabel = new QLabel(centralwidget);
        nextLabel->setObjectName(QStringLiteral("nextLabel"));
        nextLabel->setMinimumSize(QSize(0, 0));
        nextLabel->setFont(font1);
        nextLabel->setFrameShape(QFrame::Panel);
        nextLabel->setFrameShadow(QFrame::Raised);
        nextLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(nextLabel);

        nextCBox = new QComboBox(centralwidget);
        nextCBox->setObjectName(QStringLiteral("nextCBox"));
        nextCBox->setMaximumSize(QSize(51, 33));
        nextCBox->setFont(font1);

        horizontalLayout->addWidget(nextCBox);

        spacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        inStateLabel = new QLabel(centralwidget);
        inStateLabel->setObjectName(QStringLiteral("inStateLabel"));
        inStateLabel->setMinimumSize(QSize(0, 0));
        inStateLabel->setMaximumSize(QSize(16777215, 16777215));
        inStateLabel->setFont(font1);
        inStateLabel->setFrameShape(QFrame::Panel);
        inStateLabel->setFrameShadow(QFrame::Raised);
        inStateLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(inStateLabel);

        inStateCBox = new QComboBox(centralwidget);
        inStateCBox->setObjectName(QStringLiteral("inStateCBox"));
        inStateCBox->setMaximumSize(QSize(51, 31));
        inStateCBox->setFont(font1);

        horizontalLayout_3->addWidget(inStateCBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        hltStateLabel = new QLabel(centralwidget);
        hltStateLabel->setObjectName(QStringLiteral("hltStateLabel"));
        hltStateLabel->setMinimumSize(QSize(0, 0));
        hltStateLabel->setFont(font1);
        hltStateLabel->setFrameShape(QFrame::Panel);
        hltStateLabel->setFrameShadow(QFrame::Raised);
        hltStateLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(hltStateLabel);

        hltStateCBox = new QComboBox(centralwidget);
        hltStateCBox->setObjectName(QStringLiteral("hltStateCBox"));
        hltStateCBox->setMaximumSize(QSize(51, 31));
        hltStateCBox->setFont(font1);

        horizontalLayout_3->addWidget(hltStateCBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        changeBut = new QPushButton(centralwidget);
        changeBut->setObjectName(QStringLiteral("changeBut"));
        QFont font2;
        font2.setPointSize(12);
        changeBut->setFont(font2);

        horizontalLayout_5->addWidget(changeBut);

        saveBut = new QPushButton(centralwidget);
        saveBut->setObjectName(QStringLiteral("saveBut"));
        saveBut->setFont(font2);

        horizontalLayout_5->addWidget(saveBut);


        verticalLayout->addLayout(horizontalLayout_5);

        EditMachines->setCentralWidget(centralwidget);

        retranslateUi(EditMachines);

        QMetaObject::connectSlotsByName(EditMachines);
    } // setupUi

    void retranslateUi(QMainWindow *EditMachines)
    {
        EditMachines->setWindowTitle(QApplication::translate("EditMachines", "MainWindow", nullptr));
        label->setText(QApplication::translate("EditMachines", " Select the cells you want to edit ", nullptr));
        writeLabel->setText(QApplication::translate("EditMachines", " Write Symbol ", nullptr));
        moveLabel->setText(QApplication::translate("EditMachines", " Move Tape ", nullptr));
        nextLabel->setText(QApplication::translate("EditMachines", " Next State ", nullptr));
        inStateLabel->setText(QApplication::translate("EditMachines", " Initial State ", nullptr));
        hltStateLabel->setText(QApplication::translate("EditMachines", " Halt State ", nullptr));
        changeBut->setText(QApplication::translate("EditMachines", "Change", nullptr));
        saveBut->setText(QApplication::translate("EditMachines", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditMachines: public Ui_EditMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMACHINES_H
