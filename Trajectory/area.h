#ifndef AREA_H
#define AREA_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "QtSvgButton"
#include <QTimer>


namespace Ui {
class Area;
}

class Area : public QWidget
{
    Q_OBJECT

public:
    explicit Area(QWidget *parent = 0);
    ~Area();

private:
    Ui::Area *ui;
    QLabel *label;
    QString backgroundColor;
private slots:
    void timeOut();
};

#endif // AREA_H
