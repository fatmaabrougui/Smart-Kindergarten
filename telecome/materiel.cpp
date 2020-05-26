#include "materiel.h"
#include "salle.h"
#include <QTabWidget>
#include <QDebug>
#include "connexion.h"
#include "smtp.h"
#include <QSqlRecord>
materiel::materiel()
{
    id_materiel=0;
    nom="";
    etat=0;
    nombre=0;
    id_salle=0;
    total_panne=0;
}
materiel::materiel(int id_materiel,QString nom,int etat,int nombre,int id_salle,int total_panne)
{
this->id_materiel=id_materiel;
this->nom=nom;
this->etat=etat;
this->nombre=nombre;
this->id_salle=id_salle;
this->total_panne=total_panne;

}

QString materiel ::get_nom(){return  nom;}

int materiel::get_id_materiel(){return  id_materiel;}

int materiel::get_etat(){return etat;}

int materiel::get_nombre(){return nombre;}
int materiel::get_id_salle(){return id_salle;}

int materiel::get_total_panne(){return total_panne;}

bool materiel::ajouter_materiel ()
{
    QSqlQuery query;

    QString res= QString::number(etat);
    QString ress= QString::number(nombre);
        QString resss= QString::number(id_salle);

     query.prepare("INSERT INTO materiel ( NOM, ETAT,NOMBRE, ID_SALLE) "
                      "VALUES (:nom, :etat,:nombre,:id_salle)");
     query.bindValue(":etat", res);
     query.bindValue(":nombre", ress);
      query.bindValue(":id_salle", resss);
     query.bindValue(":nom", nom);
    //query.bindValue(":capacite", capacite);

    return    query.exec();

}

QSqlQueryModel * materiel::afficher_materiel()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from materiel ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_materiel"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_salle"));
    return model;
}
bool materiel::supprimer_materiel(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from materiel where ID_materiel = :id_materiel");
query.bindValue(":id_materiel", res);
return    query.exec();
}

bool materiel::modifier_materiel(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = QString::number(etat);
    QString resss = QString::number(nombre);

query.prepare("UPDATE materiel set nom= :nom, etat= :etat, nombre= :nombre where id_materiel= :cod");
    query.bindValue(":cod", res);
   query.bindValue(":nom", nom);
query.bindValue(":etat", ress);
query.bindValue(":nombre", resss);
    return query.exec();
}

int materiel :: alert ()
{

    QSqlQuery q;



    QString nom;
    int id_materiel=0,etat=0,nombre=0,id_salle=0,total_panne=0;
materiel m(id_materiel, nom, etat,nombre,id_salle,total_panne);

  //QMessageBox::information(this, tr("Modifier Materiel"), tr("a"));

  QString a = QString::number(etat);
   QString b = QString::number(total_panne);
 q .prepare("SELECT * FROM materiel where etat=0");

       q.bindValue(":etat", a);
       //QMessageBox::information(this, tr("Modifier Materiel"), tr("A"));

       q.bindValue(":total_panne", b);
       //QMessageBox::information(this, tr("Modifier Materiel"), tr("B"));

if (q.exec()) {

    while (q.next())
        total_panne++;



}


     return total_panne;




}

int panne=0;
int n_panne=0;






int materiel :: calcul_panne ()
{
    QSqlQuery q;
    int panne=0;
    q.prepare("SELECT * FROM materiel WHERE etat = 0 ");
    q.exec();
      while (q.next())
    {
    panne++;
    }

  return panne;


}
int  materiel ::calcul_betat ()
{

    QSqlQuery q;
    int n_panne=0;
    q.prepare("SELECT * FROM materiel WHERE etat=1");
    q.exec();
      while (q.next())
    {
     n_panne++;
    }

    return n_panne;





}
