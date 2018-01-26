/********************************************************************************
** Form generated from reading UI file 'randommachines.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMMACHINES_H
#define UI_RANDOMMACHINES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomMachines
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *stLabel;
    QLabel *syLabel;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *nameEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *stSel;
    QHBoxLayout *stLayout;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *sySel;
    QHBoxLayout *syLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QComboBox *initStCBox;
    QComboBox *blanckSyCBox;
    QLineEdit *haltStEdit;
    QTableWidget *randTable;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *randBut;
    QPushButton *saveBut;

    void setupUi(QMainWindow *RandomMachines)
    {
        if (RandomMachines->objectName().isEmpty())
            RandomMachines->setObjectName(QStringLiteral("RandomMachines"));
        RandomMachines->resize(800, 600);
        centralwidget = new QWidget(RandomMachines);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setMaximumSize(QSize(60, 27));
        QFont font;
        font.setPointSize(14);
        nameLabel->setFont(font);
        nameLabel->setFrameShape(QFrame::Panel);
        nameLabel->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(nameLabel);

        stLabel = new QLabel(centralwidget);
        stLabel->setObjectName(QStringLiteral("stLabel"));
        stLabel->setMaximumSize(QSize(64, 27));
        stLabel->setFont(font);
        stLabel->setFrameShape(QFrame::Panel);
        stLabel->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(stLabel);

        syLabel = new QLabel(centralwidget);
        syLabel->setObjectName(QStringLiteral("syLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(syLabel->sizePolicy().hasHeightForWidth());
        syLabel->setSizePolicy(sizePolicy);
        syLabel->setMaximumSize(QSize(82, 27));
        syLabel->setFont(font);
        syLabel->setFrameShape(QFrame::Panel);
        syLabel->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(syLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nameEdit = new QTextEdit(centralwidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setMaximumSize(QSize(16777215, 27));

        verticalLayout_2->addWidget(nameEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        stSel = new QSpinBox(centralwidget);
        stSel->setObjectName(QStringLiteral("stSel"));
        stSel->setMaximumSize(QSize(46, 26));

        horizontalLayout_3->addWidget(stSel);

        stLayout = new QHBoxLayout();
        stLayout->setObjectName(QStringLiteral("stLayout"));

        horizontalLayout_3->addLayout(stLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        sySel = new QSpinBox(centralwidget);
        sySel->setObjectName(QStringLiteral("sySel"));
        sySel->setMaximumSize(QSize(46, 26));

        horizontalLayout_4->addWidget(sySel);

        syLayout = new QHBoxLayout();
        syLayout->setObjectName(QStringLiteral("syLayout"));

        horizontalLayout_4->addLayout(syLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(101, 0));
        label->setMaximumSize(QSize(101, 27));
        label->setFont(font);
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(130, 0));
        label_2->setMaximumSize(QSize(130, 27));
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(91, 0));
        label_3->setMaximumSize(QSize(91, 27));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        initStCBox = new QComboBox(centralwidget);
        initStCBox->setObjectName(QStringLiteral("initStCBox"));
        initStCBox->setMaximumSize(QSize(41, 16777215));

        verticalLayout_4->addWidget(initStCBox);

        blanckSyCBox = new QComboBox(centralwidget);
        blanckSyCBox->setObjectName(QStringLiteral("blanckSyCBox"));
        blanckSyCBox->setMaximumSize(QSize(41, 16777215));

        verticalLayout_4->addWidget(blanckSyCBox);

        haltStEdit = new QLineEdit(centralwidget);
        haltStEdit->setObjectName(QStringLiteral("haltStEdit"));
        haltStEdit->setMaximumSize(QSize(41, 16777215));
        haltStEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(haltStEdit);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout);

        randTable = new QTableWidget(centralwidget);
        randTable->setObjectName(QStringLiteral("randTable"));

        verticalLayout_5->addWidget(randTable);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        randBut = new QPushButton(centralwidget);
        randBut->setObjectName(QStringLiteral("randBut"));
        QFont font1;
        font1.setPointSize(10);
        randBut->setFont(font1);

        horizontalLayout_5->addWidget(randBut);

        saveBut = new QPushButton(centralwidget);
        saveBut->setObjectName(QStringLiteral("saveBut"));
        saveBut->setFont(font1);

        horizontalLayout_5->addWidget(saveBut);


        verticalLayout_5->addLayout(horizontalLayout_5);

        RandomMachines->setCentralWidget(centralwidget);

        retranslateUi(RandomMachines);

        QMetaObject::connectSlotsByName(RandomMachines);
    } // setupUi

    void retranslateUi(QMainWindow *RandomMachines)
    {
        RandomMachines->setWindowTitle(QApplication::translate("RandomMachines", "MainWindow", nullptr));
        nameLabel->setText(QApplication::translate("RandomMachines", "Name", nullptr));
        stLabel->setText(QApplication::translate("RandomMachines", "States", nullptr));
        syLabel->setText(QApplication::translate("RandomMachines", "Symbols", nullptr));
        label->setText(QApplication::translate("RandomMachines", "Initial State", nullptr));
        label_2->setText(QApplication::translate("RandomMachines", "Blanck Symbol", nullptr));
        label_3->setText(QApplication::translate("RandomMachines", "Halt State", nullptr));
        haltStEdit->setPlaceholderText(QApplication::translate("RandomMachines", "H", nullptr));
        randBut->setText(QApplication::translate("RandomMachines", "Random", nullptr));
        saveBut->setText(QApplication::translate("RandomMachines", "Save Table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RandomMachines: public Ui_RandomMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMMACHINES_H
