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
#include "explosion.h"
#include "piedramovsen.h"
#include <QKeyEvent>
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
    scene2= new QGraphicsScene(0,0,980,580);
    scene3= new QGraphicsScene(0,0,980,580);
    donalt=new Sprite();

    ui->graphicsView->setScene(scene);
    scene->addItem(donalt);
    donalt->setPos(w,z);
    velocidad=10;
    timer=new QTimer();
    timer2=new QTimer();
    objeto=new Objeto();
    timer->start(2);
    lecturaArchivo();
    for(int g=0,k=0,l=0;g!=714;g++,l+=30){
        if(g%34==0&&g!=0){
           k++;
           l=0;
        }
    if(level[g]==2){piedramov=new PiedraMov();scene->addItem(piedramov);piedramov->setPos(l+10,k*30);piedramov->setMx(l+10);piedramov->setMy(k*30);}
    if(level[g]==3){platano=new Platano();scene->addItem(platano);platano->setPos(l+10,k*30);}
    if(level[g]==4){uva=new Uva();scene->addItem(uva);uva->setPos(l+10,k*30);}
    if(level[g]==5){manzana=new Manzana();scene->addItem(manzana);manzana->setPos(l+10,k*30);}
    if(level[g]==6){piedrasen=new PiedraMovSen();scene->addItem(piedrasen);piedrasen->setPos(l+10,k*30);;piedrasen->setMx(l+10);piedrasen->setMy(k*30);}
    if(level[g]==7){piedrapend=new PiedraMovPend();scene->addItem(piedrapend);piedrapend->setPos(l+10,k*30);;piedrapend->setMx(l+10);piedrapend->setMy(k*30);}}
    for(int g=0,k=0,l=0;g!=714;g++,l+=30){
        if(g%34==0&&g!=0){
           k++;
           l=0;
        }
    if(level[g]==1){piedra=new Piedra();scene->addItem(piedra);piedra->setPos(l+10,k*30);}}
    score=new Score();
    rect=new Rect();
    scene->addItem(rect);
    rect->setPos(1005,0);
    scene->addItem(score);
    score->setPos(0,-25);
    img=new IMG();
    ni=new Nivel();
    scene->addItem(img);
    img->setPos(1000,700);
    scene->addItem(ni);
    ni->setPos(280,200);
    timer->start(0);

    connect(timer,&QTimer::timeout,this,&Widget::Scene);
    connect(timer,&QTimer::timeout,this,&Widget::Scene2);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *e)
{        ah=e->key();
         qDebug()<<ah;
         if(e->key()==Qt::Key_W&&move==true){
             if(z>90){
                 z-=velocidad;
             donalt->setPos(w,z);
             }
             donalt->setFilas(2);
         }else if(e->key()==Qt::Key_S&&move==true){

             if(z<600){
                 z+=velocidad;
             donalt->setPos(w,z);
             }
             donalt->setFilas(3);
         }else if(e->key()==Qt::Key_D&&move==true){
             if(w<=980){
                 w+=velocidad;
             donalt->setPos(w,z);}
             donalt->setFilas(1);
         }else if(e->key()==Qt::Key_A&&move==true){
             if(w>80){w-=velocidad;donalt->setPos(w,z);
             }donalt->setFilas(0);
         }else if(e->key()==Qt::Key_Space){
            Objeto *mi=new Objeto();
            mi->setPos(100,100);
            scene->addItem(mi);

         }
         e->accept();

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
void Widget::lecturaArchivo2()
{
    FILE * archivo;
      long medida;
      char texto[734];
    archivo = fopen ("Niveles2.txt", "r");
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
void Widget::lecturaArchivo3()
{
    FILE * archivo;
      long medida;
      char texto[734];
    archivo = fopen ("Niveles3.txt", "r");
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
void Widget::Scene()
{
    if (score->getScore()==8){
        scenea=2;
        img=new IMG();
        ni=new Nivel();
         score->increase();
         ui->graphicsView->setScene(scene2);

         donalt=new Sprite();

         scene2->addItem(donalt);

         w=100;
         z=100;
         donalt->setPos(w,z);
         lecturaArchivo2();
         for(int g=0,k=0,l=0;g!=714;g++,l+=30){
             if(g%34==0&&g!=0){
                k++;
                l=0;
             }
         if(level[g]==2){piedramov=new PiedraMov();scene2->addItem(piedramov);piedramov->setPos(l+10,k*30);piedramov->setMx(l+10);piedramov->setMy(k*30);}
         if(level[g]==3){platano=new Platano();scene2->addItem(platano);platano->setPos(l+10,k*30);}
         if(level[g]==4){uva=new Uva();scene2->addItem(uva);uva->setPos(l+10,k*30);}
         if(level[g]==5){manzana=new Manzana();scene2->addItem(manzana);manzana->setPos(l+10,k*30);}
         if(level[g]==6){piedrasen=new PiedraMovSen();scene2->addItem(piedrasen);piedrasen->setPos(l+10,k*30);;piedrasen->setMx(l+10);piedrasen->setMy(k*30);}
         if(level[g]==7){piedrapend=new PiedraMovPend();scene2->addItem(piedrapend);piedrapend->setPos(l+10,k*30);;piedrapend->setMx(l+10);piedrapend->setMy(k*30);}}
         for(int g=0,k=0,l=0;g!=714;g++,l+=30){
             if(g%34==0&&g!=0){
                k++;
                l=0;
             }
         if(level[g]==1){piedra=new Piedra();scene2->addItem(piedra);piedra->setPos(l+10,k*30);}}
         rect=new Rect();
         scene2->addItem(rect);
         rect->setPos(1005,0);
         scene2->addItem(score);
         scene2->addItem(img);
         img->setPos(1000,700);
         scene2->addItem(ni);
         ni->increase(2);
         ni->setPos(280,200);
    }

}
void Widget::Scene2()
{
    if (score->getScore()==16){
        scenea=3;
        score->increase();
        ui->graphicsView->setScene(scene3);
        img=new IMG();
        ni=new Nivel();
        donalt=new Sprite();
        scene3->addItem(donalt);
        w=100;
        z=100;
        donalt->setPos(w,z);
        lecturaArchivo3();
        for(int g=0,k=0,l=0;g!=714;g++,l+=30){
            if(g%34==0&&g!=0){
               k++;
               l=0;
            }
        if(level[g]==2){piedramov=new PiedraMov();scene3->addItem(piedramov);piedramov->setPos(l+10,k*30);piedramov->setMx(l+10);piedramov->setMy(k*30);}
        if(level[g]==3){platano=new Platano();scene3->addItem(platano);platano->setPos(l+10,k*30);}
        if(level[g]==4){uva=new Uva();scene3->addItem(uva);uva->setPos(l+10,k*30);}
        if(level[g]==5){manzana=new Manzana();scene3->addItem(manzana);manzana->setPos(l+10,k*30);}
        if(level[g]==6){piedrasen=new PiedraMovSen();scene3->addItem(piedrasen);piedrasen->setPos(l+10,k*30);;piedrasen->setMx(l+10);piedrasen->setMy(k*30);}
        if(level[g]==7){piedrapend=new PiedraMovPend();scene3->addItem(piedrapend);piedrapend->setPos(l+10,k*30);;piedrapend->setMx(l+10);piedrapend->setMy(k*30);}}
        for(int g=0,k=0,l=0;g!=714;g++,l+=30){
            if(g%34==0&&g!=0){
               k++;
               l=0;
            }
        if(level[g]==1){piedra=new Piedra();scene3->addItem(piedra);piedra->setPos(l+10,k*30);}}
        rect=new Rect();
        scene3->addItem(rect);
        rect->setPos(1005,0);
        scene3->addItem(score);
        scene3->addItem(img);
        img->setPos(1000,700);
        scene3->addItem(ni);
        ni->increase(3);
        ni->setPos(280,200);
    }

}
void Widget::Explos(){
    exp=new Explosion();
    exp->setPos(w,z);
    if(scenea==1){
    scene->addItem(exp);}
    if(scenea==2){
    scene2->addItem(exp);}
    if(scenea==3){
    scene3->addItem(exp);}

    score->decrease();
}





void Widget::on_pushButton_clicked()
{

}

