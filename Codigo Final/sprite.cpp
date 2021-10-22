#include "sprite.h"
#include "widget.h"
#include <QKeyEvent>
#include <QDebug>
#include <QList>
#include "score.h"
#include "piedra.h"
extern Widget *w;
Sprite::Sprite(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    timer2=new QTimer();
    filas=0;
    columnas=0;
    pixmap = new QPixmap(":/FinalNormal.png");
    ancho=70;
    alto=70;
    timer->start(190);
    timer2->start(0);
    connect(timer, &QTimer::timeout,this,&Sprite::Actualizacion);
    connect(timer2, &QTimer::timeout,this,&Sprite::Comer);
    connect(timer2, &QTimer::timeout,this,&Sprite::Columna);
}

void Sprite::setFilas(int a)
{
    this->filas=a*70;
}

QRectF Sprite::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}



void Sprite::Actualizacion()
{

    columnas +=70;
    if(columnas>=280){
        columnas=0;

    }
    this->update(-ancho,-alto,ancho,alto);
}

void Sprite::Comer()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Platano)||typeid(*(colliding_items[i]))==typeid(Uva)){
            delete colliding_items[i];
            w->score->increase();
            return;
        }
    }
}
void Sprite::Columna()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Piedra)){
            if(filas/70==2){
                w->z+=10;
                w->donalt->setPos(w->w,w->z);
                return;
            }else if(filas/70==3){
                w->z-=10;
                w->donalt->setPos(w->w,w->z);
                return;
            }else if(filas/70==1){
                w->w-=10;
                w->donalt->setPos(w->w,w->z);
                return;
            }else if(filas/70==0){
                w->w+=10;
                w->donalt->setPos(w->w,w->z);
                return;
            }
        }
    }
}

