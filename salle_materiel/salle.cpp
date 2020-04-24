#include "salle.h"
#include <QDebug>
#include "connexion.h"


//----------------------------------

#include <QPdfWriter>

#include<QString>
#include <QFileDialog>
#include <QDate>
#include <QApplication>
#include <QTextStream>
#include <QInputDialog>
#include <QIODevice>
#include <QFile>
#include<QPdfWriter>
#include<QPainter>
#include<QPrinter>
#include<QDesktopServices>








//-----------------------------------











salle::salle()
{
    id_salle=0;
    fonction="";
    capacite=0;
}
salle::salle(int id_salle,QString fonction,int capacite)
{
  this->id_salle=id_salle;
  this->fonction=fonction;
  this->capacite=capacite;
}

QString salle ::get_fonction(){return  fonction;}
int salle::get_id_salle(){return  id_salle;}
int salle::get_capacite(){return capacite;}
bool salle::ajouter_salle ()
{
QSqlQuery query;

QString res= QString::number(capacite);

query.prepare("INSERT INTO salle ( FONCTION, CAPACITE) "
                  "VALUES (:fonction, :capacite)");
query.bindValue(":capacite", res);

query.bindValue(":fonction", fonction);
//query.bindValue(":capacite", capacite);

return    query.exec();

}

QSqlQueryModel * salle::afficher_salle()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from salle ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_salle"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Fonction "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Capacité"));
    return model;
}
bool salle::supprimer_salle(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from salle where ID_SALLE = :id_salle");
query.bindValue(":id_salle", res);
return    query.exec();
}

bool salle::modifier_salle(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = QString::number(capacite);
//query.prepare("UPDATE salle "" SET ID_SALLE = :id_salle, FONCTION = :fonction, CAPACITE = :capacite,  ""WHERE ID_SALLE = :cod");
query.prepare("UPDATE salle set FONCTION= :fonction, CAPACITE= :capacite where id_salle= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":fonction", fonction);
    //query.bindValue(":capacite", capacite);
query.bindValue(":capacite", ress);
    return query.exec();
}

QSqlQueryModel * salle::trie()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from salle order by capacite ASC");
    return model;
}



/*bool salle::pdf(QString chemin,QString txt )
{

    QPdfWriter pdf(chemin);
    QSqlQuery query;

            pdf.setPageSize(QPagedPaintDevice::A4);
            pdf.setPageMargins(QMargins(30, 30, 30, 30));
 QString fonc;
 int capac,ids ;
            QSqlQuery qry;
            qry.exec("select * from salle where fonction = '"+txt+"'   ");

            if(qry.next())
            {
            fonc=qry.value(0).toString();


            capac =qry.value(1).toInt();
             ids =qry.value(2).toInt();


            }

            QString capac1=QString::number(capac);
            QPainter painter(&pdf);
            QRect r = painter.viewport();
            painter.setPen(Qt::black);
            painter.setFont(QFont("Times", 25));

         //   painter.drawImage(QRect(0, 30, 1500, 1061),QImage("C:/Users/MON HP/Desktop/eeeee.jpg"));

            painter.setPen(Qt::black);
            painter.setFont(QFont("Times", 10));
            QString citydate = "Tunis, ";
            QDate date = QDate::currentDate();
            citydate += date.toString("dd.MM.yyyy");
            painter.drawText(r, Qt::AlignRight, citydate);

            painter.setPen(Qt::black);
            painter.setFont(QFont("Times", 20));
 QString res = QString::number(capac);
  QString ress = QString::number(ids);

               painter.drawText(3500,4950,ress);
               painter.drawText(3500,5400,res);
               painter.drawText(3500,5850,fonc);

query.bindValue(":capac", res);
query.bindValue(":ids", ress);

            QString i="id_salle:",f="fonction",c="capacite";
            painter.setPen(Qt::blue);

               painter.drawText(1300,4950,i);
               painter.drawText(1300,5400,f);
               painter.drawText(1300,5850,c);





            painter.end();

            QDesktopServices::openUrl(QUrl::fromLocalFile(chemin));
            return true;
}
*/
bool salle:: afficher_seule_salle (QString fct)
{
    QSqlQuery qry;
    QString req="select * from salle where fonction = fct ";
    qry.prepare(req);
  qry.bindValue(":fonction", fonction);
  return qry.exec ();

}



QSqlQueryModel * salle::aff_seule_salle()
{
    QSqlQueryModel * model= new QSqlQueryModel();
//model->setQuery("select * from salle ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_salle"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Fonction "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Capacité"));
    return model;
}



QSqlQueryModel * salle::rechercher(QString fonction)
{
    QSqlQueryModel *model = new QSqlQueryModel;
        QSqlQuery query ;


              model->setQuery("SELECT * FROM salle where fonction like '"+fonction+"'  "  );
                return model;
}


