/********************************************************************************
** Form generated from reading UI file 'randommachines.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMMACHINES_H
#define UI_RANDOMMACHINES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomMachines
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *stLabel;
    QSpinBox *stSel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *syLabel;
    QSpinBox *sySel;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *randTable;
    QPushButton *randBut;

    void setupUi(QMainWindow *RandomMachines)
    {
        if (RandomMachines->objectName().isEmpty())
            RandomMachines->setObjectName(QStringLiteral("RandomMachines"));
        RandomMachines->resize(800, 600);
        centralwidget = new QWidget(RandomMachines);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        stLabel = new QLabel(centralwidget);
        stLabel->setObjectName(QStringLiteral("stLabel"));
        QFont font;
        font.setPointSize(14);
        stLabel->setFont(font);
        stLabel->setFrameShape(QFrame::Panel);
        stLabel->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(stLabel);

        stSel = new QSpinBox(centralwidget);
        stSel->setObjectName(QStringLiteral("stSel"));

        horizontalLayout->addWidget(stSel);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        syLabel = new QLabel(centralwidget);
        syLabel->setObjectName(QStringLiteral("syLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(syLabel->sizePolicy().hasHeightForWidth());
        syLabel->setSizePolicy(sizePolicy);
        syLabel->setFont(font);
        syLabel->setFrameShape(QFrame::Panel);
        syLabel->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(syLabel);

        sySel = new QSpinBox(centralwidget);
        sySel->setObjectName(QStringLiteral("sySel"));

        horizontalLayout_2->addWidget(sySel);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        randTable = new QTableWidget(centralwidget);
        randTable->setObjectName(QStringLiteral("randTable"));

        verticalLayout->addWidget(randTable);

        randBut = new QPushButton(centralwidget);
        randBut->setObjectName(QStringLiteral("randBut"));

        verticalLayout->addWidget(randBut);

        RandomMachines->setCentralWidget(centralwidget);

        retranslateUi(RandomMachines);

        QMetaObject::connectSlotsByName(RandomMachines);
    } // setupUi

    void retranslateUi(QMainWindow *RandomMachines)
    {
        RandomMachines->setWindowTitle(QApplication::translate("RandomMachines", "MainWindow", Q_NULLPTR));
        stLabel->setText(QApplication::translate("RandomMachines", "States", Q_NULLPTR));
        syLabel->setText(QApplication::translate("RandomMachines", "Symbols", Q_NULLPTR));
        randBut->setText(QApplication::translate("RandomMachines", "Random", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RandomMachines: public Ui_RandomMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMMACHINES_H
