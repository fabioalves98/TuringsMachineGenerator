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
    QWidget *zCentralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *zTitleLayout;
    QSpacerItem *zSpacer_2;
    QLabel *zLabel;
    QSpacerItem *zSpacer_3;
    QHBoxLayout *zTapeLayout;
    QPushButton *plusLeftBt;
    QPushButton *minusLeftBt;
    QListWidget *tapeList;
    QPushButton *minusRightBt;
    QPushButton *plusRightBt;
    QHBoxLayout *zBSymLayout;
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
        zCentralwidget = new QWidget(EditTapes);
        zCentralwidget->setObjectName(QStringLiteral("zCentralwidget"));
        verticalLayout = new QVBoxLayout(zCentralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        zTitleLayout = new QHBoxLayout();
        zTitleLayout->setObjectName(QStringLiteral("zTitleLayout"));
        zSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zTitleLayout->addItem(zSpacer_2);

        zLabel = new QLabel(zCentralwidget);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        QFont font;
        font.setPointSize(16);
        zLabel->setFont(font);
        zLabel->setFrameShape(QFrame::Panel);
        zLabel->setFrameShadow(QFrame::Raised);
        zLabel->setLineWidth(1);
        zLabel->setMidLineWidth(0);
        zLabel->setAlignment(Qt::AlignCenter);
        zLabel->setWordWrap(false);
        zLabel->setMargin(0);

        zTitleLayout->addWidget(zLabel);

        zSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zTitleLayout->addItem(zSpacer_3);


        verticalLayout->addLayout(zTitleLayout);

        zTapeLayout = new QHBoxLayout();
        zTapeLayout->setObjectName(QStringLiteral("zTapeLayout"));
        plusLeftBt = new QPushButton(zCentralwidget);
        plusLeftBt->setObjectName(QStringLiteral("plusLeftBt"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plusLeftBt->sizePolicy().hasHeightForWidth());
        plusLeftBt->setSizePolicy(sizePolicy);

        zTapeLayout->addWidget(plusLeftBt);

        minusLeftBt = new QPushButton(zCentralwidget);
        minusLeftBt->setObjectName(QStringLiteral("minusLeftBt"));
        sizePolicy.setHeightForWidth(minusLeftBt->sizePolicy().hasHeightForWidth());
        minusLeftBt->setSizePolicy(sizePolicy);

        zTapeLayout->addWidget(minusLeftBt);

        tapeList = new QListWidget(zCentralwidget);
        tapeList->setObjectName(QStringLiteral("tapeList"));
        tapeList->setMaximumSize(QSize(16777215, 48));

        zTapeLayout->addWidget(tapeList);

        minusRightBt = new QPushButton(zCentralwidget);
        minusRightBt->setObjectName(QStringLiteral("minusRightBt"));
        sizePolicy.setHeightForWidth(minusRightBt->sizePolicy().hasHeightForWidth());
        minusRightBt->setSizePolicy(sizePolicy);

        zTapeLayout->addWidget(minusRightBt);

        plusRightBt = new QPushButton(zCentralwidget);
        plusRightBt->setObjectName(QStringLiteral("plusRightBt"));
        sizePolicy.setHeightForWidth(plusRightBt->sizePolicy().hasHeightForWidth());
        plusRightBt->setSizePolicy(sizePolicy);

        zTapeLayout->addWidget(plusRightBt);


        verticalLayout->addLayout(zTapeLayout);

        zBSymLayout = new QHBoxLayout();
        zBSymLayout->setObjectName(QStringLiteral("zBSymLayout"));
        zBlanckSymLabel = new QLabel(zCentralwidget);
        zBlanckSymLabel->setObjectName(QStringLiteral("zBlanckSymLabel"));
        zBlanckSymLabel->setFont(font);
        zBlanckSymLabel->setFrameShape(QFrame::Panel);
        zBlanckSymLabel->setFrameShadow(QFrame::Raised);
        zBlanckSymLabel->setMargin(1);

        zBSymLayout->addWidget(zBlanckSymLabel);

        blanckSymLEdit = new QLineEdit(zCentralwidget);
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

        zBSymLayout->addWidget(blanckSymLEdit);

        zSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zBSymLayout->addItem(zSpacer);

        restoreBt = new QPushButton(zCentralwidget);
        restoreBt->setObjectName(QStringLiteral("restoreBt"));
        restoreBt->setFont(font1);

        zBSymLayout->addWidget(restoreBt);

        saveBt = new QPushButton(zCentralwidget);
        saveBt->setObjectName(QStringLiteral("saveBt"));
        saveBt->setFont(font1);

        zBSymLayout->addWidget(saveBt);


        verticalLayout->addLayout(zBSymLayout);

        EditTapes->setCentralWidget(zCentralwidget);

        retranslateUi(EditTapes);

        QMetaObject::connectSlotsByName(EditTapes);
    } // setupUi

    void retranslateUi(QMainWindow *EditTapes)
    {
        EditTapes->setWindowTitle(QApplication::translate("EditTapes", "MainWindow", nullptr));
        zLabel->setText(QApplication::translate("EditTapes", " Edit the symbols of the Tape ", nullptr));
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
