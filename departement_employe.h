#ifndef DEPARTEMENT_EMPLOYE_H
#define DEPARTEMENT_EMPLOYE_H

#include <QDialog>

namespace Ui {
class departement_employe;
}

class departement_employe : public QDialog
{
    Q_OBJECT

public:
    explicit departement_employe(QWidget *parent = nullptr);
    ~departement_employe();

private:
    Ui::departement_employe *ui;
};

#endif // DEPARTEMENT_EMPLOYE_H
