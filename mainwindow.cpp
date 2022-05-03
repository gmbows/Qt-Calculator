#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //this->findChild<QLCDNumber*>("nDisplay")->display(1);
    this->calculator.add_digit(1);
}


void MainWindow::on_pushButton_2_clicked()
{
    this->calculator.add_digit(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    this->calculator.add_digit(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    this->calculator.add_digit(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    this->calculator.add_digit(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    this->calculator.add_digit(6);
}

void MainWindow::on_pushButton_7_clicked()
{
    this->calculator.add_digit(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    this->calculator.add_digit(8);
}

void MainWindow::on_pushButton_9_clicked()
{
    this->calculator.add_digit(9);
}

void MainWindow::on_pushButton_0_clicked()
{
    this->calculator.add_digit(0);
}

void MainWindow::on_pushButton_eq_clicked()
{
    this->calculator.equals();
}

void MainWindow::on_pushButton_plus_clicked()
{
    this->calculator.set_op(OP_ADD);
}

void MainWindow::on_pushButton_minus_clicked()
{
    this->calculator.set_op(OP_SUB);
}

void MainWindow::on_pushButton_mult_clicked()
{
    this->calculator.set_op(OP_MULT);
}

void MainWindow::on_pushButton_div_clicked()
{
    this->calculator.set_op(OP_DIV);
}

void MainWindow::on_nDisplay_overflow()
{
    this->calculator.displayValue = 0;
    this->calculator.lastValue = 0;
    this->calculator.update_display();
}


void MainWindow::on_pushButton_clr_clicked()
{
    this->calculator.clear();
}


void MainWindow::on_pushButton_del_clicked()
{
    this->calculator.del();
}

