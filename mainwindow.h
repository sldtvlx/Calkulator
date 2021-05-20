#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_C_clicked();

    void on_pushButton_trig_clicked();

    void on_pushButton_exp_clicked();

    void on_pushButton_an_clicked();

    void on_pushButton_pl_clicked();

    void on_pushButton_mi_clicked();

    void on_pushButton_um_clicked();

    void on_pushButton_de_clicked();

    void on_pushButton_sq_clicked();

    void on_pushButton_st_clicked();

    void on_spinBox_1_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
