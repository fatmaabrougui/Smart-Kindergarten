#include "connexion.h"

#include <QSqlError>
Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{
bool test= false;
    db=QSqlDatabase::addDatabase("QODBC"); //DB DRIVER UNIVERSEL
db.setDatabaseName("green");
db.setUserName("aa");//inserer nom de l'utilisateur
db.setPassword("aa2020");//inserer mot de passe de cet utilisateur

if (db.open()) test = true;
return test;
}

void Connexion::fermerConnexion()
{db.close();}
