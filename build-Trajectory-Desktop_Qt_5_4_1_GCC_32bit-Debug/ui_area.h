/********************************************************************************
** Form generated from reading UI file 'area.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AREA_H
#define UI_AREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Area
{
public:

    void setupUi(QWidget *Area)
    {
        if (Area->objectName().isEmpty())
            Area->setObjectName(QStringLiteral("Area"));
        Area->resize(800, 153);

        retranslateUi(Area);

        QMetaObject::connectSlotsByName(Area);
    } // setupUi

    void retranslateUi(QWidget *Area)
    {
        Area->setWindowTitle(QApplication::translate("Area", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Area: public Ui_Area {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AREA_H
