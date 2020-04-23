#include "event.h"
#include "club.h"
#include <QDebug>
#include "connexion.h"


/*************************club*********************************/

Club::Club()
{
idclub=0;
nomclub="";
categclub="";
descclub="";
}
Club::Club(int idclub,QString nomclub,QString categclub, QString descclub)
{
  this->idclub=idclub;
  this->nomclub=nomclub;
    this->categclub=categclub;
    this->descclub=descclub;
}
QString Club::get_nomclub(){return  nomclub;}
QString Club::get_categclub(){return categclub;}
QString Club::get_descclub(){return descclub;}
int Club::get_idclub(){return  idclub;}

bool Club::ajouter()
{
QSqlQuery query;
QString res= QString::number(idclub);
query.prepare("INSERT INTO Club (id_club, nom_club, categorie_club, description_club) "
                    "VALUES (:idclub, :nomclub, :categclub, :dessclub)");
query.bindValue(":idclub", idclub);
query.bindValue(":nomclub", nomclub);
query.bindValue(":categclub", categclub);
query.bindValue(":descclub", descclub);

return    query.exec();
}

QSqlQueryModel * Club::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Club");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idclub"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomclub "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("categclub"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("descclub"));
    return model;
}

bool Club::supprimer(int idclubd)
{
QSqlQuery query;
QString res= QString::number(idclubd);
query.prepare("Delete from Club where id_club = :idclub ");
query.bindValue(":idclub", res);
return    query.exec();
}


bool Club::modifier_club(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = nomclub;
query.prepare("UPDATE club set nom_club= :nomclub, categorie_club= :categclub, description_club= :descclub WHERE id_club= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":categclub", categclub);
    query.bindValue("descclub", descclub);
    query.bindValue(":nomclub", ress);
    return query.exec();
}



/*************************event*********************************/

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


