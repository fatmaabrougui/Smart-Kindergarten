#ifndef CLUB_H
#define CLUB_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Club
{public:
    Club();
    Club(int,QString,QString,QString);
    QString get_nomclub();
    QString get_categclub();
    QString get_descclub();
    int get_idclub();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_club(int);
private:
    QString nomclub,categclub,descclub;
    int idclub;
};

#endif // CLUB_H
