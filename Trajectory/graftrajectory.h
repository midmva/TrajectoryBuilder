#ifndef GRAFTRAJECTORY_H
#define GRAFTRAJECTORY_H

#include <QWidget>
#include <QGridLayout>
#include <qwt_plot_grid.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_directpainter.h>
#include <qwt_curve_fitter.h>
#include <qwt_painter.h>

namespace Ui {
class GrafTrajectory;
}

class GrafTrajectory : public QWidget
{
    Q_OBJECT

public:
    explicit GrafTrajectory(QWidget *parent = 0);
    ~GrafTrajectory();

private:
    Ui::GrafTrajectory *ui;
    void initPlotGrid(QwtPlotGrid * grid);
};

#endif // GRAFTRAJECTORY_H
