#include "statestique.h"
#include <QSqlQuery>
#include <QPainter>
#include <QString>
#include "ui_statestique.h"
#include <QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QVariant>

statestique::statestique (QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statestique)
{
    ui->setupUi(this);
}

statestique::~statestique()
{
    delete ui;
}


int statestique::statestique_partie1()
{  QString a="playground";

    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from espace where fonction_espace='"+a+"'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}

int statestique::statestique_partie2()
{

    QString b=" Salle de jeux";
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from CHARIOTS where fonction_espace='"+b+"'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}

void statestique::paintEvent(QPaintEvent *)
{

    int a=statestique_partie1();
  //  cout<<a<<endl  ;
    int b=statestique_partie2();
  //  cout<<b<<endl ;

    int s1= a*100 ;
        int nb = a+b;
        int q1 ;
        q1 = s1/nb ;
        int x  ;
        x= (q1*360)/100 ;

    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-100,this->width()-100);
    painter.setBrush(Qt::yellow);
    painter.drawPie(size,0,16*x);
    ui->labeluno->setText("fonction:playground") ;

    painter.setBrush(Qt::green);
    painter.drawPie(size,16*x,16*x);
    ui->labeldos->setText("fonction: salle de jeux") ;


}
