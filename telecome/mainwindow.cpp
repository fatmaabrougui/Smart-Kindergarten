#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "acceuille.h"

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
    hide();
    Acceuille Acceuille;
    Acceuille.setModal(true);
    Acceuille.exec();
}
