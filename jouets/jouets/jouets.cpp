#include "jouets.h"
#include <QTabWidget>
#include <QDebug>
#include "connexion.h"
jouets::jouets()
{
    id_jouets=0;
    nom_jouets="";
    qt_jouets=0;
    cat_jouets="";

}
jouets::jouets(int id_jouets,QString nom_jouets,int qt_jouets, QString cat_jouets)
{
  this->id_jouets=id_jouets;
  this->nom_jouets=nom_jouets;
  this->qt_jouets=qt_jouets;
    this->cat_jouets=cat_jouets;
}

QString jouets ::get_nom_jouets(){return  nom_jouets;}

int jouets::get_id_jouets(){return  id_jouets;}

int jouets::get_qt_jouets(){return qt_jouets;}
QString jouets ::get_cat_jouets(){return  cat_jouets;}


bool jouets::ajouter_jouets ()
{
    QSqlQuery query;

    QString res= QString::number(qt_jouets);

    query.prepare("INSERT INTO jouets ( nom_jouets, qt_jouets,cat_jouets) "
                      "VALUES (:nom_jouets, :qt_jouets, :cat_jouets)");
    query.bindValue(":qt_jouets", res);

    query.bindValue(":nom_jouets", nom_jouets);
  query.bindValue(":cat_jouets", cat_jouets);

    //query.bindValue(":capacite", capacite);

    return    query.exec();

}

QSqlQueryModel * jouets::afficher_jouets()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from jouets ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_jouets"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_jouets "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("qt_jouets"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("cat_jouets"));

    return model;
}
bool jouets::supprimer_jouets(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from jouets where ID_jouets = :id_jouets");
query.bindValue(":id_jouets", res);
return    query.exec();
}

bool jouets::modifier_jouets(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = QString::number(qt_jouets);
//query.prepare("UPDATE jouets "" SET ID_jouets = :id_jouets, nom_jouets = :nom_jouets, qt_jouets = :qt_jouets, cat_jouets= :cat_jouets,  ""WHERE ID_jouets = :cod");
query.prepare("UPDATE jouets set nom_jouets= :nom_jouets, qt_jouets= :qt_jouets, cat_jouets= :cat_jouets where id_jouets= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":nom_jouets", nom_jouets);
    //query.bindValue(":qt_jouets", qt_jouets);
query.bindValue(":qt_jouets", ress);
query.bindValue(":cat_jouets", cat_jouets);

    return query.exec();
}

QSqlQueryModel * jouets::trier()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from jouets order by qt_jouets ASC");
    return model;
}
