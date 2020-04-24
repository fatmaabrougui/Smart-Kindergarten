#ifndef stat_H
#define stat_H
#include <QPainter>
#include<QPaintEvent>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {class stati;}
QT_END_NAMESPACE

class stati : public QDialog
{
    Q_OBJECT

public:
    explicit stati(QWidget *parent = nullptr);
    ~stati();
    void paintEvent(QPaintEvent *);
    int stat_partie2();
    int stat_partie1();

private:
    Ui::stati *ui;
};

#endif // stat_H
