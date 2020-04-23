#include "event.h"
#include <QDebug>
#include "connexion.h"
Event::Event()
{
idevent=0;
nomevent="";
dateevent="";
descevent="";
}
Event::Event(int idevent,QString nomevent,QString dateevent, QString descevent)
{
  this->idevent=idevent;
  this->nomevent=nomevent;
    this->dateevent=dateevent;
    this->descevent=descevent;
}
QString Event::get_nomevent(){return  nomevent;}
QString Event::get_dateevent(){return dateevent;}
QString Event::get_descevent(){return descevent;}
int Event::get_idevent(){return  idevent;}

bool Event::ajouter()
{
QSqlQuery query;
QString res= QString::number(idevent);
query.prepare("INSERT INTO Event (id_event, nom_event, date_event, description_event) "
                    "VALUES (:idevent, :nomevent, :dateevent, :dessevent)");
query.bindValue(":idevent", idevent);
query.bindValue(":nomevent", nomevent);
query.bindValue(":dateevent", dateevent);
query.bindValue(":descevent", descevent);

return    query.exec();
}

QSqlQueryModel * Event::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Event");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idevent"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomevent "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateevent"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("descevent"));
    return model;
}

bool Event::supprimer(int ideventd)
{
QSqlQuery query;
QString res= QString::number(ideventd);
query.prepare("Delete from Event where id_event = :idevent ");
query.bindValue(":idevent", res);
return    query.exec();
}


bool Event::modifier_event(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = nomevent;
query.prepare("UPDATE event set nom_event= :nomevent, date_event= :dateevent, description_event= :descevent WHERE id_event= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":dateevent", dateevent);
    query.bindValue("descevent", descevent);
    query.bindValue(":nomevent", ress);
    return query.exec();
}


