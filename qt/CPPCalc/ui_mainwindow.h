/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QLCDNumber *number;
    QPushButton *cButton;
    QPushButton *plusMinusButton;
    QPushButton *percentageButton;
    QPushButton *divisionButton;
    QPushButton *multiplicationButton;
    QPushButton *minusButton;
    QPushButton *plusButton;
    QPushButton *equalButton;
    QPushButton *dotButton;
    QPushButton *zeroButton;
    QPushButton *sevenButton;
    QPushButton *eightButton;
    QPushButton *nineButton;
    QPushButton *sixButton;
    QPushButton *threeButton;
    QPushButton *twoButton;
    QPushButton *oneButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(283, 548);
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        number = new QLCDNumber(centralwidget);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(20, 30, 231, 141));
        cButton = new QPushButton(centralwidget);
        cButton->setObjectName(QString::fromUtf8("cButton"));
        cButton->setGeometry(QRect(20, 180, 51, 51));
        plusMinusButton = new QPushButton(centralwidget);
        plusMinusButton->setObjectName(QString::fromUtf8("plusMinusButton"));
        plusMinusButton->setGeometry(QRect(80, 180, 51, 51));
        percentageButton = new QPushButton(centralwidget);
        percentageButton->setObjectName(QString::fromUtf8("percentageButton"));
        percentageButton->setGeometry(QRect(140, 180, 51, 51));
        divisionButton = new QPushButton(centralwidget);
        divisionButton->setObjectName(QString::fromUtf8("divisionButton"));
        divisionButton->setGeometry(QRect(200, 180, 51, 51));
        multiplicationButton = new QPushButton(centralwidget);
        multiplicationButton->setObjectName(QString::fromUtf8("multiplicationButton"));
        multiplicationButton->setGeometry(QRect(200, 240, 51, 51));
        minusButton = new QPushButton(centralwidget);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));
        minusButton->setGeometry(QRect(200, 300, 51, 51));
        plusButton = new QPushButton(centralwidget);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setGeometry(QRect(200, 360, 51, 51));
        equalButton = new QPushButton(centralwidget);
        equalButton->setObjectName(QString::fromUtf8("equalButton"));
        equalButton->setGeometry(QRect(200, 420, 51, 51));
        dotButton = new QPushButton(centralwidget);
        dotButton->setObjectName(QString::fromUtf8("dotButton"));
        dotButton->setGeometry(QRect(140, 420, 51, 51));
        zeroButton = new QPushButton(centralwidget);
        zeroButton->setObjectName(QString::fromUtf8("zeroButton"));
        zeroButton->setGeometry(QRect(20, 420, 111, 51));
        sevenButton = new QPushButton(centralwidget);
        sevenButton->setObjectName(QString::fromUtf8("sevenButton"));
        sevenButton->setGeometry(QRect(20, 240, 51, 51));
        eightButton = new QPushButton(centralwidget);
        eightButton->setObjectName(QString::fromUtf8("eightButton"));
        eightButton->setGeometry(QRect(80, 240, 51, 51));
        nineButton = new QPushButton(centralwidget);
        nineButton->setObjectName(QString::fromUtf8("nineButton"));
        nineButton->setGeometry(QRect(140, 240, 51, 51));
        sixButton = new QPushButton(centralwidget);
        sixButton->setObjectName(QString::fromUtf8("sixButton"));
        sixButton->setGeometry(QRect(140, 300, 51, 51));
        threeButton = new QPushButton(centralwidget);
        threeButton->setObjectName(QString::fromUtf8("threeButton"));
        threeButton->setGeometry(QRect(140, 360, 51, 51));
        twoButton = new QPushButton(centralwidget);
        twoButton->setObjectName(QString::fromUtf8("twoButton"));
        twoButton->setGeometry(QRect(80, 360, 51, 51));
        oneButton = new QPushButton(centralwidget);
        oneButton->setObjectName(QString::fromUtf8("oneButton"));
        oneButton->setGeometry(QRect(20, 360, 51, 51));
        fourButton = new QPushButton(centralwidget);
        fourButton->setObjectName(QString::fromUtf8("fourButton"));
        fourButton->setGeometry(QRect(20, 300, 51, 51));
        fiveButton = new QPushButton(centralwidget);
        fiveButton->setObjectName(QString::fromUtf8("fiveButton"));
        fiveButton->setGeometry(QRect(80, 300, 51, 51));
        Calculator->setCentralWidget(centralwidget);
        number->raise();
        plusMinusButton->raise();
        percentageButton->raise();
        divisionButton->raise();
        multiplicationButton->raise();
        minusButton->raise();
        plusButton->raise();
        equalButton->raise();
        dotButton->raise();
        zeroButton->raise();
        sevenButton->raise();
        eightButton->raise();
        nineButton->raise();
        sixButton->raise();
        threeButton->raise();
        twoButton->raise();
        oneButton->raise();
        fourButton->raise();
        fiveButton->raise();
        cButton->raise();
        menubar = new QMenuBar(Calculator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 283, 29));
        Calculator->setMenuBar(menubar);
        statusbar = new QStatusBar(Calculator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Calculator->setStatusBar(statusbar);

        retranslateUi(Calculator);
        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        cButton->setText(QCoreApplication::translate("Calculator", "C", nullptr));
        plusMinusButton->setText(QCoreApplication::translate("Calculator", "+/-", nullptr));
        percentageButton->setText(QCoreApplication::translate("Calculator", "%", nullptr));
        divisionButton->setText(QCoreApplication::translate("Calculator", "\303\267", nullptr));
        multiplicationButton->setText(QCoreApplication::translate("Calculator", "\303\227", nullptr));
        minusButton->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        plusButton->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        equalButton->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        dotButton->setText(QCoreApplication::translate("Calculator", ".", nullptr));
        zeroButton->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        sevenButton->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        eightButton->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        nineButton->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        sixButton->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        threeButton->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        twoButton->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        oneButton->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        fourButton->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        fiveButton->setText(QCoreApplication::translate("Calculator", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
