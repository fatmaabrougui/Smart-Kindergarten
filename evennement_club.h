#ifndef EVENNEMENT_CLUB_H
#define EVENNEMENT_CLUB_H

#include <QDialog>

namespace Ui {
class evennement_club;
}

class evennement_club : public QDialog
{
    Q_OBJECT

public:
    explicit evennement_club(QWidget *parent = nullptr);
    ~evennement_club();

private:
    Ui::evennement_club *ui;
};

#endif // EVENNEMENT_CLUB_H
