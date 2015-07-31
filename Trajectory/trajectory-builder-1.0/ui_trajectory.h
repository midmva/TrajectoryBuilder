/********************************************************************************
** Form generated from reading UI file 'trajectory.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAJECTORY_H
#define UI_TRAJECTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Trajectory
{
public:

    void setupUi(QWidget *Trajectory)
    {
        if (Trajectory->objectName().isEmpty())
            Trajectory->setObjectName(QStringLiteral("Trajectory"));
        Trajectory->resize(800, 500);

        retranslateUi(Trajectory);

        QMetaObject::connectSlotsByName(Trajectory);
    } // setupUi

    void retranslateUi(QWidget *Trajectory)
    {
        Trajectory->setWindowTitle(QApplication::translate("Trajectory", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Trajectory: public Ui_Trajectory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAJECTORY_H
