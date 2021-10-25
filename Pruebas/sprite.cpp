#include "sprite.h"
#include "widget.h"
#include <QKeyEvent>
#include <QDebug>
#include <QList>
#include "score.h"
#include "piedra.h"
#include <QGraphicsScene>
#include "time.h"
#include <unistd.h>
#include "comiendo.h"
extern Widget *w;
extern PiedraMov *mov;
Sprite::Sprite(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    timer2=new QTimer();
    timer3=new QTimer();
    filas=0;
    columnas=0;
    pixmap = new QPixmap(":/FinalNormal.png");
    ancho=70;
    alto=70;
    timer->start(100);
    timer2->start(0);
    exp=new Explosion();
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
        if(typeid(*(colliding_items[i]))==typeid(Platano)||typeid(*(colliding_items[i]))==typeid(Uva)||typeid(*(colliding_items[i]))==typeid(Manzana)){
            Comiendo *m=new Comiendo();
            if(w->scenea==1){
            w->scene->addItem(m);}
            if(w->scenea==2){
            w->scene2->addItem(m);}
            if(w->scenea==3){
            w->scene3->addItem(m);}
            if(w->ah==87){
              m->setFilas(2);
            }else if(w->ah==83){
              m->setFilas(3);
            }else if(w->ah==68){
                m->setFilas(1);
            }else if(w->ah==65){
                m->setFilas(0);
            }
            w->move=false;
            w->donalt->setPos(10000,111110);
            m->setPos(w->w,w->z);
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
            if(w->ah==87){
                w->z+=10;
                this->setPos(w->w,w->z);
                return;
            }else if(w->ah==83){
                w->z-=10;
                this->setPos(w->w,w->z);
                return;
            }else if(w->ah==68){
                w->w-=10;
                this->setPos(w->w,w->z);
                return;
            }else if(w->ah==65){
                w->w+=10;
                this->setPos(w->w,w->z);
                return;
            }
        }
        if(typeid(*(colliding_items[i]))==typeid(PiedraMov)||typeid(*(colliding_items[i]))==typeid(PiedraMovSen)||typeid(*(colliding_items[i]))==typeid(PiedraMovPend)){
            w->donalt->setPos(0,0);

            this->Muerte();
            return;
        }
    }
}

void Sprite::Muerte()
{
          w->Explos();
        w->w=100;
        w->z=100;
        w->donalt->setPos(w->w,w->z);



}


