#ifndef ALIMENT_MENU_H
#define ALIMENT_MENU_H

#include <QDialog>

namespace Ui {
class aliment_menu;
}

class aliment_menu : public QDialog
{
    Q_OBJECT

public:
    explicit aliment_menu(QWidget *parent = nullptr);
    ~aliment_menu();

private:
    Ui::aliment_menu *ui;
};

#endif // ALIMENT_MENU_H
