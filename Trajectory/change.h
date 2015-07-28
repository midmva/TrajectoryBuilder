#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class Change;
}

class Change : public QWidget
{
    Q_OBJECT

public:
    explicit Change(QWidget *parent = 0);
    ~Change();


private:
    Ui::Change *ui;
    QString *pathToRes;

private slots:
    void pressButton1();
    void pressButton2();
    void pressButton3();
    void pressButton4();
    void pressButton5();
    void pressButton6();
    void pressButton7();

signals:
    void pressButton(int index);
};

#endif // CHANGE_H
