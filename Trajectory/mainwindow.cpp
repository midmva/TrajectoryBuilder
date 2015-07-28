#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

QStringList *nameSkin = NULL;
QStringList *nameArea = NULL;
QStringList *nameParameter = NULL;
    QString *pathToRes = new QString("/home/midv/Projects/TrajectoryBuilder/Trajectory/resourses/");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mode = true;
    nameSkin = new QStringList();
    nameSkin->append("Line");
    nameSkin->append("Aссel");
    nameSkin->append("ArcV");
    nameSkin->append("ArcH");
    nameSkin->append("ZmeyV");
    nameSkin->append("ZmeyH");
    nameArea = new QStringList();
    nameArea->append("Прямолинейное\nравномерное\nдвижение");
    nameArea->append("Прямолинейное\nравноускоренное\nдвижение");
    nameArea->append("Движение по дуге\nв вертикальной\nплоскости");
    nameArea->append("Движение по дуге\nв горизонтальной\nплоскости");
    nameArea->append("Маневр \"змейка\"\nв вертикальной\nплоскости");
    nameArea->append("Маневр \"змейка\"\nв горизонтальной\nплоскости");
    nameParameter = new QStringList();
    nameParameter->append("Расстояние,\n[м]");
    nameParameter->append("Ограничение\nпо длительности\nманевра,\n[с]");
    nameParameter->append("Ускорение,\n[м/с^2]");
    nameParameter->append("Скорость\nв конце маневра,\n[м/с]");
    nameParameter->append("Центробежное\nускорение,\n[м/с^2]");
    nameParameter->append("Угол поворота,\n[град]");
    nameParameter->append("Центробежное\nускорение,\n[м/с^2]");
    nameParameter->append("Угол поворота,\n[град]");
    nameParameter->append("Максимальная\nперегрузка,\n[м/с^2]");
    nameParameter->append("Смещение цели\nв вертикальной\nплоскости,\n[м]");
    nameParameter->append("Максимальная\nперегрузка,\n[м/с^2]");
    nameParameter->append("Смещение цели\nв горизонтальной\nплоскости,\n[м]");

    ui->setupUi(this);
    horLay = new QHBoxLayout(ui->centralWidget);
    horLay->setSpacing(0);
    horLay->setAlignment(Qt::AlignCenter);
    for (int i = 0; i<4; i++){
        trajectory[i] = new Trajectory();
        graf[i] = new GrafTrajectory();
    }
    horLay->addWidget(trajectory[0]);
    show_trajectory = 0;
    ControlPanel *control = new ControlPanel();
    connect(control,SIGNAL(changeTrajectory(int)),SLOT(changeTrajectory(int)));
    connect(control,SIGNAL(loadFileFrom(QString)),SLOT(loadFile(QString)));
    connect(control,SIGNAL(saveFileAs(QString)),SLOT(saveFile(QString)));
    connect(control,SIGNAL(changeMode(bool)),SLOT(changeMode(bool)));
    horLay->addWidget(control);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeTrajectory(int number){
    if (mode){
        horLay->removeWidget(trajectory[show_trajectory]);
        trajectory[show_trajectory]->hide();
        show_trajectory = number-1;
        horLay->insertWidget(0,trajectory[show_trajectory]);
        trajectory[show_trajectory]->show();
    }
    else{
        horLay->removeWidget(graf[show_trajectory]);
        graf[show_trajectory]->hide();
        show_trajectory = number-1;
        horLay->insertWidget(0,graf[show_trajectory]);
        graf[show_trajectory]->show();
    }
}

void MainWindow::changeMode(bool mode){
    this->mode = mode;
    if (this->mode){
        horLay->removeWidget(graf[show_trajectory]);
        graf[show_trajectory]->hide();
        horLay->insertWidget(0,trajectory[show_trajectory]);
        trajectory[show_trajectory]->show();
    }
    else {        
        horLay->removeWidget(trajectory[show_trajectory]);
        trajectory[show_trajectory]->hide();
        horLay->insertWidget(0,graf[show_trajectory]);
        graf[show_trajectory]->show();
    }
}

void MainWindow::loadFile(const QString name){
    qDebug()<<"load "+name;
}

void MainWindow::saveFile(const QString name){
    QList<QStringList> list;
    for (int i = 0; i<4; i++){
        list = trajectory[i]->getTrajectory();
        if (!list.isEmpty())
            qDebug()<<list;
    }
}
