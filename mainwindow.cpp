#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // calculate 1
{
    int it=0;
    int st=0;
    stringstream stream;
    string x0,x1,x2;

    int n = ui->spinBox_n_1->value();
    int mit = ui->spinBox_m_1->value();

    long double *x = new long double[n];

    x[0] = static_cast <long double> (ui->doubleSpinBox_x0_1->value());
    x[1] = static_cast <long double> (ui->doubleSpinBox_x1_1->value());
    x[2] = static_cast <long double> (ui->doubleSpinBox_x2_1->value());
    long double omega = static_cast <long double> (ui->doubleSpinBox_omega_1->value());
    long double eps = static_cast <long double> (ui->doubleSpinBox_eps_1->value());

    Newtonsimple(n,x,omega,eps,mit,it,st);

    stream << fixed << setprecision( 15 ) << x[0];
    x0 = stream.str();  stream.str( string() );  stream.clear();
    stream << fixed << setprecision( 15 ) << x[1];
    x1 = stream.str();  stream.str( string() );  stream.clear();
    stream << fixed << setprecision( 80 ) << x[2];
    x2 = stream.str();  stream.str( string() );  stream.clear();

    ui->lineEdit_x0_1->setText(QString::fromStdString(x0));
    ui->lineEdit_x1_1->setText(QString::fromStdString(x1));
    ui->lineEdit_x2_1->setText(QString::fromStdString(x2));
    ui->lineEdit_it_1->setText(QString::fromStdString(to_string(it)));
    ui->lineEdit_st_1->setText(QString::fromStdString(to_string(st)));


    delete []x;
}

void MainWindow::on_pushButton_2_clicked() // reset 1
{
    ui->lineEdit_x0_1->setText(QString(""));
    ui->lineEdit_x1_1->setText(QString(""));
    ui->lineEdit_x2_1->setText(QString(""));
    ui->lineEdit_it_1->setText(QString(""));
    ui->lineEdit_st_1->setText(QString(""));
}

void MainWindow::on_pushButton_3_clicked()
{
    int n, it, st, mit;

    stringstream stream;
    string x0L,x0R,x1L,x1R,x2L,x2R;

    n = ui->spinBox_n_2->value();
    mit = ui->spinBox_m_2->value();

    intervalarth::interval *x = new intervalarth::interval[n];
    intervalarth::interval omega, eps;

    x[0].a = static_cast <long double> (ui->doubleSpinBox_x0_2L->value());
    x[0].b = static_cast <long double> (ui->doubleSpinBox_x0_2R->value());
    x[1].a = static_cast <long double> (ui->doubleSpinBox_x1_2L->value());
    x[1].b = static_cast <long double> (ui->doubleSpinBox_x1_2R->value());
    x[2].a = static_cast <long double> (ui->doubleSpinBox_x2_2L->value());
    x[2].b = static_cast <long double> (ui->doubleSpinBox_x2_2R->value());

    omega.a = static_cast <long double> (ui->doubleSpinBox_omega_2L->value());
    omega.b = static_cast <long double> (ui->doubleSpinBox_omega_2R->value());

    eps.a = static_cast <long double> (ui->doubleSpinBox_eps_2L->value());
    eps.b = static_cast <long double> (ui->doubleSpinBox_eps_2R->value());

    Newtonsimple_interval(n,x,omega,eps,mit,it,st);

    stream << fixed << setprecision( 16 ) << x[0].a;
    x0L = stream.str();  stream.str( string() );  stream.clear();
    stream << fixed << setprecision( 16 ) << x[0].b;
    x0R = stream.str();  stream.str( string() );  stream.clear();
    stream << fixed << setprecision( 16 ) << x[1].a;
    x1L = stream.str();  stream.str( string() );  stream.clear();
    stream << fixed << setprecision( 16 ) << x[1].b;
    x1R = stream.str();  stream.str( string() );  stream.clear();
    stream << fixed << setprecision( 16 ) << x[2].a;
    x2L = stream.str();  stream.str( string() );  stream.clear();
    stream << fixed << setprecision( 16 ) << x[2].b;
    x2R = stream.str();  stream.str( string() );  stream.clear();

    ui->lineEdit_x0_2L->setText(QString::fromStdString(x0L));
    ui->lineEdit_x0_2R->setText(QString::fromStdString(x0R));
    ui->lineEdit_x1_2L->setText(QString::fromStdString(x1L));
    ui->lineEdit_x1_2R->setText(QString::fromStdString(x1R));
    ui->lineEdit_x2_2L->setText(QString::fromStdString(x2L));
    ui->lineEdit_x2_2R->setText(QString::fromStdString(x2R));
    ui->lineEdit_it_2->setText(QString::fromStdString(to_string(it)));
    ui->lineEdit_st_2->setText(QString::fromStdString(to_string(st)));

    delete []x;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit_x0_2L->setText(QString(""));
    ui->lineEdit_x0_2R->setText(QString(""));
    ui->lineEdit_x1_2L->setText(QString(""));
    ui->lineEdit_x1_2R->setText(QString(""));
    ui->lineEdit_x2_2L->setText(QString(""));
    ui->lineEdit_x2_2R->setText(QString(""));
    ui->lineEdit_it_2->setText(QString(""));
    ui->lineEdit_st_2->setText(QString(""));
}