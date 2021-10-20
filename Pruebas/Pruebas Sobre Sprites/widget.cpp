#include "widget.h"
#include "ui_widget.h"
#include "qapplication.h"
#include <QWidget>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QtGui>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#include <QGraphicsScene>

#endif

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QRect Desktop(0,0,1366,768);
    x=Desktop.x();
    y=Desktop.y();
    ancho= Desktop.width()-100;
    alto= Desktop.height()-100;
    scene= new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(scene);
    donalt=new Sprite();
    scene->addItem(donalt);
    donalt->setPos(150,190);
}

Widget::~Widget()
{
    delete ui;
}




