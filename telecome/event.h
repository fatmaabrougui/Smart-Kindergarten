#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Event
{public:
    Event();
    Event(int,QString,QString,QString);
    QString get_nomevent();
    QString get_descevent();
    QString get_dateevent();
    int get_idevent();
    bool ajouterE();
    QSqlQueryModel * afficherE();
    QSqlQueryModel * trier();
    bool supprimerE(int);
    bool modifier_event(int);
private:
    QString nomevent,descevent,dateevent;
    int idevent;
};


#endif // EVENT_H
