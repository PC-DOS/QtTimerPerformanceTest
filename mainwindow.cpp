#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTimer>

int iTotal=0;
int iCurrent=0;
int iFps=1;
QTimer * tmrFpsCounter;
QTimer * tmrGenerator;

void MainWindow::CountTotal(){
    ++iTotal;
    ++iCurrent;
    ui->lblTotal->setText(QString::number(iTotal)+QString(" Counts"));
    ui->lblFps->setText(QString::number(iFps)+QString(" fps"));
}

void MainWindow::CalcFps(){
    iFps=iCurrent;
    iCurrent=0;
    ui->lblTotal->setText(QString::number(iTotal)+QString(" Counts"));
    ui->lblFps->setText(QString::number(iFps)+QString(" fps"));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lblTotal->setText(QString::number(iTotal)+QString(" Counts"));
    ui->lblFps->setText(QString::number(iFps)+QString(" fps"));
    tmrFpsCounter=new QTimer(this);
    connect(tmrFpsCounter, SIGNAL(timeout()), this, SLOT(CalcFps()));
    tmrFpsCounter->start(1000);
    tmrGenerator=new QTimer(this);
    connect(tmrGenerator, SIGNAL(timeout()), this, SLOT(CountTotal()));
    tmrGenerator->start(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
