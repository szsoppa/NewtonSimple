#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

int n,it,st,mit;

long double *v = NULL;
long double omega,eps;

intervalarth::interval *x_i = NULL;
intervalarth::interval omega_i, eps_i;

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
    string x0,x1,x2;
    stringstream stream;

    Newtonsimple(n,v,omega,eps,mit,it,st);

    stream << scientific << setprecision( 16 ) <<  v[0];
    x0 = stream.str();  stream.str( string() );  stream.clear();
    stream << scientific << setprecision( 16 ) <<  v[1];
    x1 = stream.str();  stream.str( string() );  stream.clear();
    stream << scientific << setprecision( 16 ) <<  v[2];
    x2 = stream.str();  stream.str( string() );  stream.clear();

    ui->lineEdit_x0_1->setText(QString::fromStdString(x0));
    ui->lineEdit_x1_1->setText(QString::fromStdString(x1));
    ui->lineEdit_x2_1->setText(QString::fromStdString(x2));
    ui->lineEdit_it_1->setText(QString::fromStdString(to_string(it)));
    ui->lineEdit_st_1->setText(QString::fromStdString(to_string(st)));


    delete []v;

    v=NULL;
    n=0;
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
    Newtonsimple_interval(n,x_i,omega_i,eps_i,mit,it,st);

    string x0L,x0R,x1L,x1R,x2L,x2R;

    intervalarth::IntervalArithmetic::IEndsToStrings(x_i[0],x0L,x0R);
    intervalarth::IntervalArithmetic::IEndsToStrings(x_i[1],x1L,x1R);
    intervalarth::IntervalArithmetic::IEndsToStrings(x_i[2],x2L,x2R);

    ui->lineEdit_x0_2L->setText(QString::fromStdString(x0L));
    ui->lineEdit_x0_2R->setText(QString::fromStdString(x0R));
    ui->lineEdit_x1_2L->setText(QString::fromStdString(x1L));
    ui->lineEdit_x1_2R->setText(QString::fromStdString(x1R));
    ui->lineEdit_x2_2L->setText(QString::fromStdString(x2L));
    ui->lineEdit_x2_2R->setText(QString::fromStdString(x2R));
    ui->lineEdit_it_2->setText(QString::fromStdString(to_string(it)));
    ui->lineEdit_st_2->setText(QString::fromStdString(to_string(st)));

    delete []x_i;

    n=0;
}

void MainWindow::on_pushButton_4_clicked() // Reset values Interval
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

void MainWindow::on_pushButton_5_clicked() // Read from File Extended
{
    stringstream stream;
    bool is_open;

    QString file_name = QFileDialog::getOpenFileName(this,tr("Open File"),QDir::homePath(),"Text File (*.txt)");

    QFile file(file_name);

    is_open = file.open(QIODevice::ReadOnly);

    if(is_open)
    {
        QTextStream in(&file);

        QString temp = in.readLine();
        n = stod(temp.toStdString());
        ui->spinBox_n_1->setValue(n);

        temp = in.readLine();
        mit = stod(temp.toStdString());
        ui->spinBox_m_1->setValue(mit);

        if(!v)
            delete []v;

        v = new long double[n];

        temp = in.readLine();
        v[0] = stod(temp.toStdString());
        ui->doubleSpinBox_x0_1->setValue(v[0]);

        temp = in.readLine();
        v[1] = stod(temp.toStdString());
        ui->doubleSpinBox_x1_1->setValue(v[1]);

        temp = in.readLine();
        v[2] = stod(temp.toStdString());
        ui->doubleSpinBox_x2_1->setValue(v[2]);

        temp = in.readLine();
        omega = stod(temp.toStdString());
        ui->doubleSpinBox_omega_1->setValue(omega);

        temp = in.readLine();
        eps = stod(temp.toStdString());
        ui->doubleSpinBox_eps_1->setValue(eps);

        file.close();
    }
}

void MainWindow::on_pushButton_6_clicked() // Read from Input Extended
{
    stringstream stream;
    string x0,x1,x2;

    n = ui->spinBox_n_1->value();
    mit = ui->spinBox_m_1->value();

    if(!v)
        delete []v;

    v = new long double[n];

    v[0] = static_cast <long double> (ui->doubleSpinBox_x0_1->value());
    v[1] = static_cast <long double> (ui->doubleSpinBox_x1_1->value());
    v[2] = static_cast <long double> (ui->doubleSpinBox_x2_1->value());
    omega = static_cast <long double> (ui->doubleSpinBox_omega_1->value());
    eps = static_cast <long double> (ui->doubleSpinBox_eps_1->value());
}

void MainWindow::on_pushButton_7_clicked() // Read from Input Interval
{
    QString qs;

    stringstream stream;
    string x0L,x0R,x1L,x1R,x2L,x2R;

    n = ui->spinBox_n_2->value();
    mit = ui->spinBox_m_2->value();

    if(!x_i)
        delete []x_i;

    x_i = new intervalarth::interval[n];

    qs = ui->plainTextEdit_x0_L->toPlainText();
    x_i[0].a = LeftRead( qs.toStdString() );
    qs = ui->plainTextEdit_x0_R->toPlainText();
    x_i[0].b = RightRead( qs.toStdString() );

    qs = ui->plainTextEdit_x1_L->toPlainText();
    x_i[1].a = LeftRead( qs.toStdString() );
    qs = ui->plainTextEdit_x1_R->toPlainText();
    x_i[1].b = RightRead( qs.toStdString() );

    qs = ui->plainTextEdit_x2_L->toPlainText();
    x_i[2].a = LeftRead( qs.toStdString() );
    qs = ui->plainTextEdit_x2_R->toPlainText();
    x_i[2].b = RightRead( qs.toStdString() );

    qs = ui->plainTextEdit_omega_L->toPlainText();
    omega_i.a = LeftRead( qs.toStdString() );
    qs = ui->plainTextEdit_omega_R->toPlainText();
    omega_i.b = RightRead( qs.toStdString() );

    qs = ui->plainTextEdit_eps_L->toPlainText();
    eps_i.a = LeftRead( qs.toStdString() );
    qs = ui->plainTextEdit_eps_R->toPlainText();
    eps_i.b = RightRead( qs.toStdString() );
}

void MainWindow::on_pushButton_8_clicked() // Read from File Interval
{
    stringstream stream;
    bool is_open;

    QString file_name = QFileDialog::getOpenFileName(this,tr("Open File"),QDir::homePath(),"Text File (*.txt)");

    QFile file(file_name);

    is_open = file.open(QIODevice::ReadOnly);

    if(is_open)
    {
        QTextStream in(&file);

        QString temp = in.readLine();
        n = stod(temp.toStdString());
        ui->spinBox_n_2->setValue(n);

        temp = in.readLine();
        mit = stod(temp.toStdString());
        ui->spinBox_m_2->setValue(mit);

        if(!x_i)
            delete []x_i;

        x_i = new intervalarth::interval[n];

        temp = in.readLine();
        x_i[0].a = LeftRead(temp.toStdString());
        ui->plainTextEdit_x0_L->setPlainText(temp);

        temp = in.readLine();
        x_i[0].b = RightRead((temp.toStdString()));
        ui->plainTextEdit_x0_R->setPlainText(temp);

        temp = in.readLine();
        x_i[1].a = LeftRead((temp.toStdString()));
        ui->plainTextEdit_x1_L->setPlainText(temp);

        temp = in.readLine();
        x_i[1].b = RightRead((temp.toStdString()));
        ui->plainTextEdit_x1_R->setPlainText(temp);

        temp = in.readLine();
        x_i[2].a = LeftRead((temp.toStdString()));
        ui->plainTextEdit_x2_L->setPlainText(temp);

        temp = in.readLine();
        x_i[2].b = RightRead((temp.toStdString()));
        ui->plainTextEdit_x2_R->setPlainText(temp);

        temp = in.readLine();
        omega_i.a = LeftRead((temp.toStdString()));
        ui->plainTextEdit_omega_L->setPlainText(temp);

        temp = in.readLine();
        omega_i.b = RightRead((temp.toStdString()));
        ui->plainTextEdit_omega_R->setPlainText(temp);

        temp = in.readLine();
        eps_i.a = LeftRead((temp.toStdString()));
        ui->plainTextEdit_eps_L->setPlainText(temp);

        temp = in.readLine();
        eps_i.b = RightRead((temp.toStdString()));
        ui->plainTextEdit_eps_R->setPlainText(temp);

        file.close();
    }
}
