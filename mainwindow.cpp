#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "methods.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <math.h>
#include <cmath>
#include <QString>

using namespace std;

short boot_menu;
float a, b, ai, bi;
string back;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> label_3 -> hide();
    ui -> label_4 -> hide();
    ui -> label_6 -> hide();
    ui -> label_7 -> hide();
    ui -> label_8 -> hide();
    ui -> spinBox_3 -> hide();
    ui -> spinBox_4 -> hide();

    ui -> spinBox_1 -> clear();
    ui -> spinBox_2 -> clear();
    ui -> spinBox_3 -> clear();
    ui -> spinBox_4 -> clear();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_back_clicked()
{
    string tmp = ui->label_7->text().toStdString();
    ui->label_7->setText(QString::fromStdString(back));
    back = tmp;
}

void MainWindow::on_pushButton_C_clicked()
{
        ui -> label_7 -> hide();
        ui -> label_8 -> hide();
        ui -> label_9 -> hide();
        ui -> label_6 -> hide();
        ui -> label_3 -> hide();
        ui -> label_4 -> hide();
        ui -> spinBox_3 -> hide();
        ui -> spinBox_4 -> hide();

}

void MainWindow::on_pushButton_trig_clicked()
{
    boot_menu = 4;
    ui -> label_9 -> setText("");
}

void MainWindow::on_pushButton_exp_clicked()
{
    boot_menu = 5;
    ui -> label_9 -> setText("");
}

void MainWindow::on_pushButton_pl_clicked()
{
    boot_menu = 6;
    ui -> label_9 -> setText("+");
}

void MainWindow::on_pushButton_mi_clicked()
{
    boot_menu = 7;
    ui -> label_9 -> setText("−");
}

void MainWindow::on_pushButton_um_clicked()
{
    boot_menu = 8;
    ui -> label_9 -> setText("×");
}

void MainWindow::on_pushButton_de_clicked()
{
    boot_menu = 9;
    ui -> label_9 -> setText("÷");
}

void MainWindow::on_pushButton_sq_clicked()
{
    boot_menu = 10;
    ui -> label_9 -> setText("");

}

void MainWindow::on_pushButton_st_clicked()
{
    boot_menu = 11;
    ui -> label_9 -> setText("");
}

void MainWindow::on_pushButton_an_clicked()
{
    back = ui->label_7->text().toStdString();
    //сложение
    if (boot_menu == 6)
    {
        int ne_ishka = a + b;
        int ishka = ai + bi;
        ui -> label_7 -> setText(QString::number(round(ne_ishka*100)/100) + " + i × " + QString::number(round(ishka*100)/100));
    }
    //вычитание
    if (boot_menu == 7)
    {
        int ne_ishka = a - b;
        int ishka = ai - bi;
        ui -> label_7 -> setText(QString::number(round(ne_ishka*100)/100) + " + i × " + QString::number(round(ishka*100)/100));
    }
    //умножение
    if (boot_menu == 8)
    {
        int ishka = a * bi + b * ai;
        int ne_ishka = a * b - ai * bi;
        ui -> label_7 -> setText(QString::number(round(ne_ishka * 1000) / 1000) + " + i × " + QString::number(round(ishka*100)/100));
    }
    //деление
    if (boot_menu == 9)
    {
        float ne_ishka = (a * b + ai * bi)/(pow(b,2) + pow(bi,2));
        float ishka = (b * ai - a * bi)/(pow(b,2) + pow(bi,2));
        ui -> label_7 -> setText(QString::number(round(ne_ishka*100)/100) + " + i × " + QString::number(round(ishka*100)/100));

    }
    //возведение в степень
    if (boot_menu == 11)
    {
        int ne_ishka = pow(a,2);
        int ishka = pow(ai,2);
        ui -> label_7 -> setText(QString::number(round(ne_ishka*100)/100) + " + i × " + QString::number(round(ishka*100)/100));
    }
    //перевод в тригонометрическую форму
    if (boot_menu == 4)
    {
        double abs = sqrt(pow(a,2) + pow(ai,2));
        ui -> label_7 -> setText(QString::number(round(abs * 1000) / 1000) + " × cos(arctg(" + QString::number(round(ai * 1000) / 1000) + "/" + QString::number(round(a * 1000) / 1000) + ") + i × (arctg(" + QString::number(round(ai * 1000) / 1000) + "/" + QString::number(round(a * 1000) / 1000) + ")))");
    }
    //перевод в экспоненциальную форму
    if (boot_menu == 5)
    {
        double abs = sqrt(pow(a,2) + pow(ai,2));
        double arg = (atan(ai/a) * 180)/acos(-1);
        ui -> label_7 -> setText(QString::number(round(abs * 1000) / 1000) + " + e^(i × " + QString::number(round(arg * 1000) / 1000) + ")");
    }
    //вычисление корня
    if(boot_menu == 10)
    {
        double abs = sqrt(sqrt(pow(a,2) + pow(ai,2))); //модуль
        double z1_cos = cos(((atan(ai/a) * 180)/acos(-1)) / 2);
        double z1_sin = sin(((atan(ai/a) * 180)/acos(-1)) / 2);
        double ishka = abs * z1_sin;
        double ne_ishka = abs*z1_cos;
        ui -> label_7 ->setText("z(1,2) = ±(" + QString::number(round(ne_ishka*100)/100) + " + i × " + QString::number(round(ishka * 1000) / 1000) + ")");
    }
}

void MainWindow::on_spinBox_1_valueChanged(int arg1)
{
    a = arg1;

}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    ai = arg1;
}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    b = arg1;
}

void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
    bi = arg1;
}
