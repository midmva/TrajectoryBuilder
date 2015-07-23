#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include "QtSvgButton"
#include "change.h"
#include "area.h"
#include "trajectory.h"
#include "controlpanel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QHBoxLayout *horLay;
    Trajectory * trajectory[4];
    int show_trajectory;

private slots:
    void changeTrajectory(int number);

};

extern QStringList *nameSkin;
extern QStringList *nameArea;
extern QStringList *nameParameter;
extern     QString *pathToRes;


#endif // MAINWINDOW_H
