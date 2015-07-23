#include "controlpanel.h"
#include "ui_controlpanel.h"
#include "mainwindow.h"

ControlPanel::ControlPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlPanel)
{
    ui->setupUi(this);
    setFixedWidth(200);
    verLay = new QVBoxLayout(this);
    QLabel *trajectory_area = new QLabel();
    trajectory_area->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px}");
    trajectory_area->setFixedHeight(216);
    QVBoxLayout *layVer = new QVBoxLayout(trajectory_area);
    layVer->setContentsMargins(2,2,2,2);
    layVer->setSpacing(2);
    layVer->setAlignment(Qt::AlignTop);
    QLabel *trajectory_area_1 = new QLabel();
    trajectory_area_1->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px; background:lightgreen}");
    trajectory_area_1->setFixedHeight(50);
    QHBoxLayout *layHor1 = new QHBoxLayout(trajectory_area_1);
    layHor1->setContentsMargins(1,1,1,1);
    QLabel *trajectory_label_1 = new QLabel("Траектория 1");
    trajectory_label_1->setAlignment(Qt::AlignCenter);
    trajectory_label_1->setStyleSheet("QLabel{border:0px solid gray; border-radius:5px}");
    //trajectory_label->setFixedHeight(48);
    layHor1->addWidget(trajectory_label_1);
    QtSvgButton *trajectory_button_1 = new QtSvgButton();
    trajectory_button_1->setLockalSkin(*pathToRes,"BerylSquare");
    trajectory_button_1->setFixedSize(50,50);
    layHor1->addWidget(trajectory_button_1);
    layVer->addWidget(trajectory_area_1);

    QLabel *trajectory_area_2 = new QLabel();
    trajectory_area_2->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px;}");
    trajectory_area_2->setFixedHeight(50);
    QHBoxLayout *layHor2 = new QHBoxLayout(trajectory_area_2);
    layHor2->setContentsMargins(1,1,1,1);
    QLabel *trajectory_label_2 = new QLabel("Траектория 2");
    trajectory_label_2->setAlignment(Qt::AlignCenter);
    trajectory_label_2->setStyleSheet("QLabel{border:0px solid gray; border-radius:5px}");
    //trajectory_label->setFixedHeight(48);
    layHor2->addWidget(trajectory_label_2);
    QtSvgButton *trajectory_button_2 = new QtSvgButton();
    trajectory_button_2->setLockalSkin(*pathToRes,"BerylSquare");
    trajectory_button_2->setFixedSize(50,50);
    layHor2->addWidget(trajectory_button_2);
    layVer->addWidget(trajectory_area_2);

    QLabel *trajectory_area_3 = new QLabel();
    trajectory_area_3->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px;}");
    trajectory_area_3->setFixedHeight(52);
    QHBoxLayout *layHor3 = new QHBoxLayout(trajectory_area_3);
    layHor3->setContentsMargins(1,1,1,1);
    QLabel *trajectory_label_3 = new QLabel("Траектория 3");
    trajectory_label_3->setAlignment(Qt::AlignCenter);
    trajectory_label_3->setStyleSheet("QLabel{border:0px solid gray; border-radius:5px}");
    //trajectory_label->setFixedHeight(48);
    layHor3->addWidget(trajectory_label_3);
    QtSvgButton *trajectory_button_3 = new QtSvgButton();
    trajectory_button_3->setLockalSkin(*pathToRes,"BerylSquare");
    trajectory_button_3->setFixedSize(50,50);
    layHor3->addWidget(trajectory_button_3);
    layVer->addWidget(trajectory_area_3);

    QLabel *trajectory_area_4 = new QLabel();
    trajectory_area_4->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px;}");
    trajectory_area_4->setFixedHeight(52);
    QHBoxLayout *layHor4 = new QHBoxLayout(trajectory_area_4);
    layHor4->setContentsMargins(1,1,1,1);
    QLabel *trajectory_label_4 = new QLabel("Траектория 4");
    trajectory_label_4->setAlignment(Qt::AlignCenter);
    trajectory_label_4->setStyleSheet("QLabel{border:0px solid gray; border-radius:5px}");
    //trajectory_label->setFixedHeight(48);
    layHor4->addWidget(trajectory_label_4);
    QtSvgButton *trajectory_button_4 = new QtSvgButton();
    trajectory_button_4->setLockalSkin(*pathToRes,"BerylSquare");
    trajectory_button_4->setFixedSize(50,50);
    layHor4->addWidget(trajectory_button_4);
    layVer->addWidget(trajectory_area_4);

    verLay->addWidget(trajectory_area);
    verLay->addStretch(1);
    QLabel *control_area = new QLabel();
    control_area->setStyleSheet("QLabel{border:1px solid gray; border-radius:5px}");
    control_area->setFixedHeight(100);
    verLay->addWidget(control_area,1);
}

ControlPanel::~ControlPanel()
{
    delete ui;

}
