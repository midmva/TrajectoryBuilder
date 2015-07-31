/********************************************************************************
** Form generated from reading UI file 'change.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_H
#define UI_CHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Change
{
public:

    void setupUi(QWidget *Change)
    {
        if (Change->objectName().isEmpty())
            Change->setObjectName(QStringLiteral("Change"));
        Change->resize(800, 153);

        retranslateUi(Change);

        QMetaObject::connectSlotsByName(Change);
    } // setupUi

    void retranslateUi(QWidget *Change)
    {
        Change->setWindowTitle(QApplication::translate("Change", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Change: public Ui_Change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_H
