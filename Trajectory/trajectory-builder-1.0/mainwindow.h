#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QtXml>
#include <QFile>
#include <QMessageBox>
#include "QtSvgButton"
#include "change.h"
#include "area.h"
#include "trajectory.h"
#include "controlpanel.h"
#include "graftrajectory.h"

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
    GrafTrajectory *graf[4];
    int show_trajectory;
    bool mode;
    void parceXml(QDomNode node);


private slots:
    void changeTrajectory(const int number);
    void changeMode(const bool mode);
    void loadFile(const QString name);
    void saveFile(const QString name);


};

extern QStringList *nameSkin;
extern QStringList *nameArea;
extern QStringList *nameParameter;
extern     QString *pathToRes;


#endif // MAINWINDOW_H
