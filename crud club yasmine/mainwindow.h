#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "club.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    bool on_pb_chercherC_released();

    void on_pb_confirmerC_released();

private:
    Ui::MainWindow *ui;
    Club tmpclub;
};

#endif // MAINWINDOW_H
