#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
        QString digitValue = button->text();
        MainCalculator.Operation(digitValue.toStdString());
        ui->number->display(MainCalculator.Number);
    }
}

void MainWindow::operationClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString operation = button->text();
        if (operation == "+") {
            MainCalculator.Operation("1");
        } else if (operation == "-") {
            MainCalculator.Operation("2");
        } else if (operation == "*") {
            MainCalculator.Operation("3");
        } else if (operation == "/") {
            MainCalculator.Operation("4");
        } else if (operation == "%") {
            MainCalculator.Operation("5");
        }
        ui->number->display(MainCalculator.Number);
    }
}

void MainWindow::equalClicked() {
    MainCalculator.Operation("=");
    if (MainCalculator.isError()) {
        ui->number->display("Error"); // Show an error message
    } else {
        ui->number->display(MainCalculator.Number);
    }
}

void MainWindow::plusMinusClicked() {
    MainCalculator.PlusMinus();
    ui->number->display(MainCalculator.Number);
}

void MainWindow::clearClicked() {
    MainCalculator.Clear();
    ui->number->display(MainCalculator.Number);
}

void MainWindow::dotClicked() {
    // TODO: Add a dot to the current value
}