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
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_2;
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
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QComboBox *initStCBox;
    QLineEdit *haltStEdit;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *randTable;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *randBut;
    QPushButton *saveBut;

    void setupUi(QMainWindow *RandomMachines)
    {
        if (RandomMachines->objectName().isEmpty())
            RandomMachines->setObjectName(QStringLiteral("RandomMachines"));
        RandomMachines->resize(800, 567);
        centralwidget = new QWidget(RandomMachines);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(14);
        nameLabel->setFont(font);
        nameLabel->setFrameShape(QFrame::Panel);
        nameLabel->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(nameLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        stLabel = new QLabel(centralwidget);
        stLabel->setObjectName(QStringLiteral("stLabel"));
        stLabel->setMaximumSize(QSize(16777215, 16777215));
        stLabel->setFont(font);
        stLabel->setFrameShape(QFrame::Panel);
        stLabel->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(stLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        syLabel = new QLabel(centralwidget);
        syLabel->setObjectName(QStringLiteral("syLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(syLabel->sizePolicy().hasHeightForWidth());
        syLabel->setSizePolicy(sizePolicy);
        syLabel->setMaximumSize(QSize(16777215, 16777215));
        syLabel->setFont(font);
        syLabel->setFrameShape(QFrame::Panel);
        syLabel->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(syLabel);


        horizontalLayout_6->addLayout(verticalLayout);

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
        QFont font1;
        font1.setPointSize(10);
        stSel->setFont(font1);
        stSel->setMaximum(25);

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
        sySel->setFont(font1);
        sySel->setMaximum(10);

        horizontalLayout_4->addWidget(sySel);

        syLayout = new QHBoxLayout();
        syLayout->setObjectName(QStringLiteral("syLayout"));

        horizontalLayout_4->addLayout(syLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 26));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setFont(font);
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 26));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        initStCBox = new QComboBox(centralwidget);
        initStCBox->setObjectName(QStringLiteral("initStCBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(initStCBox->sizePolicy().hasHeightForWidth());
        initStCBox->setSizePolicy(sizePolicy1);
        initStCBox->setMinimumSize(QSize(40, 26));
        initStCBox->setMaximumSize(QSize(16777215, 16777215));
        initStCBox->setFont(font1);

        verticalLayout_4->addWidget(initStCBox);

        haltStEdit = new QLineEdit(centralwidget);
        haltStEdit->setObjectName(QStringLiteral("haltStEdit"));
        sizePolicy1.setHeightForWidth(haltStEdit->sizePolicy().hasHeightForWidth());
        haltStEdit->setSizePolicy(sizePolicy1);
        haltStEdit->setMinimumSize(QSize(40, 26));
        haltStEdit->setMaximumSize(QSize(16777215, 16777215));
        haltStEdit->setFont(font1);
        haltStEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(haltStEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_6);

        randTable = new QTableWidget(centralwidget);
        randTable->setObjectName(QStringLiteral("randTable"));

        verticalLayout_5->addWidget(randTable);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        randBut = new QPushButton(centralwidget);
        randBut->setObjectName(QStringLiteral("randBut"));
        QFont font2;
        font2.setPointSize(12);
        randBut->setFont(font2);

        horizontalLayout_5->addWidget(randBut);

        saveBut = new QPushButton(centralwidget);
        saveBut->setObjectName(QStringLiteral("saveBut"));
        saveBut->setFont(font2);

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
