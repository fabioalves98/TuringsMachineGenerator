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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomMachines
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;

    void setupUi(QMainWindow *RandomMachines)
    {
        if (RandomMachines->objectName().isEmpty())
            RandomMachines->setObjectName(QStringLiteral("RandomMachines"));
        RandomMachines->resize(800, 600);
        centralwidget = new QWidget(RandomMachines);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 56, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 56, 17));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(150, 30, 46, 26));
        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(150, 80, 46, 26));
        RandomMachines->setCentralWidget(centralwidget);

        retranslateUi(RandomMachines);

        QMetaObject::connectSlotsByName(RandomMachines);
    } // setupUi

    void retranslateUi(QMainWindow *RandomMachines)
    {
        RandomMachines->setWindowTitle(QApplication::translate("RandomMachines", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("RandomMachines", "States", Q_NULLPTR));
        label_2->setText(QApplication::translate("RandomMachines", "Symbols", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RandomMachines: public Ui_RandomMachines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMMACHINES_H
