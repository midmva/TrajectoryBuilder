#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    change = new Change();
    QHBoxLayout *generalLayer = new QHBoxLayout(ui->centralWidget);
    trajLayer = new QVBoxLayout();
    trajLayer->setContentsMargins(0,0,0,0);
    trajLayer->setSpacing(1);
    trajLayer->setAlignment(Qt::AlignTop);
    generalLayer->addLayout(trajLayer,3);
    QVBoxLayout *buttonLayout = new QVBoxLayout();
    generalLayer->addLayout(buttonLayout,1);
    addButton = new QtSvgButton();
    connect(addButton,SIGNAL(clicked()),SLOT(ShowChange()));
    addButton->setSkin("BerylSquare");
    addButton->setFixedSize(150,150);
    trajLayer->addWidget(addButton);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowChange(){
    trajLayer->insertWidget(trajLayer->indexOf(addButton),change);
    addButton->hide();
}
