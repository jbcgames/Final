#include "piedramovpend.h"
#include "math.h"
#include "sprite.h"
#include <QKeyEvent>
#include <QDebug>
#include <QList>
#include "score.h"
#include "piedra.h"
#include <QGraphicsScene>
#include "time.h"
#include <unistd.h>
#include <QGraphicsScene>

PiedraMovPend::PiedraMovPend(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    QTimer *timer2=new QTimer();
    QTimer *timer3=new QTimer();
    pixmap = new QPixmap(":/pinchoneg.png");
    ancho=30;
    alto=30;
    timer->start(10);
    timer2->start(50);
    timer3->start(0);
    connect(timer, &QTimer::timeout,this,&PiedraMovPend::Mov);
    connect(timer2, &QTimer::timeout,this,&PiedraMovPend::Actualizacion);
    connect(timer3, &QTimer::timeout,this,&PiedraMovPend::Detect);
}

QRectF PiedraMovPend::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void PiedraMovPend::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}
void PiedraMovPend::setMx(int mx)
{
    this->mx=mx;
    inix=mx;
}
void PiedraMovPend::setMy(int my)
{
    this->my=my;
    iniy=my;
}

void PiedraMovPend::Mov(){

    mx=inix+90*cos(s*3.1415/180);
    my=iniy+90*sin(s*3.1415/180);
    if(m==true){
        s+=1;
    }
    if(m==false){
        s-=1;
    }
    this->setPos(mx,my);
}
void PiedraMovPend::Actualizacion(){
    columnas +=30;
    if(columnas>=60){
        columnas=0;
    }

    this->update(-ancho,-alto,ancho,alto);
}

void PiedraMovPend::Detect()
{

   if(s>=160){
       m=false;
    }
   if(s<20){
       m=true;
   }

}

