#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Departement
{public:
    Departement();
    Departement(int,QString,int);
    QString get_nom();
    int get_id();
    int get_places();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_departement(int);
private:
    QString nom_departement;
    int id_departement,places_disponibles;
};

#endif // DEPARTEMENT_H
