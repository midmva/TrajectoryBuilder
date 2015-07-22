#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include "QtSvgButton"
#include "change.h"
#include "area.h"

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
    QVBoxLayout *trajLayer;
    QtSvgButton *addButton;
    Change *change;
    QString *pathToRes;
    QStringList *nameSkin;
    QStringList *nameArea;
    QStringList *nameParameter;


private slots:
    void ShowChange();
    void ChangeManeur(int index);
};

#endif // MAINWINDOW_H
