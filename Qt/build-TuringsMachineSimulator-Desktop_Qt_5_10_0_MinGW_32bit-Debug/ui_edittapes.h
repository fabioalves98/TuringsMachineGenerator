/********************************************************************************
** Form generated from reading UI file 'edittapes.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTAPES_H
#define UI_EDITTAPES_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditTapes
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *Title;
    QSpacerItem *zSpacerL;
    QLabel *zTitleLabel;
    QSpacerItem *zSpacerR;
    QHBoxLayout *Tape;
    QPushButton *plusLeftBt;
    QPushButton *minusLeftBt;
    QListWidget *tapeList;
    QPushButton *minusRightBt;
    QPushButton *plusRightBt;
    QHBoxLayout *BlackSymbol;
    QLabel *zBlanckSymLabel;
    QLineEdit *blanckSymLEdit;
    QSpacerItem *zSpacer;
    QPushButton *restoreBt;
    QPushButton *saveBt;

    void setupUi(QMainWindow *EditTapes)
    {
        if (EditTapes->objectName().isEmpty())
            EditTapes->setObjectName(QStringLiteral("EditTapes"));
        EditTapes->resize(800, 146);
        centralwidget = new QWidget(EditTapes);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Title = new QHBoxLayout();
        Title->setObjectName(QStringLiteral("Title"));
        zSpacerL = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Title->addItem(zSpacerL);

        zTitleLabel = new QLabel(centralwidget);
        zTitleLabel->setObjectName(QStringLiteral("zTitleLabel"));
        QFont font;
        font.setPointSize(16);
        zTitleLabel->setFont(font);
        zTitleLabel->setFrameShape(QFrame::Panel);
        zTitleLabel->setFrameShadow(QFrame::Raised);
        zTitleLabel->setLineWidth(1);
        zTitleLabel->setMidLineWidth(0);
        zTitleLabel->setAlignment(Qt::AlignCenter);
        zTitleLabel->setWordWrap(false);
        zTitleLabel->setMargin(3);

        Title->addWidget(zTitleLabel);

        zSpacerR = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Title->addItem(zSpacerR);


        verticalLayout->addLayout(Title);

        Tape = new QHBoxLayout();
        Tape->setObjectName(QStringLiteral("Tape"));
        plusLeftBt = new QPushButton(centralwidget);
        plusLeftBt->setObjectName(QStringLiteral("plusLeftBt"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plusLeftBt->sizePolicy().hasHeightForWidth());
        plusLeftBt->setSizePolicy(sizePolicy);

        Tape->addWidget(plusLeftBt);

        minusLeftBt = new QPushButton(centralwidget);
        minusLeftBt->setObjectName(QStringLiteral("minusLeftBt"));
        sizePolicy.setHeightForWidth(minusLeftBt->sizePolicy().hasHeightForWidth());
        minusLeftBt->setSizePolicy(sizePolicy);

        Tape->addWidget(minusLeftBt);

        tapeList = new QListWidget(centralwidget);
        tapeList->setObjectName(QStringLiteral("tapeList"));
        tapeList->setMaximumSize(QSize(16777215, 48));

        Tape->addWidget(tapeList);

        minusRightBt = new QPushButton(centralwidget);
        minusRightBt->setObjectName(QStringLiteral("minusRightBt"));
        sizePolicy.setHeightForWidth(minusRightBt->sizePolicy().hasHeightForWidth());
        minusRightBt->setSizePolicy(sizePolicy);

        Tape->addWidget(minusRightBt);

        plusRightBt = new QPushButton(centralwidget);
        plusRightBt->setObjectName(QStringLiteral("plusRightBt"));
        sizePolicy.setHeightForWidth(plusRightBt->sizePolicy().hasHeightForWidth());
        plusRightBt->setSizePolicy(sizePolicy);

        Tape->addWidget(plusRightBt);


        verticalLayout->addLayout(Tape);

        BlackSymbol = new QHBoxLayout();
        BlackSymbol->setObjectName(QStringLiteral("BlackSymbol"));
        zBlanckSymLabel = new QLabel(centralwidget);
        zBlanckSymLabel->setObjectName(QStringLiteral("zBlanckSymLabel"));
        zBlanckSymLabel->setFont(font);
        zBlanckSymLabel->setFrameShape(QFrame::Panel);
        zBlanckSymLabel->setFrameShadow(QFrame::Raised);
        zBlanckSymLabel->setMargin(1);

        BlackSymbol->addWidget(zBlanckSymLabel);

        blanckSymLEdit = new QLineEdit(centralwidget);
        blanckSymLEdit->setObjectName(QStringLiteral("blanckSymLEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(blanckSymLEdit->sizePolicy().hasHeightForWidth());
        blanckSymLEdit->setSizePolicy(sizePolicy1);
        blanckSymLEdit->setMaximumSize(QSize(40, 16777215));
        QFont font1;
        font1.setPointSize(12);
        blanckSymLEdit->setFont(font1);
        blanckSymLEdit->setMaxLength(1);
        blanckSymLEdit->setAlignment(Qt::AlignCenter);

        BlackSymbol->addWidget(blanckSymLEdit);

        zSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        BlackSymbol->addItem(zSpacer);

        restoreBt = new QPushButton(centralwidget);
        restoreBt->setObjectName(QStringLiteral("restoreBt"));
        restoreBt->setFont(font1);

        BlackSymbol->addWidget(restoreBt);

        saveBt = new QPushButton(centralwidget);
        saveBt->setObjectName(QStringLiteral("saveBt"));
        saveBt->setFont(font1);

        BlackSymbol->addWidget(saveBt);


        verticalLayout->addLayout(BlackSymbol);

        EditTapes->setCentralWidget(centralwidget);

        retranslateUi(EditTapes);

        QMetaObject::connectSlotsByName(EditTapes);
    } // setupUi

    void retranslateUi(QMainWindow *EditTapes)
    {
        EditTapes->setWindowTitle(QApplication::translate("EditTapes", "MainWindow", nullptr));
        zTitleLabel->setText(QApplication::translate("EditTapes", "Edit the symbols of the Tape", nullptr));
        plusLeftBt->setText(QString());
        minusLeftBt->setText(QString());
        minusRightBt->setText(QString());
        plusRightBt->setText(QString());
        zBlanckSymLabel->setText(QApplication::translate("EditTapes", "Blanck Symbol:", nullptr));
        restoreBt->setText(QApplication::translate("EditTapes", "Restore", nullptr));
        saveBt->setText(QApplication::translate("EditTapes", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditTapes: public Ui_EditTapes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTAPES_H
