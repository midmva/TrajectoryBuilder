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
    style_gray = "QLabel{border:1px solid gray; border-radius:5px}";
    style_no_border = "QLabel{border:0px solid gray; border-radius:5px}";
    style_green = "QLabel{border:1px solid gray; border-radius:5px; background:lightgreen}";
    QLabel *trajectory_area = new QLabel();
    trajectory_area->setStyleSheet(style_gray);
    trajectory_area->setFixedHeight(216);
    QVBoxLayout *layVer = new QVBoxLayout(trajectory_area);
    layVer->setContentsMargins(2,2,2,2);
    layVer->setSpacing(2);
    layVer->setAlignment(Qt::AlignTop);
    trajectory_area_1 = new QLabel();
    trajectory_area_1->setStyleSheet(style_green);
    trajectory_area_1->setFixedHeight(50);
    QHBoxLayout *layHor1 = new QHBoxLayout(trajectory_area_1);
    layHor1->setContentsMargins(1,1,1,1);
    QLabel *trajectory_label_1 = new QLabel("Траектория 1");
    trajectory_label_1->setAlignment(Qt::AlignCenter);
    trajectory_label_1->setStyleSheet(style_no_border);
    //trajectory_label->setFixedHeight(48);
    layHor1->addWidget(trajectory_label_1);
    QtSvgButton *trajectory_button_1 = new QtSvgButton();
    connect(trajectory_button_1,SIGNAL(clicked()),SLOT(pressButton1()));
    trajectory_button_1->setLockalSkin(*pathToRes,"BerylSquare");
    trajectory_button_1->setFixedSize(50,50);
    layHor1->addWidget(trajectory_button_1);
    layVer->addWidget(trajectory_area_1);

    trajectory_area_2 = new QLabel();
    trajectory_area_2->setStyleSheet(style_gray);
    trajectory_area_2->setFixedHeight(50);
    QHBoxLayout *layHor2 = new QHBoxLayout(trajectory_area_2);
    layHor2->setContentsMargins(1,1,1,1);
    QLabel *trajectory_label_2 = new QLabel("Траектория 2");
    trajectory_label_2->setAlignment(Qt::AlignCenter);
    trajectory_label_2->setStyleSheet(style_no_border);
    layHor2->addWidget(trajectory_label_2);
    QtSvgButton *trajectory_button_2 = new QtSvgButton();
    connect(trajectory_button_2,SIGNAL(clicked()),SLOT(pressButton2()));
    trajectory_button_2->setLockalSkin(*pathToRes,"BerylSquare");
    trajectory_button_2->setFixedSize(50,50);
    layHor2->addWidget(trajectory_button_2);
    layVer->addWidget(trajectory_area_2);

    trajectory_area_3 = new QLabel();
    trajectory_area_3->setStyleSheet(style_gray);
    trajectory_area_3->setFixedHeight(52);
    QHBoxLayout *layHor3 = new QHBoxLayout(trajectory_area_3);
    layHor3->setContentsMargins(1,1,1,1);
    QLabel *trajectory_label_3 = new QLabel("Траектория 3");
    trajectory_label_3->setAlignment(Qt::AlignCenter);
    trajectory_label_3->setStyleSheet(style_no_border);
    layHor3->addWidget(trajectory_label_3);
    QtSvgButton *trajectory_button_3 = new QtSvgButton();
    connect(trajectory_button_3,SIGNAL(clicked()),SLOT(pressButton3()));
    trajectory_button_3->setLockalSkin(*pathToRes,"BerylSquare");
    trajectory_button_3->setFixedSize(50,50);
    layHor3->addWidget(trajectory_button_3);
    layVer->addWidget(trajectory_area_3);

    trajectory_area_4 = new QLabel();
    trajectory_area_4->setStyleSheet(style_gray);
    trajectory_area_4->setFixedHeight(52);
    QHBoxLayout *layHor4 = new QHBoxLayout(trajectory_area_4);
    layHor4->setContentsMargins(1,1,1,1);
    QLabel *trajectory_label_4 = new QLabel("Траектория 4");
    trajectory_label_4->setAlignment(Qt::AlignCenter);
    trajectory_label_4->setStyleSheet(style_no_border);
    //trajectory_label->setFixedHeight(48);
    layHor4->addWidget(trajectory_label_4);
    QtSvgButton *trajectory_button_4 = new QtSvgButton();
    connect(trajectory_button_4,SIGNAL(clicked()),SLOT(pressButton4()));
    trajectory_button_4->setLockalSkin(*pathToRes,"BerylSquare");
    trajectory_button_4->setFixedSize(50,50);
    layHor4->addWidget(trajectory_button_4);
    layVer->addWidget(trajectory_area_4);

    verLay->addWidget(trajectory_area);

    verLay->addStretch(1);

    QLabel *graf_area = new QLabel();
    graf_area->setStyleSheet(style_gray);
    graf_area->setFixedHeight(60);
    graf_area->setContentsMargins(3,3,3,3);
    QHBoxLayout *lay1 = new QHBoxLayout();
    graf_area->setLayout(lay1);
    lay1->setContentsMargins(0,0,0,0);
    QLabel *button_area = new QLabel();
    button_area->setStyleSheet(style_gray);
    button_area->setContentsMargins(1,1,1,1);
    lay1->addWidget(button_area);
    QHBoxLayout *lay2 = new QHBoxLayout();
    lay2->setContentsMargins(0,0,0,0);
    button_area->setLayout(lay2);
    label = new QLabel("Просмотр\nтраектории");
    label->setStyleSheet(style_no_border);
    label->setAlignment(Qt::AlignCenter);
    lay2->addWidget(label);

    show_graf_button = new QtSvgButton();
    show_graf_button->setLockalSkin(*pathToRes, "Graf");
    connect(show_graf_button,SIGNAL(clicked()),SLOT(pressButtonGraf()));
    show_graf_button->setFixedSize(50,50);
    lay2->addWidget(show_graf_button);
    verLay->addWidget(graf_area);

    verLay->addStretch(1);
    QLabel *control_area = new QLabel();
    control_area->setStyleSheet(style_gray);
    control_area->setFixedHeight(140);
    control_area->setContentsMargins(15,10,5,10);
    verLay->addWidget(control_area,1);
    QVBoxLayout *ver_lay = new QVBoxLayout();
    ver_lay->setAlignment(Qt::AlignCenter);
    ver_lay->setContentsMargins(0,0,0,0);
    ver_lay->setSpacing(10);
    control_area->setLayout(ver_lay);
    QtSvgButton *save_button = new QtSvgButton();
    save_button->setLockalSkin(*pathToRes, "BerylSave");
    connect(save_button,SIGNAL(clicked()),SLOT(pressButtonSave()));
    ver_lay->addWidget(save_button);
    QtSvgButton *load_button = new QtSvgButton();
    load_button->setLockalSkin(*pathToRes,"BerylLoad");
    connect(load_button,SIGNAL(clicked()),SLOT(pressButtonLoad()));
    ver_lay->addWidget(load_button);
}

ControlPanel::~ControlPanel()
{
    delete ui;
}

void ControlPanel::pressButton1(){
    trajectory_area_1->setStyleSheet(style_green);
    trajectory_area_2->setStyleSheet(style_gray);
    trajectory_area_3->setStyleSheet(style_gray);
    trajectory_area_4->setStyleSheet(style_gray);
    emit changeTrajectory(1);
}

void ControlPanel::pressButton2(){
    trajectory_area_1->setStyleSheet(style_gray);
    trajectory_area_2->setStyleSheet(style_green);
    trajectory_area_3->setStyleSheet(style_gray);
    trajectory_area_4->setStyleSheet(style_gray);
    emit changeTrajectory(2);
}

void ControlPanel::pressButton3(){
    trajectory_area_1->setStyleSheet(style_gray);
    trajectory_area_2->setStyleSheet(style_gray);
    trajectory_area_3->setStyleSheet(style_green);
    trajectory_area_4->setStyleSheet(style_gray);
    emit changeTrajectory(3);
}

void ControlPanel::pressButton4(){
    trajectory_area_1->setStyleSheet(style_gray);
    trajectory_area_2->setStyleSheet(style_gray);
    trajectory_area_3->setStyleSheet(style_gray);
    trajectory_area_4->setStyleSheet(style_green);
    emit changeTrajectory(4);
}

void ControlPanel::pressButtonGraf(){
    static bool mode = false;
    if (!mode) {
        show_graf_button->setLockalSkin(*pathToRes,"Constructor");
        label->setText("Режим\nконструктора");
    }
    else {
        show_graf_button->setLockalSkin(*pathToRes,"Graf");
        label->setText("Просмотр\nтраектории");
    }
    emit changeMode(mode);
    mode = !mode;
}

void ControlPanel::pressButtonSave(){
    emit saveFileAs(QFileDialog::getSaveFileName(0,"Сохранить траекторию как...", "","*.xml")+".xml");
}

void ControlPanel::pressButtonLoad(){
    emit loadFileFrom(QFileDialog::getOpenFileName(0,"Открыть файл траектории","","*.xml"));
}
