#include "connexion.h"

#include <QSqlError>
Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{
bool test= false;
    db=QSqlDatabase::addDatabase("QODBC"); //DB DRIVER UNIVERSEL
db.setDatabaseName("test123");
db.setUserName("fatma");//inserer nom de l'utilisateur
db.setPassword("fatma");//inserer mot de passe de cet utilisateur

if (db.open()) test = true;
return test;
}

void Connexion::fermerConnexion()
{db.close();}
