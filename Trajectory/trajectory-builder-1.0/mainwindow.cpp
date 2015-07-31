#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

QStringList *nameSkin = NULL;
QStringList *nameArea = NULL;
QStringList *nameParameter = NULL;
    QString *pathToRes = new QString("/home/midv/Projects/TrajectoryBuilder/Trajectory/resourses/");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mode = true;
    nameSkin = new QStringList();
    nameSkin->append("Line");
    nameSkin->append("Aссel");
    nameSkin->append("ArcV");
    nameSkin->append("ArcH");
    nameSkin->append("ZmeyV");
    nameSkin->append("ZmeyH");
    nameArea = new QStringList();
    nameArea->append("Прямолинейное\nравномерное\nдвижение");
    nameArea->append("Прямолинейное\nравноускоренное\nдвижение");
    nameArea->append("Движение по дуге\nв вертикальной\nплоскости");
    nameArea->append("Движение по дуге\nв горизонтальной\nплоскости");
    nameArea->append("Маневр \"змейка\"\nв вертикальной\nплоскости");
    nameArea->append("Маневр \"змейка\"\nв горизонтальной\nплоскости");
    nameParameter = new QStringList();
    nameParameter->append("Расстояние,\n[м]");
    nameParameter->append("Ограничение\nпо длительности\nманевра,\n[с]");
    nameParameter->append("Ускорение,\n[м/с^2]");
    nameParameter->append("Скорость\nв конце маневра,\n[м/с]");
    nameParameter->append("Центробежное\nускорение,\n[м/с^2]");
    nameParameter->append("Угол поворота,\n[град]");
    nameParameter->append("Центробежное\nускорение,\n[м/с^2]");
    nameParameter->append("Угол поворота,\n[град]");
    nameParameter->append("Максимальная\nперегрузка,\n[м/с^2]");
    nameParameter->append("Смещение цели\nв вертикальной\nплоскости,\n[м]");
    nameParameter->append("Максимальная\nперегрузка,\n[м/с^2]");
    nameParameter->append("Смещение цели\nв горизонтальной\nплоскости,\n[м]");

    ui->setupUi(this);
    horLay = new QHBoxLayout(ui->centralWidget);
    horLay->setSpacing(0);
    horLay->setAlignment(Qt::AlignCenter);
    for (int i = 0; i<4; i++){
        trajectory[i] = new Trajectory();
        graf[i] = new GrafTrajectory();
    }
    horLay->addWidget(trajectory[0]);
    show_trajectory = 0;
    ControlPanel *control = new ControlPanel();
    connect(control,SIGNAL(changeTrajectory(int)),SLOT(changeTrajectory(int)));
    connect(control,SIGNAL(loadFileFrom(QString)),SLOT(loadFile(QString)));
    connect(control,SIGNAL(saveFileAs(QString)),SLOT(saveFile(QString)));
    connect(control,SIGNAL(changeMode(bool)),SLOT(changeMode(bool)));
    horLay->addWidget(control);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeTrajectory(int number){
    if (mode){
        horLay->removeWidget(trajectory[show_trajectory]);
        trajectory[show_trajectory]->hide();
        show_trajectory = number-1;
        horLay->insertWidget(0,trajectory[show_trajectory]);
        trajectory[show_trajectory]->show();
    }
    else{
        horLay->removeWidget(graf[show_trajectory]);
        graf[show_trajectory]->hide();
        show_trajectory = number-1;
        horLay->insertWidget(0,graf[show_trajectory]);
        graf[show_trajectory]->show();
    }
}

void MainWindow::changeMode(bool mode){
    this->mode = mode;
    if (this->mode){
        horLay->removeWidget(graf[show_trajectory]);
        graf[show_trajectory]->hide();
        horLay->insertWidget(0,trajectory[show_trajectory]);
        trajectory[show_trajectory]->show();
    }
    else {        
        horLay->removeWidget(trajectory[show_trajectory]);
        trajectory[show_trajectory]->hide();
        horLay->insertWidget(0,graf[show_trajectory]);
        graf[show_trajectory]->show();
    }
}

void MainWindow::loadFile(const QString name){
    QFile file(name);
    QDomDocument doc("file");
    QStringList string_list[4];
    QList<QStringList> list;
    if (file.open(QIODevice::ReadOnly)){
        if (doc.setContent(&file)){
            QString file_name = name;
            file_name.remove(0,file_name.lastIndexOf("/")+1);
            setWindowTitle(windowTitle()+" "+file_name);
            if (doc.documentElement().nodeName()!="file")return;
            QDomNode node = doc.documentElement().firstChild();
            while (!node.isNull()){                  //пока все не разберем
                if (node.isElement()){               //проверка на вшивость
                    QDomElement element = node.toElement();
                    if (element.nodeName()!="traectory")return;
                    QDomNode node_child = node.firstChild();
                    list.clear();
                    while (!node_child.isNull()){
                        if (node_child.isElement()){
                            QDomElement element_child = node_child.toElement();
                            if (element_child.nodeName()!="area")return;
                            int index = element_child.attribute("number").toInt()-1;
                            string_list[index].clear();
                            string_list[index].append(element_child.attribute("number"));
                            string_list[index].append(element_child.attribute("name"));
                            string_list[index].append(element_child.attribute("parameter_1_value"));
                            string_list[index].append(element_child.attribute("parameter_2_value"));
                            list.append(string_list[index]);
                        }
                        node_child = node_child.nextSibling();
                    }
                    if (!list.isEmpty())
                        trajectory[element.attribute("number").toInt()-1]->setTrajectory(list);
                }
                node = node.nextSibling();
            }
        }
        else {
            QMessageBox *error = new QMessageBox(QMessageBox::Critical,
                                                 "Error","Cannot to read this file",
                                                 QMessageBox::Ok);
            error->show();
        }
        file.close();
    }
    else{
        QMessageBox *error = new QMessageBox(QMessageBox::Critical,
                                             "Error","Cannot to open this file",
                                             QMessageBox::Ok);
        error->show();
    }
}

void MainWindow::parceXml(QDomNode node){
    while (!node.isNull()){                  //пока все не разберем
        if (node.isElement()){               //проверка на вшивость
            QDomElement element = node.toElement();
            qDebug()<<element.nodeName();

        }
        node = node.nextSibling();
    }
}

void MainWindow::saveFile(const QString name){
    QList<QStringList> list;
    QDomDocument doc("file");
    QDomElement element = doc.createElement("file");
    QDomAttr attr1 = doc.createAttribute("create_date");
    attr1.setValue(QDate::currentDate().toString("dd.MM.yyyy"));
    element.setAttributeNode(attr1);
    QDomAttr attr2 = doc.createAttribute("create_time");
    attr2.setValue(QTime::currentTime().toString("hh:mm:ss"));
    element.setAttributeNode(attr2);
    doc.appendChild(element);
    for (int i = 0; i<4; i++){
        list = trajectory[i]->getTrajectory();
        if (!list.isEmpty()){
            QDomElement trajectory_element = doc.createElement("traectory");
            QDomAttr trajectory_attr = doc.createAttribute("number");
            trajectory_attr.setValue(QString::number(i+1));
            trajectory_element.setAttributeNode(trajectory_attr);
            for (int j = 0; j<list.count();j++){
                QDomElement area_element = doc.createElement("area");
                QDomAttr area_attr0 = doc.createAttribute("number");
                area_attr0.setValue(list.at(j).at(0));//номер
                area_element.setAttributeNode(area_attr0);
                QDomAttr area_attr1 = doc.createAttribute("name");
                area_attr1.setValue(list.at(j).at(1));//имя
                area_element.setAttributeNode(area_attr1);
                QDomAttr area_attr2 = doc.createAttribute("parameter_1_name");//имя 1 параметра
                area_attr2.setValue(list.at(j).at(2));//значение параметра
                area_element.setAttributeNode(area_attr2);
                QDomAttr area_attr3 = doc.createAttribute("parameter_1_value");//значение 2 параметра
                area_attr3.setValue(list.at(j).at(3));//значение параметра
                area_element.setAttributeNode(area_attr3);
                QDomAttr area_attr4 = doc.createAttribute("parameter_2_name");//имя 2 параметра
                area_attr4.setValue(list.at(j).at(4));//значение параметра
                area_element.setAttributeNode(area_attr4);
                QDomAttr area_attr5 = doc.createAttribute("parameter_2_value");//значение 2 параметра
                area_attr5.setValue(list.at(j).at(5));//значение параметра
                area_element.setAttributeNode(area_attr5);
                trajectory_element.appendChild(area_element);
            }
            element.appendChild(trajectory_element);
        }
    }
    if (!element.hasChildNodes()){
        QMessageBox *error = new QMessageBox(QMessageBox::Critical,
                                             "Error","Не найдено на одной траектории",
                                             QMessageBox::Ok);
        error->show();
        return;
    }
    QFile file(name);
    if (file.open(QIODevice::WriteOnly)){
        QTextStream(&file)<<doc.toString();
        file.close();
    }
}
