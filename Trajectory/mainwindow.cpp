#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

QStringList *nameSkin = NULL;
QStringList *nameArea = NULL;
QStringList *nameParameter = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    list = new QList<Area *>();
    pathToRes = new QString("/home/midv/Projects/TrajectoryBuilder/Trajectory/resourses/");
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
    change = new Change();
    connect(change,SIGNAL(pressButton(int)),SLOT(ChangeManeur(int)));
    QHBoxLayout *generalLayer = new QHBoxLayout(ui->centralWidget);
    trajLayer = new QVBoxLayout();
    trajLayer->setContentsMargins(0,0,0,0);
    trajLayer->setSpacing(10);
    trajLayer->setAlignment(Qt::AlignTop);
    generalLayer->addLayout(trajLayer,3);
    QVBoxLayout *buttonLayout = new QVBoxLayout();
    generalLayer->addLayout(buttonLayout,1);
    addButton = new QtSvgButton();
    connect(addButton,SIGNAL(clicked()),SLOT(ShowChange()));
    addButton->setLockalSkin(*pathToRes,"Add");
    addButton->setFixedSize(150,150);
    trajLayer->addWidget(addButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowChange(){
    trajLayer->insertWidget(trajLayer->indexOf(addButton),change);
    trajLayer->removeWidget(addButton);
    addButton->hide();
    change->show();
}

void MainWindow::ChangeManeur(int index){
    if (index == 7){
        trajLayer->insertWidget(trajLayer->indexOf(change),addButton);
        trajLayer->removeWidget(change);
        addButton->show();
        change->hide();
    }
    else {
        Area *area = new Area();
        list->append(area);
        connect(area,SIGNAL(Renumber(Area*)),this,SLOT(Renumber(Area*)));
        area->InitArea(trajLayer->indexOf(change)+1,nameSkin->at(index-1),nameArea->at(index-1),nameParameter->at((index-1)*2),0,nameParameter->at((index-1)*2+1),0);
        trajLayer->insertWidget(trajLayer->indexOf(change),area);
        trajLayer->removeWidget(change);
        change->hide();
        if (list->count()<4){
            trajLayer->addWidget(addButton);
            addButton->show();
        }
    }
}

void MainWindow::Renumber(Area *ptr){
    if (list->count()==4){
        trajLayer->addWidget(addButton);
        addButton->show();
    }
    list->removeOne(ptr);
    trajLayer->removeWidget(ptr);
    ptr->deleteLater();
    for (int i = 0; i<list->count();i++){
        list->at(i)->SetNumber(i+1);
    }
}
