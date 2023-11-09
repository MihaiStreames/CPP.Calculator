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
    QString qDisplay;
    bool expectingNewOperand;

private slots:
    void digit_clicked();
    void operation_clicked();
    void clear_clicked();
    void equal_clicked();
    void plus_minus_clicked();
    void dot_clicked();

};
#endif // MAINWINDOW_H