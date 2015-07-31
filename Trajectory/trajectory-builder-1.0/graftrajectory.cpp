#include "graftrajectory.h"
#include "ui_graftrajectory.h"


GrafTrajectory::GrafTrajectory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GrafTrajectory)
{
    ui->setupUi(this);
    QGridLayout *grid = new QGridLayout();
    setLayout(grid);
    ui->qwtPlot_1->plotLayout()->setAlignCanvasToScales(true);
    ui->qwtPlot_2->plotLayout()->setAlignCanvasToScales(true);
    ui->qwtPlot_3->plotLayout()->setAlignCanvasToScales(true);
    ui->qwtPlot_4->plotLayout()->setAlignCanvasToScales(true);
    QwtPlotGrid *plot_grid_1 = new QwtPlotGrid();
    initPlotGrid(plot_grid_1);
    plot_grid_1->attach( ui->qwtPlot_1 );
    QwtPlotGrid *plot_grid_2 = new QwtPlotGrid();
    initPlotGrid(plot_grid_2);
    plot_grid_2->attach( ui->qwtPlot_2 );
    QwtPlotGrid *plot_grid_3 = new QwtPlotGrid();
    initPlotGrid(plot_grid_3);
    plot_grid_3->attach( ui->qwtPlot_3 );
    QwtPlotGrid *plot_grid_4 = new QwtPlotGrid();
    initPlotGrid(plot_grid_4);
    plot_grid_4->attach( ui->qwtPlot_4 );
    grid->addWidget(ui->qwtPlot_1,0,0,1,1);
    grid->addWidget(ui->qwtPlot_2,0,1,1,1);
    grid->addWidget(ui->qwtPlot_3,1,0,1,1);
    grid->addWidget(ui->qwtPlot_4,1,1,1,1);
}

GrafTrajectory::~GrafTrajectory()
{
    delete ui;
}

void GrafTrajectory::initPlotGrid(QwtPlotGrid *grid){
    grid->setMajorPen(QPen(Qt::lightGray,0,Qt::DotLine)); // черный для основных делений
    grid->setMinorPen(QPen(Qt::darkGray,0,Qt::DotLine));  // серый для вспомогательных
    grid->enableX( true );
    grid->enableXMin( true );
    grid->enableY( true );
    grid->enableYMin( true );
}
