#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    pathToRes = new QString("/home/midv/Projects/TrajectoryBuilder/Trajectory/resourses/");
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
    qDebug()<<index;
    if (index == 7){
        trajLayer->insertWidget(trajLayer->indexOf(change),addButton);
        trajLayer->removeWidget(change);
        addButton->show();
        change->hide();
    }
    else {
        Area *area = new Area(this);
        trajLayer->insertWidget(trajLayer->indexOf(change),area);
        trajLayer->removeWidget(change);
        change->hide();
        trajLayer->addWidget(addButton);
        addButton->show();
    }
}
