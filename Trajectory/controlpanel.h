#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QLabel>
#include "QtSvgButton"

namespace Ui {
class ControlPanel;
}

class ControlPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ControlPanel(QWidget *parent = 0);
    ~ControlPanel();

private:
    Ui::ControlPanel *ui;
    QVBoxLayout *verLay;
    QString style_gray;
    QString style_green;
    QString style_no_border;
    QLabel *trajectory_area_1;
    QLabel *trajectory_area_2;
    QLabel *trajectory_area_3;
    QLabel *trajectory_area_4;

private slots:
    void pressButton1();
    void pressButton2();
    void pressButton3();
    void pressButton4();

signals:
    void changeTrajectory(int number);
};

#endif // CONTROLPANEL_H
