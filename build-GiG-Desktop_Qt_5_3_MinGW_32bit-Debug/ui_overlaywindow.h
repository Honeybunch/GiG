/********************************************************************************
** Form generated from reading UI file 'overlaywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERLAYWINDOW_H
#define UI_OVERLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OverlayWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWebView *webView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OverlayWindow)
    {
        if (OverlayWindow->objectName().isEmpty())
            OverlayWindow->setObjectName(QStringLiteral("OverlayWindow"));
        OverlayWindow->setWindowModality(Qt::ApplicationModal);
        OverlayWindow->resize(400, 300);
        OverlayWindow->setDocumentMode(false);
        centralWidget = new QWidget(OverlayWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        webView = new QWebView(centralWidget);
        webView->setObjectName(QStringLiteral("webView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy);
        webView->setMinimumSize(QSize(320, 240));
        webView->setAutoFillBackground(true);
        webView->setStyleSheet(QStringLiteral(""));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout->addWidget(webView, 0, 0, 1, 1);

        OverlayWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OverlayWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OverlayWindow->setStatusBar(statusBar);

        retranslateUi(OverlayWindow);

        QMetaObject::connectSlotsByName(OverlayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OverlayWindow)
    {
        OverlayWindow->setWindowTitle(QApplication::translate("OverlayWindow", "OverlayWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class OverlayWindow: public Ui_OverlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERLAYWINDOW_H
