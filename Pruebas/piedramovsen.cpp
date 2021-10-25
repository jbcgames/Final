#include "piedramovsen.h"
#include "piedramov.h"
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
#include "piedramovpend.h"
PiedraMovSen::PiedraMovSen(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    QTimer *timer2=new QTimer();
    pixmap = new QPixmap(":/pincho2.png");
    ancho=30;
    alto=30;
    timer->start(15);
    timer2->start(50);
    connect(timer, &QTimer::timeout,this,&PiedraMovSen::Mov);
    connect(timer2, &QTimer::timeout,this,&PiedraMovSen::Actualizacion);
}

QRectF PiedraMovSen::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void PiedraMovSen::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}
void PiedraMovSen::setMx(int mx)
{
    this->mx=mx;
    inix=mx;
}
void PiedraMovSen::setMy(int my)
{
    this->my=my;
    iniy=my;
}

void PiedraMovSen::Mov(){
    QList<QGraphicsItem *> colliding = collidingItems();
  for(int i=0,n=colliding.size();i<n;++i){
       if(typeid(*(colliding[i]))==typeid(Piedra)&&m==true){
            m=false;
            break;
        }
        else if(typeid(*(colliding[i]))==typeid(Piedra)&&m==false){
            m=true;
            break;
       }
       if(typeid(*(colliding[i]))==typeid(PiedraMov)&&m==true){
            m=false;
            break;
        }
        else if(typeid(*(colliding[i]))==typeid(PiedraMov)&&m==false){
            m=true;
            break;
       }
       if(typeid(*(colliding[i]))==typeid(PiedraMovPend)&&m==true){
            m=false;
            break;
        }
        else if(typeid(*(colliding[i]))==typeid(PiedraMovPend)&&m==false){
            m=true;
            break;
       }
       if(typeid(*(colliding[i]))==typeid(PiedraMovSen)&&m==true){
            m=false;
            break;
        }
        else if(typeid(*(colliding[i]))==typeid(PiedraMovSen)&&m==false){
            m=true;
            break;
       }

    }
    if(m==true){
        mx+=n;
    }

    if(m==false){
        mx-=n;
    }
    s+=5;
    if(s>=360){
        s=1;
    }

  my=30*sin((float)s/180*3.1415);


    this->setPos(mx,my+iniy);
}
void PiedraMovSen::DeteccionParedes(){

}
void PiedraMovSen::Actualizacion(){
    columnas +=30;
    if(columnas>=60){
        columnas=0;
    }


    this->update(-ancho,-alto,ancho,alto);
}


