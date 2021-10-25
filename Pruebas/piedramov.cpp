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
PiedraMov::PiedraMov(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    QTimer *timer2=new QTimer();
    pixmap = new QPixmap(":/pincho.png");
    ancho=30;
    alto=30;
    timer->start(10);
    timer2->start(50);
    connect(timer, &QTimer::timeout,this,&PiedraMov::Mov);
    connect(timer2, &QTimer::timeout,this,&PiedraMov::Actualizacion);
}

QRectF PiedraMov::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void PiedraMov::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}
void PiedraMov::setMx(int mx)
{
    this->mx=mx;
    inix=mx;
}
void PiedraMov::setMy(int my)
{
    this->my=my;
    iniy=my;
}

void PiedraMov::Mov(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
  /*for(int i=0,n=colliding_items.size();i<n;++i){
       if(typeid(*(colliding_items[i]))==typeid(Piedra)&&m==true){
            m=false;
            mx-=10;
        }
        else if(typeid(*(colliding_items[i]))==typeid(Piedra)&&m==false){
            m=true;
            mx+=10;
        }

    }
*/
    s++;
    mx=inix+30*cos(s*3.1415/180);

    my=iniy+30*sin(s*3.1415/180);

    this->setPos(mx,my);
}
void PiedraMov::Actualizacion(){
    columnas +=30;
    if(columnas>=60){
        columnas=0;
    }

    this->update(-ancho,-alto,ancho,alto);
}


