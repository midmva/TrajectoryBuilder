#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include "QtSvgButton"
#include "change.h"
#include "area.h"

namespace Ui {
class Trajectory;
}

class Trajectory : public QWidget
{
    Q_OBJECT

public:
    explicit Trajectory(QWidget *parent = 0);
    ~Trajectory();
    QList<QStringList> getTrajectory();
    void setTrajectory(const QList<QStringList> list);

private:
    Ui::Trajectory *ui;
    QVBoxLayout *trajLayer;
    QtSvgButton *addButton;
    Change *change;

    QList<Area *> *list;

private slots:
    void ShowChange();
    void ChangeManeur(int index);
    void Renumber(Area * ptr);
};

#endif // TRAJECTORY_H
