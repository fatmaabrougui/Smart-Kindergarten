#ifndef STATESTIQUE_H
#define STATESTIQUE_H

#include <QDialog>
#include <QPainter>
#include<QPaintEvent>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class statestique;
}

class statestique : public QDialog
{
    Q_OBJECT

public:
    explicit statestique(QWidget *parent = nullptr);
    ~statestique();
        int statestique_partie2();
        int statestique_partie1();
        void paintEvent(QPaintEvent *);


private:
    Ui::statestique *ui;
};

#endif // STATESTIQUE_H
