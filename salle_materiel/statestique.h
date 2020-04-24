#ifndef STATESTIQUE_H
#define STATESTIQUE_H

#include <QDialog>
#include "qcustomplot.h"


namespace Ui {
class statestique;
}

class statestique : public QDialog
{
    Q_OBJECT

public:
    explicit statestique(QWidget *parent = 0);
    ~statestique();
private slots:

    //void makePlot();



private:
    Ui::statestique *ui;
    QCustomPlot *customPlot;
};
#endif // STATESTIQUE_H
