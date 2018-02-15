/********************************************************************************
** Form generated from reading UI file 'randomtapes.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMTAPES_H
#define UI_RANDOMTAPES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomTapes
{
public:
    QWidget *zCentralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *zTopLayout;
    QVBoxLayout *zLabels;
    QLabel *zLabel_2;
    QLabel *zLabel_4;
    QLabel *zLabel_3;
    QLabel *zLabel;
    QVBoxLayout *zValues;
    QHBoxLayout *zNameLayout;
    QLineEdit *nameEdit;
    QSpacerItem *zSpacer;
    QHBoxLayout *zSymbolsLayout;
    QSpinBox *symSBox;
    QHBoxLayout *symLayout;
    QSpacerItem *zSpacer_2;
    QHBoxLayout *zSizeLayout;
    QSpinBox *sizeSBox;
    QSpacerItem *zSpacer_3;
    QHBoxLayout *zBSymLayout;
    QLineEdit *bSymEdit;
    QSpacerItem *zSpacer_4;
    QListWidget *tapeList;
    QHBoxLayout *zButtonLayout;
    QPushButton *randBt;
    QPushButton *saveBt;

    void setupUi(QMainWindow *RandomTapes)
    {
        if (RandomTapes->objectName().isEmpty())
            RandomTapes->setObjectName(QStringLiteral("RandomTapes"));
        RandomTapes->resize(800, 235);
        zCentralwidget = new QWidget(RandomTapes);
        zCentralwidget->setObjectName(QStringLiteral("zCentralwidget"));
        verticalLayout = new QVBoxLayout(zCentralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        zTopLayout = new QHBoxLayout();
        zTopLayout->setObjectName(QStringLiteral("zTopLayout"));
        zLabels = new QVBoxLayout();
        zLabels->setObjectName(QStringLiteral("zLabels"));
        zLabel_2 = new QLabel(zCentralwidget);
        zLabel_2->setObjectName(QStringLiteral("zLabel_2"));
        QFont font;
        font.setPointSize(14);
        zLabel_2->setFont(font);
        zLabel_2->setFrameShape(QFrame::Panel);
        zLabel_2->setFrameShadow(QFrame::Raised);
        zLabel_2->setMargin(0);

        zLabels->addWidget(zLabel_2);

        zLabel_4 = new QLabel(zCentralwidget);
        zLabel_4->setObjectName(QStringLiteral("zLabel_4"));
        zLabel_4->setFont(font);
        zLabel_4->setFrameShape(QFrame::Panel);
        zLabel_4->setFrameShadow(QFrame::Raised);
        zLabel_4->setMargin(0);

        zLabels->addWidget(zLabel_4);

        zLabel_3 = new QLabel(zCentralwidget);
        zLabel_3->setObjectName(QStringLiteral("zLabel_3"));
        zLabel_3->setFont(font);
        zLabel_3->setFrameShape(QFrame::Panel);
        zLabel_3->setFrameShadow(QFrame::Raised);
        zLabel_3->setMargin(0);

        zLabels->addWidget(zLabel_3);

        zLabel = new QLabel(zCentralwidget);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        zLabel->setFont(font);
        zLabel->setFrameShape(QFrame::Panel);
        zLabel->setFrameShadow(QFrame::Raised);
        zLabel->setMargin(0);

        zLabels->addWidget(zLabel);


        zTopLayout->addLayout(zLabels);

        zValues = new QVBoxLayout();
        zValues->setObjectName(QStringLiteral("zValues"));
        zNameLayout = new QHBoxLayout();
        zNameLayout->setObjectName(QStringLiteral("zNameLayout"));
        nameEdit = new QLineEdit(zCentralwidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        nameEdit->setFont(font1);

        zNameLayout->addWidget(nameEdit);

        zSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zNameLayout->addItem(zSpacer);


        zValues->addLayout(zNameLayout);

        zSymbolsLayout = new QHBoxLayout();
        zSymbolsLayout->setObjectName(QStringLiteral("zSymbolsLayout"));
        symSBox = new QSpinBox(zCentralwidget);
        symSBox->setObjectName(QStringLiteral("symSBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(symSBox->sizePolicy().hasHeightForWidth());
        symSBox->setSizePolicy(sizePolicy1);
        symSBox->setFont(font1);
        symSBox->setMinimum(0);
        symSBox->setMaximum(10);
        symSBox->setValue(0);

        zSymbolsLayout->addWidget(symSBox);

        symLayout = new QHBoxLayout();
        symLayout->setObjectName(QStringLiteral("symLayout"));

        zSymbolsLayout->addLayout(symLayout);

        zSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zSymbolsLayout->addItem(zSpacer_2);


        zValues->addLayout(zSymbolsLayout);

        zSizeLayout = new QHBoxLayout();
        zSizeLayout->setObjectName(QStringLiteral("zSizeLayout"));
        sizeSBox = new QSpinBox(zCentralwidget);
        sizeSBox->setObjectName(QStringLiteral("sizeSBox"));
        sizePolicy1.setHeightForWidth(sizeSBox->sizePolicy().hasHeightForWidth());
        sizeSBox->setSizePolicy(sizePolicy1);
        sizeSBox->setFont(font1);
        sizeSBox->setMinimum(0);
        sizeSBox->setMaximum(500);
        sizeSBox->setValue(0);

        zSizeLayout->addWidget(sizeSBox);

        zSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zSizeLayout->addItem(zSpacer_3);


        zValues->addLayout(zSizeLayout);

        zBSymLayout = new QHBoxLayout();
        zBSymLayout->setObjectName(QStringLiteral("zBSymLayout"));
        bSymEdit = new QLineEdit(zCentralwidget);
        bSymEdit->setObjectName(QStringLiteral("bSymEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bSymEdit->sizePolicy().hasHeightForWidth());
        bSymEdit->setSizePolicy(sizePolicy2);
        bSymEdit->setMinimumSize(QSize(43, 0));
        bSymEdit->setFont(font1);
        bSymEdit->setMaxLength(1);
        bSymEdit->setAlignment(Qt::AlignCenter);

        zBSymLayout->addWidget(bSymEdit);

        zSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zBSymLayout->addItem(zSpacer_4);


        zValues->addLayout(zBSymLayout);


        zTopLayout->addLayout(zValues);


        verticalLayout->addLayout(zTopLayout);

        tapeList = new QListWidget(zCentralwidget);
        tapeList->setObjectName(QStringLiteral("tapeList"));
        tapeList->setMaximumSize(QSize(16777215, 48));

        verticalLayout->addWidget(tapeList);

        zButtonLayout = new QHBoxLayout();
        zButtonLayout->setObjectName(QStringLiteral("zButtonLayout"));
        randBt = new QPushButton(zCentralwidget);
        randBt->setObjectName(QStringLiteral("randBt"));
        QFont font2;
        font2.setPointSize(12);
        randBt->setFont(font2);

        zButtonLayout->addWidget(randBt);

        saveBt = new QPushButton(zCentralwidget);
        saveBt->setObjectName(QStringLiteral("saveBt"));
        saveBt->setFont(font2);

        zButtonLayout->addWidget(saveBt);


        verticalLayout->addLayout(zButtonLayout);

        RandomTapes->setCentralWidget(zCentralwidget);

        retranslateUi(RandomTapes);

        QMetaObject::connectSlotsByName(RandomTapes);
    } // setupUi

    void retranslateUi(QMainWindow *RandomTapes)
    {
        RandomTapes->setWindowTitle(QApplication::translate("RandomTapes", "MainWindow", nullptr));
        zLabel_2->setText(QApplication::translate("RandomTapes", "Name", nullptr));
        zLabel_4->setText(QApplication::translate("RandomTapes", "Symbols", nullptr));
        zLabel_3->setText(QApplication::translate("RandomTapes", "Size", nullptr));
        zLabel->setText(QApplication::translate("RandomTapes", "Blank Symbol", nullptr));
        randBt->setText(QApplication::translate("RandomTapes", "Random", nullptr));
        saveBt->setText(QApplication::translate("RandomTapes", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RandomTapes: public Ui_RandomTapes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMTAPES_H
