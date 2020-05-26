#ifndef ESPACE_JOUET_H
#define ESPACE_JOUET_H

#include <QDialog>

namespace Ui {
class espace_jouet;
}

class espace_jouet : public QDialog
{
    Q_OBJECT

public:
    explicit espace_jouet(QWidget *parent = nullptr);
    ~espace_jouet();

private:
    Ui::espace_jouet *ui;
};

#endif // ESPACE_JOUET_H
