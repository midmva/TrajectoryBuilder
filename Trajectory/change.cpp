#include "change.h"
#include "ui_change.h"
#include <QHBoxLayout>
#include "QtSvgButton"

Change::Change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);
    QHBoxLayout *lay = new QHBoxLayout(this);
    lay->setAlignment(Qt::AlignLeft);
    lay->setSpacing(0);
    lay->setContentsMargins(5,0,0,0);
    QtSvgButton *button1 = new QtSvgButton();
    button1->setSkin("BerylSquare");
    button1->setFixedSize(110,110);
    lay->addWidget(button1);
    QtSvgButton *button2 = new QtSvgButton();
    button2->setSkin("BerylSquare");
    button2->setFixedSize(110,110);
    lay->addWidget(button2);
    QtSvgButton *button3 = new QtSvgButton();
    button3->setSkin("BerylSquare");
    button3->setFixedSize(110,110);
    lay->addWidget(button3);
    QtSvgButton *button4 = new QtSvgButton();
    button4->setSkin("BerylSquare");
    button4->setFixedSize(110,110);
    lay->addWidget(button4);
    QtSvgButton *button5 = new QtSvgButton();
    button5->setSkin("BerylSquare");
    button5->setFixedSize(110,110);
    lay->addWidget(button5);
    QtSvgButton *button6 = new QtSvgButton();
    button6->setSkin("BerylSquare");
    button6->setFixedSize(110,110);
    lay->addWidget(button6);
}

Change::~Change()
{
    delete ui;
}
