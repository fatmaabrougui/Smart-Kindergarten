#ifndef MENU_H
#define MENU_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Menu
{public:
    Menu();
    Menu(int,QString,QString);
    QString get_TEMPS();
    QString get_NOM_MENU();
    int get_ID_MENU();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_menu(int);
    QSqlQueryModel * trie();
private:
    QString NOM_MENU,TEMPS;
    int ID_MENU;
};

#endif // MENU_H
