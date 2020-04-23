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
    QString get_dateevent();
    QString get_descevent();
    int get_idevent();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_event(int);
private:
    QString nomevent,dateevent,descevent;
    int idevent;
};


#endif // EVENT_H
