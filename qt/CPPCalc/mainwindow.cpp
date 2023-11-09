#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
    , expectingNewOperand(false)
{
    ui->setupUi(this);
    qDisplay = "";
    ui->number->display("0");

    // Digit Buttons
    connect(ui->zeroButton, SIGNAL(clicked()), this, SLOT(digit_clicked()));
    connect(ui->oneButton, SIGNAL(clicked()), this, SLOT(digit_clicked()));
    connect(ui->twoButton, SIGNAL(clicked()), this, SLOT(digit_clicked()));
    connect(ui->threeButton, SIGNAL(clicked()), this, SLOT(digit_clicked()));
    connect(ui->fourButton, SIGNAL(clicked()), this, SLOT(digit_clicked()));
    connect(ui->fiveButton, SIGNAL(clicked()), this, SLOT(digit_clicked()));
    connect(ui->sixButton, SIGNAL(clicked()), this, SLOT(digit_clicked()));
    connect(ui->sevenButton, SIGNAL(clicked()), this, SLOT(digit_clicked()));
    connect(ui->eightButton, SIGNAL(clicked()), this, SLOT(digit_clicked()));
    connect(ui->nineButton, SIGNAL(clicked()), this, SLOT(digit_clicked()));

    // operation Buttons
    connect(ui->plusButton, SIGNAL(clicked()), this, SLOT(operation_clicked()));
    connect(ui->minusButton, SIGNAL(clicked()), this, SLOT(operation_clicked()));
    connect(ui->multiplicationButton, SIGNAL(clicked()), this, SLOT(operation_clicked()));
    connect(ui->divisionButton, SIGNAL(clicked()), this, SLOT(operation_clicked()));
    connect(ui->percentageButton, SIGNAL(clicked()), this, SLOT(operation_clicked()));

    // Other Buttons
    connect(ui->cButton, SIGNAL(clicked()), this, SLOT(clear_clicked()));
    connect(ui->equalButton, SIGNAL(clicked()), this, SLOT(equal_clicked()));
    connect(ui->plusMinusButton, SIGNAL(clicked()), this, SLOT(plus_minus_clicked()));
    connect(ui->dotButton, SIGNAL(clicked()), this, SLOT(dot_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_clicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (button) {
        QString digitValue = button->text();
        qDisplay += digitValue;
        ui->number->display(qDisplay);
    }
}

void MainWindow::operation_clicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString operation;

        if (button->text() == "×") {
            operation = "*";
        } else if (button->text() == "÷") {
            operation = "/";
        } else {
            operation = button->text();
        }
        qDisplay += operation;
        ui->number->display(qDisplay);
    }
}


void MainWindow::equal_clicked() {
    MainCalculator.input(qDisplay.toStdString());
    MainCalculator.input("=");

    if (MainCalculator.has_error()) {
        ui->number->display("Error");
        MainCalculator.clear_error();
    } else {
        double result = MainCalculator.get_number();
        ui->number->display(QString::number(result));
    }
    qDisplay = "";
}

void MainWindow::plus_minus_clicked() {
    if (qDisplay.startsWith("-")) {
        qDisplay.remove(0, 1);
    } else {
        qDisplay.prepend("-");
    }
    ui->number->display(qDisplay);
}

void MainWindow::clear_clicked() {
    MainCalculator.clear();
    qDisplay = "";
    ui->number->display("0");
}

void MainWindow::dot_clicked() {
    if (!qDisplay.contains('.')) {
        qDisplay += ".";
    }
    ui->number->display(qDisplay);
}