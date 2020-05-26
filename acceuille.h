#ifndef ACCEUILLE_H
#define ACCEUILLE_H

#include <QDialog>

namespace Ui {
class Acceuille;
}

class Acceuille : public QDialog
{
    Q_OBJECT

public:
    explicit Acceuille(QWidget *parent = nullptr);
    ~Acceuille();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Acceuille *ui;
};

#endif // ACCEUILLE_H
