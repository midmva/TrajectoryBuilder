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
    list = new QList<Trajectory *>();
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
    Trajectory * trajectory = new Trajectory();
    list->append(trajectory);
    horLay->addWidget(trajectory);
    ControlPanel *control = new ControlPanel();
    horLay->addWidget(control);
}

MainWindow::~MainWindow()
{
    delete ui;
}

