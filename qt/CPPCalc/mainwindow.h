#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Calc MainCalculator;

private slots:
    void digitClicked();
    void operationClicked();
    void clearClicked();
    void equalClicked();
    void plusMinusClicked();
    void dotClicked();

};
#endif // MAINWINDOW_H