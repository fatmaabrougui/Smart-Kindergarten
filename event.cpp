#include "event.h"
#include <QDebug>
#include "connexion.h"
Event::Event()
{
idevent=0;
nomevent="";
descevent="";
dateevent="";
}
Event::Event(int idevent,QString nomevent, QString descevent,QString dateevent)
{
  this->idevent=idevent;
  this->nomevent=nomevent;
    this->descevent=descevent;
    this->dateevent=dateevent;
}
QString Event::get_nomevent(){return  nomevent;}
QString Event::get_descevent(){return descevent;}
QString Event::get_dateevent(){return dateevent;}
int Event::get_idevent(){return  idevent;}

bool Event::ajouterE()
{
QSqlQuery query;
QString res= QString::number(idevent);
query.prepare("INSERT INTO Event (idevent, nomevent, descevent, dateevent) "
                    "VALUES (:idevent, :nomevent, :descevent, :dateevent)");
query.bindValue(":idevent", idevent);
query.bindValue(":nomevent", nomevent);
query.bindValue(":descevent", descevent);
query.bindValue(":dateevent", dateevent);

return    query.exec();
}

QSqlQueryModel * Event::afficherE()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Event");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idevent"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomevent "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("descevent"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateevent"));
    return model;
}

bool Event::supprimerE(int ideventd)
{
QSqlQuery query;
QString res= QString::number(ideventd);
query.prepare("Delete from Event where idevent = :idevent ");
query.bindValue(":idevent", res);
return    query.exec();
}


bool Event::modifier_event(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = QString::number(idevent);
query.prepare("UPDATE event set  descevent= :descevent, dateevent= :dateevent,nomevent= :nomevent WHERE idevent= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":idevent", ress);
    query.bindValue(":descevent", descevent);
    query.bindValue(":dateevent", dateevent);
    query.bindValue(":nomevent", nomevent);
    return query.exec();
}
QSqlQueryModel * Event::trier()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from event order by idevent ASC");
    return model;
}


