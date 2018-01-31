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
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *zTopLayout;
    QVBoxLayout *zLabels;
    QLabel *zNameLabel;
    QLabel *zSymbolsLabel;
    QLabel *zSizeLabel;
    QLabel *zBSymLabel;
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
    QHBoxLayout *horizontalLayout;
    QPushButton *randBt;
    QPushButton *saveBt;

    void setupUi(QMainWindow *RandomTapes)
    {
        if (RandomTapes->objectName().isEmpty())
            RandomTapes->setObjectName(QStringLiteral("RandomTapes"));
        RandomTapes->resize(800, 235);
        centralwidget = new QWidget(RandomTapes);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        zTopLayout = new QHBoxLayout();
        zTopLayout->setObjectName(QStringLiteral("zTopLayout"));
        zLabels = new QVBoxLayout();
        zLabels->setObjectName(QStringLiteral("zLabels"));
        zNameLabel = new QLabel(centralwidget);
        zNameLabel->setObjectName(QStringLiteral("zNameLabel"));
        QFont font;
        font.setPointSize(14);
        zNameLabel->setFont(font);
        zNameLabel->setFrameShape(QFrame::Panel);
        zNameLabel->setFrameShadow(QFrame::Raised);
        zNameLabel->setMargin(0);

        zLabels->addWidget(zNameLabel);

        zSymbolsLabel = new QLabel(centralwidget);
        zSymbolsLabel->setObjectName(QStringLiteral("zSymbolsLabel"));
        zSymbolsLabel->setFont(font);
        zSymbolsLabel->setFrameShape(QFrame::Panel);
        zSymbolsLabel->setFrameShadow(QFrame::Raised);
        zSymbolsLabel->setMargin(0);

        zLabels->addWidget(zSymbolsLabel);

        zSizeLabel = new QLabel(centralwidget);
        zSizeLabel->setObjectName(QStringLiteral("zSizeLabel"));
        zSizeLabel->setFont(font);
        zSizeLabel->setFrameShape(QFrame::Panel);
        zSizeLabel->setFrameShadow(QFrame::Raised);
        zSizeLabel->setMargin(0);

        zLabels->addWidget(zSizeLabel);

        zBSymLabel = new QLabel(centralwidget);
        zBSymLabel->setObjectName(QStringLiteral("zBSymLabel"));
        zBSymLabel->setFont(font);
        zBSymLabel->setFrameShape(QFrame::Panel);
        zBSymLabel->setFrameShadow(QFrame::Raised);
        zBSymLabel->setMargin(0);

        zLabels->addWidget(zBSymLabel);


        zTopLayout->addLayout(zLabels);

        zValues = new QVBoxLayout();
        zValues->setObjectName(QStringLiteral("zValues"));
        zNameLayout = new QHBoxLayout();
        zNameLayout->setObjectName(QStringLiteral("zNameLayout"));
        nameEdit = new QLineEdit(centralwidget);
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
        symSBox = new QSpinBox(centralwidget);
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
        sizeSBox = new QSpinBox(centralwidget);
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
        bSymEdit = new QLineEdit(centralwidget);
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

        tapeList = new QListWidget(centralwidget);
        tapeList->setObjectName(QStringLiteral("tapeList"));
        tapeList->setMaximumSize(QSize(16777215, 48));

        verticalLayout->addWidget(tapeList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        randBt = new QPushButton(centralwidget);
        randBt->setObjectName(QStringLiteral("randBt"));
        QFont font2;
        font2.setPointSize(12);
        randBt->setFont(font2);

        horizontalLayout->addWidget(randBt);

        saveBt = new QPushButton(centralwidget);
        saveBt->setObjectName(QStringLiteral("saveBt"));
        saveBt->setFont(font2);

        horizontalLayout->addWidget(saveBt);


        verticalLayout->addLayout(horizontalLayout);

        RandomTapes->setCentralWidget(centralwidget);

        retranslateUi(RandomTapes);

        QMetaObject::connectSlotsByName(RandomTapes);
    } // setupUi

    void retranslateUi(QMainWindow *RandomTapes)
    {
        RandomTapes->setWindowTitle(QApplication::translate("RandomTapes", "MainWindow", nullptr));
        zNameLabel->setText(QApplication::translate("RandomTapes", "Name", nullptr));
        zSymbolsLabel->setText(QApplication::translate("RandomTapes", "Symbols", nullptr));
        zSizeLabel->setText(QApplication::translate("RandomTapes", "Size", nullptr));
        zBSymLabel->setText(QApplication::translate("RandomTapes", "Blanck Symbol", nullptr));
        randBt->setText(QApplication::translate("RandomTapes", "Random", nullptr));
        saveBt->setText(QApplication::translate("RandomTapes", "Save Tape", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RandomTapes: public Ui_RandomTapes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMTAPES_H
