#include "trajectory.h"
#include "ui_trajectory.h"
#include "mainwindow.h"

Trajectory::Trajectory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Trajectory)
{
    ui->setupUi(this);
    list = new QList<Area *>();

    change = new Change();
    connect(change,SIGNAL(pressButton(int)),SLOT(ChangeManeur(int)));
    QHBoxLayout *generalLayer = new QHBoxLayout(this);
    trajLayer = new QVBoxLayout();
    trajLayer->setContentsMargins(0,0,0,0);
    trajLayer->setSpacing(10);
    trajLayer->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    generalLayer->addLayout(trajLayer,3);
    QVBoxLayout *buttonLayout = new QVBoxLayout();
    generalLayer->addLayout(buttonLayout,1);
    addButton = new QtSvgButton();
    connect(addButton,SIGNAL(clicked()),SLOT(ShowChange()));
    addButton->setLockalSkin(*pathToRes,"Add");
    addButton->setFixedSize(150,150);
    trajLayer->addWidget(addButton);
}

Trajectory::~Trajectory()
{
    delete ui;
}

void Trajectory::ShowChange(){
    trajLayer->removeWidget(addButton);
    trajLayer->addWidget(change);
    addButton->hide();
    change->show();
}

void Trajectory::ChangeManeur(int index){
    if (index == 7){
        trajLayer->removeWidget(change);
        trajLayer->addWidget(addButton);
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

void Trajectory::Renumber(Area *ptr){
    trajLayer->removeWidget(ptr);
    if (list->count()==4){
        trajLayer->addWidget(addButton);
        addButton->show();
    }
    list->removeOne(ptr);
    ptr->deleteLater();
    for (int i = 0; i<list->count();i++){
        list->at(i)->SetNumber(i+1);
    }
}

QList<QStringList>  Trajectory::getTrajectory(){
    QList<QStringList> list;
    for (int i = 0; i<this->list->count(); i++){
        list.append(this->list->at(i)->getArea());
    }
    return list;
}

void Trajectory::setTrajectory(const QList<QStringList> list){
    trajLayer->removeWidget(addButton);
    addButton->hide();
    for (int i = 0; i<list.count();i++){
        QString temp;
        int index;
        for (index = 0; index<nameArea->count();index++){//ищем нужный индекс участка траектории
            temp = nameArea->at(index);
            temp.replace("\n"," ");
            if (temp == list.at(i).at(1)){//ищем совпадение по имени участка траектории
                break;
            }
        }
        Area *area = new Area();
        this->list->append(area);
        connect(area,SIGNAL(Renumber(Area*)),this,SLOT(Renumber(Area*)));
        area->InitArea(list.at(i).at(0).toInt(),nameSkin->at(index),nameArea->at(index),nameParameter->at(index*2),0,nameParameter->at(index*2+1),0);

        trajLayer->addWidget(area);

        this->list->last()->setParameter(list.at(i).at(2).toInt(),list.at(i).at(3).toInt());
    }
    if (this->list->count()<4){
        trajLayer->addWidget(addButton);
        addButton->show();
    }
}
