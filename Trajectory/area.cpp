#include "area.h"
#include "ui_area.h"
#include <QDebug>

Area::Area(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Area)
{
    pathToRes = new QString("/home/midv/Projects/TrajectoryBuilder/Trajectory/resourses/");
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
    number = new QLabel();
    number->setAlignment(Qt::AlignCenter);
    number->setStyleSheet(QString("QLabel{font-size:150%; font-weight:bold; border:1px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    number->setContentsMargins(0,0,0,0);
    horLay->addWidget(number,1);

    QLabel *button = new QLabel();
    button->setStyleSheet(QString("QLabel{border:1px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    button->setContentsMargins(1,1,1,1);
    horLay->addWidget(button,15);
    QHBoxLayout *horLay1 = new QHBoxLayout();
    horLay1->setContentsMargins(0,0,0,0);
    horLay1->setAlignment(Qt::AlignLeft);
    button->setLayout(horLay1);
    areaButton = new QtSvgButton();
    areaButton->setLockalSkin(*pathToRes,"ZmeyH");
    areaButton->setFixedSize(150,150);
    horLay1->addWidget(areaButton,0);
    areaLabel = new QLabel("Area Label");
    areaLabel->setContentsMargins(0,0,0,0);
    areaLabel->setStyleSheet(QString("QLabel{font-size:20px; border:0px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    areaLabel->setAlignment(Qt::AlignCenter);
    horLay1->addWidget(areaLabel,1);

    QLabel *parameter = new QLabel();
    parameter->setStyleSheet(QString("QLabel{border:1px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    parameter->setContentsMargins(1,1,1,1);
    horLay->addWidget(parameter,10);
    QGridLayout *grid = new QGridLayout();
    grid->setContentsMargins(0,0,0,0);
    grid->setSpacing(5);
    parameter->setLayout(grid);
    parameterLabel1 = new QLabel("Parameter 1");
    parameterLabel1->setContentsMargins(0,0,0,0);
    parameterLabel1->setAlignment(Qt::AlignCenter);
    parameterLabel1->setStyleSheet(QString("QLabel{border:0px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    grid->addWidget(parameterLabel1,0,0,1,1,Qt::AlignCenter);

    parameterLabel2 = new QLabel("Parameter 2");
    parameterLabel2->setContentsMargins(0,0,0,0);
    parameterLabel2->setAlignment(Qt::AlignCenter);
    parameterLabel2->setStyleSheet(QString("QLabel{border:0px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    grid->addWidget(parameterLabel2,0,1,1,1,Qt::AlignCenter);

    parameterValue1 = new QSpinBox();
    parameterValue1->setMinimum(0);
    parameterValue1->setMaximum(100);
    parameterValue1->setSingleStep(1);
    parameterValue1->setValue(50);
    grid->addWidget(parameterValue1,1,0,1,1,Qt::AlignCenter);

    parameterValue2 = new QSpinBox();
    parameterValue2->setMinimum(0);
    parameterValue2->setMaximum(100);
    parameterValue2->setSingleStep(1);
    parameterValue2->setValue(50);
    grid->addWidget(parameterValue2,1,1,1,1,Qt::AlignCenter);

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

void Area::InitArea(const int number,
                    const QString skinName,
                    const QString name,
                    const QString parameter1, const int value1,
                    const QString parameter2, const int value2){
    this->number->setText(QString::number(number));
    areaButton->setLockalSkin(*pathToRes, skinName);
    areaLabel->setText(name);
    parameterLabel1->setText(parameter1);
    parameterLabel2->setText(parameter2);
    parameterValue1->setValue(value1);
    parameterValue2->setValue(value2);
}

void Area::timeOut(){
    if (parameterValue1->hasFocus()||parameterValue2->hasFocus()){
        label->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px;background:red}");
    }
    else if (label->geometry().contains(mapFromGlobal(QCursor::pos()))){
        label->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px;background:lightgreen}");
    }
    else {
        label->setStyleSheet(QString("QLabel{border:1px solid gray; border-radius:5px;background: %1}").arg(backgroundColor));
    }
}
