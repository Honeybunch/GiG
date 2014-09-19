/********************************************************************************
** Form generated from reading UI file 'choosewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEWINDOW_H
#define UI_CHOOSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *streamInputLabel;
    QLineEdit *streamInput;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *displayButton;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChooseWindow)
    {
        if (ChooseWindow->objectName().isEmpty())
            ChooseWindow->setObjectName(QStringLiteral("ChooseWindow"));
        ChooseWindow->resize(325, 233);
        centralwidget = new QWidget(ChooseWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        streamInputLabel = new QLabel(centralwidget);
        streamInputLabel->setObjectName(QStringLiteral("streamInputLabel"));

        horizontalLayout->addWidget(streamInputLabel);

        streamInput = new QLineEdit(centralwidget);
        streamInput->setObjectName(QStringLiteral("streamInput"));

        horizontalLayout->addWidget(streamInput);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        displayButton = new QPushButton(centralwidget);
        displayButton->setObjectName(QStringLiteral("displayButton"));

        horizontalLayout_2->addWidget(displayButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        ChooseWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ChooseWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ChooseWindow->setStatusBar(statusbar);

        retranslateUi(ChooseWindow);

        QMetaObject::connectSlotsByName(ChooseWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChooseWindow)
    {
        ChooseWindow->setWindowTitle(QApplication::translate("ChooseWindow", "MainWindow", 0));
        label->setText(QApplication::translate("ChooseWindow", "GiG Stream Loader", 0));
        streamInputLabel->setText(QApplication::translate("ChooseWindow", "Stream URL:", 0));
        displayButton->setText(QApplication::translate("ChooseWindow", "Display", 0));
    } // retranslateUi

};

namespace Ui {
    class ChooseWindow: public Ui_ChooseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEWINDOW_H
