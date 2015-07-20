#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>

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
};

#endif // CHANGE_H
