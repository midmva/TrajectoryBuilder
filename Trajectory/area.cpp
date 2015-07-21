#include "area.h"
#include "ui_area.h"
#include <QDebug>

Area::Area(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Area)
{
    ui->setupUi(this);
    backgroundColor = palette().background().color().name();
    QHBoxLayout *generalLay = new QHBoxLayout(this);
    generalLay->setContentsMargins(0,0,0,0);
    label = new QLabel();
    label->setFixedSize(this->size());
    label->setContentsMargins(0,0,0,0);
    label->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px}");
    generalLay->addWidget(label);

    QHBoxLayout *horLay = new QHBoxLayout();
    horLay->setSpacing(5);
    horLay->setContentsMargins(5,5,5,5);
    QLabel *number = new QLabel();
    number->setStyleSheet(QString("QLabel{border:1px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    number->setContentsMargins(0,0,0,0);
    horLay->addWidget(number,1);

    QLabel *button = new QLabel();
    button->setStyleSheet(QString("QLabel{border:1px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    button->setContentsMargins(0,0,0,0);
    horLay->addWidget(button,15);

    QLabel *parameter = new QLabel();
    parameter->setStyleSheet(QString("QLabel{border:1px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    parameter->setContentsMargins(0,0,0,0);
    horLay->addWidget(parameter,10);

    label->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px}");
    label->setLayout(horLay);

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),SLOT(timeOut()));
    timer->start(40);
}

Area::~Area()
{
    delete ui;
}

void Area::timeOut(){
    if (label->geometry().contains(mapFromGlobal(QCursor::pos()))){
        label->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px;background:lightgreen}");
    }
    else {
        label->setStyleSheet(QString("QLabel{border:1px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    }
}
