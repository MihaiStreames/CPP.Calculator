#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::Calculator *ui;
    Calc MainCalculator;
    QString currentDisplay;
    bool expectingNewOperand;

private slots:
    void digitClicked();
    void operationClicked();
    void clearClicked();
    void equalClicked();
    void plusMinusClicked();
    void dotClicked();

};
#endif // MAINWINDOW_H