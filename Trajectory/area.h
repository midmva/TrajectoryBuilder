#ifndef AREA_H
#define AREA_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpinBox>
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

    void InitArea(const int number,
                  const QString skinName,
                  const QString name,
                  const QString parameter1, const int value1,
                  const QString parameter2, const int value2);

private:
    Ui::Area *ui;
    QString *pathToRes;
    QLabel *label;
    QString backgroundColor;
    QtSvgButton *areaButton;
    QLabel *number;
    QLabel *areaLabel;
    QLabel *parameterLabel1;
    QLabel *parameterLabel2;
    QSpinBox *parameterValue1;
    QSpinBox *parameterValue2;

private slots:
    void timeOut();
};

#endif // AREA_H
