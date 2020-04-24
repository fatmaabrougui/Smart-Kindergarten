#ifndef SALLE_MATERIEL_H
#define SALLE_MATERIEL_H

#include <QDialog>

namespace Ui {
class salle_materiel;
}

class salle_materiel : public QDialog
{
    Q_OBJECT

public:
    explicit salle_materiel(QWidget *parent = nullptr);
    ~salle_materiel();

private:
    Ui::salle_materiel *ui;
};

#endif // SALLE_MATERIEL_H
