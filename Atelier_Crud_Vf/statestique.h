#ifndef statestique_H
#define statestique_H
#include <QString>

#include <QDialog>

namespace Ui {
class statestique;
}

class statestique : public QDialog
{
    Q_OBJECT

public:
  /*  explicit statestique(QWidget *parent = nullptr);
    ~statestique();*/
    void paintEvent(QPaintEvent *);
    int statestique_partie2();
    int statestique_partie1();


};

#endif // statestique_H
