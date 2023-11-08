#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
    , expectingNewOperand(false)
{
    ui->setupUi(this);
    currentDisplay = "";
    ui->number->display("0");

    // Digit Buttons
    connect(ui->zeroButton, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->oneButton, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->twoButton, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->threeButton, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->fourButton, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->fiveButton, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->sixButton, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->sevenButton, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->eightButton, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->nineButton, SIGNAL(clicked()), this, SLOT(digitClicked()));

    // Operation Buttons
    connect(ui->plusButton, SIGNAL(clicked()), this, SLOT(operationClicked()));
    connect(ui->minusButton, SIGNAL(clicked()), this, SLOT(operationClicked()));
    connect(ui->multiplicationButton, SIGNAL(clicked()), this, SLOT(operationClicked()));
    connect(ui->divisionButton, SIGNAL(clicked()), this, SLOT(operationClicked()));
    connect(ui->percentageButton, SIGNAL(clicked()), this, SLOT(operationClicked()));

    // Other Buttons
    connect(ui->cButton, SIGNAL(clicked()), this, SLOT(clearClicked()));
    connect(ui->equalButton, SIGNAL(clicked()), this, SLOT(equalClicked()));
    connect(ui->plusMinusButton, SIGNAL(clicked()), this, SLOT(plusMinusClicked()));
    connect(ui->dotButton, SIGNAL(clicked()), this, SLOT(dotClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        if (expectingNewOperand) {
            currentDisplay = "";
            expectingNewOperand = false;
        }

        if (currentDisplay == "0" && button->text() == "0") {
            return;
        } else if (currentDisplay == "0") {
            currentDisplay = button->text();
        } else {
            currentDisplay += button->text();
        }

        MainCalculator.UpdateNumber(currentDisplay.toDouble());
        ui->number->display(currentDisplay);
    }
}

void MainWindow::operationClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString operation = button->text();
        MainCalculator.Operation(operation.toStdString());

        expectingNewOperand = true;
        ui->number->display(MainCalculator.getNumber());
    }
}

void MainWindow::equalClicked() {
    MainCalculator.Operation("=");

    if (MainCalculator.isError()) {
        ui->number->display("Error");
    } else {
        double result = MainCalculator.getNumber();
        ui->number->display(result);
    }

    expectingNewOperand = true;
}

void MainWindow::plusMinusClicked() {
    MainCalculator.PlusMinus();
    ui->number->display(MainCalculator.getNumber());
}

void MainWindow::clearClicked() {
    MainCalculator.Clear();
    currentDisplay = "";
    ui->number->display("0");
    expectingNewOperand = true;
}

void MainWindow::dotClicked() {
    if (expectingNewOperand) {
        currentDisplay = "0";
        expectingNewOperand = false;
    }

    if (!currentDisplay.contains('.')) {
        currentDisplay += ".";
    }

    ui->number->display(currentDisplay);
}