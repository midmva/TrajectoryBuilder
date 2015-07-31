/********************************************************************************
** Form generated from reading UI file 'graftrajectory.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFTRAJECTORY_H
#define UI_GRAFTRAJECTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_GrafTrajectory
{
public:
    QwtPlot *qwtPlot_1;
    QwtPlot *qwtPlot_2;
    QwtPlot *qwtPlot_3;
    QwtPlot *qwtPlot_4;

    void setupUi(QWidget *GrafTrajectory)
    {
        if (GrafTrajectory->objectName().isEmpty())
            GrafTrajectory->setObjectName(QStringLiteral("GrafTrajectory"));
        GrafTrajectory->resize(953, 705);
        qwtPlot_1 = new QwtPlot(GrafTrajectory);
        qwtPlot_1->setObjectName(QStringLiteral("qwtPlot_1"));
        qwtPlot_1->setGeometry(QRect(30, 20, 400, 200));
        qwtPlot_2 = new QwtPlot(GrafTrajectory);
        qwtPlot_2->setObjectName(QStringLiteral("qwtPlot_2"));
        qwtPlot_2->setGeometry(QRect(490, 20, 400, 200));
        qwtPlot_3 = new QwtPlot(GrafTrajectory);
        qwtPlot_3->setObjectName(QStringLiteral("qwtPlot_3"));
        qwtPlot_3->setGeometry(QRect(30, 350, 400, 200));
        qwtPlot_4 = new QwtPlot(GrafTrajectory);
        qwtPlot_4->setObjectName(QStringLiteral("qwtPlot_4"));
        qwtPlot_4->setGeometry(QRect(490, 350, 400, 200));

        retranslateUi(GrafTrajectory);

        QMetaObject::connectSlotsByName(GrafTrajectory);
    } // setupUi

    void retranslateUi(QWidget *GrafTrajectory)
    {
        GrafTrajectory->setWindowTitle(QApplication::translate("GrafTrajectory", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class GrafTrajectory: public Ui_GrafTrajectory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFTRAJECTORY_H
