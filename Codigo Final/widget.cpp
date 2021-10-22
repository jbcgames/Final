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
#include <iostream>
#include <QKeyEvent>
#include "event.h"
#include "sprite.h"
#include "corazones.h"
#include "platano.h"
#include "piedra.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;
#endif

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap *mip=new QPixmap(":/Fondo.png");

     ui->graphicsView->setBackgroundBrush(*mip);
    scene= new QGraphicsScene(0,0,980,580);
    ui->graphicsView->setScene(scene);
    donalt=new Sprite();
    scene->addItem(donalt);
    donalt->setPos(w,z);
    timer=new QTimer();
    timer->start(50);
    objeto=new Objeto();
    platano=new Platano();
    scene->addItem(platano);
    lecturaArchivo();
    for(int g=0,k=0,l=0;g!=714;g++,l+=30){
        if(g%34==0&&g!=0){
           k++;
           l=0;
        }
    if(level[g]==1){piedra=new Piedra();scene->addItem(piedra);piedra->setPos(l,k*30);}
    if(level[g]==2){uva=new Uva();scene->addItem(uva);uva->setPos(l,k*30);}
    if(level[g]==3){platano=new Platano();scene->addItem(platano);platano->setPos(l,k*30);}}
    score=new Score();
    scene->addItem(score);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *e)
{        qDebug()<<e->key();
         if(e->key()==Qt::Key_W){
             if(z>90){
                 z-=10;
             donalt->setPos(w,z);
             }
             donalt->setFilas(2);
         }else if(e->key()==Qt::Key_S){

             if(z<600){
                 z+=10;
             donalt->setPos(w,z);
             }
             donalt->setFilas(3);
         }else if(e->key()==Qt::Key_D){
             if(w<=980){
                 w+=10;
             donalt->setPos(w,z);}
             donalt->setFilas(1);
         }else if(e->key()==Qt::Key_A){
             if(w>80){w-=10;donalt->setPos(w,z);
             }donalt->setFilas(0);
         }else if(e->key()==Qt::Key_Space){
            Objeto *mi=new Objeto();
            mi->setPos(100,100);
            scene->addItem(mi);

         }

}

void Widget::lecturaArchivo()
{
    FILE * archivo;
      long medida;
      char texto[734];
    archivo = fopen ("Niveles.txt", "r");
    fseek (archivo , 0 , SEEK_END);
    medida = ftell (archivo);
    rewind (archivo);
    fread(texto, medida+1, 1, archivo);
    fclose(archivo);
    for(int h=0,g=0;h!=734;h++,g++){
        if(texto[h]!=10){level[g]=texto[h]-48;}else{
            h++;
            level[g]=texto[h]-48;
        }
    }
}

void Widget::movimiento()
{

}




