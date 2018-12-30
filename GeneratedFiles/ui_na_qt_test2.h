/********************************************************************************
** Form generated from reading UI file 'na_qt_test2.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NA_QT_TEST2_H
#define UI_NA_QT_TEST2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NA_Qt_test2Class
{
public:
    QWidget *centralWidget;
    QTextBrowser *deviceInfo;
    QTextBrowser *contentBrowser;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NA_Qt_test2Class)
    {
        if (NA_Qt_test2Class->objectName().isEmpty())
            NA_Qt_test2Class->setObjectName(QStringLiteral("NA_Qt_test2Class"));
        NA_Qt_test2Class->resize(821, 605);
        centralWidget = new QWidget(NA_Qt_test2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        deviceInfo = new QTextBrowser(centralWidget);
        deviceInfo->setObjectName(QStringLiteral("deviceInfo"));
        deviceInfo->setGeometry(QRect(70, 10, 651, 141));
        contentBrowser = new QTextBrowser(centralWidget);
        contentBrowser->setObjectName(QStringLiteral("contentBrowser"));
        contentBrowser->setGeometry(QRect(40, 180, 711, 261));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 490, 351, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 490, 93, 28));
        NA_Qt_test2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NA_Qt_test2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 821, 26));
        NA_Qt_test2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NA_Qt_test2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NA_Qt_test2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NA_Qt_test2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NA_Qt_test2Class->setStatusBar(statusBar);

        retranslateUi(NA_Qt_test2Class);

        QMetaObject::connectSlotsByName(NA_Qt_test2Class);
    } // setupUi

    void retranslateUi(QMainWindow *NA_Qt_test2Class)
    {
        NA_Qt_test2Class->setWindowTitle(QApplication::translate("NA_Qt_test2Class", "NA_Qt_test2", 0));
        pushButton->setText(QApplication::translate("NA_Qt_test2Class", "send", 0));
    } // retranslateUi

};

namespace Ui {
    class NA_Qt_test2Class: public Ui_NA_Qt_test2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NA_QT_TEST2_H
