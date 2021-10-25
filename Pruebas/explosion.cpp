#include "explosion.h"
#include "sprite.h"
#include "objeto.h"
#include <QGraphicsScene>
#include "widget.h"
extern Widget *w;
Explosion::Explosion(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    filas=0;
    columnas=0;
    pixmap = new QPixmap(":/Exposion.png");
    ancho=75;
    alto=75;
    timer->start(50);
    connect(timer, &QTimer::timeout,this,&Explosion::Actualizacion);
}

void Explosion::setFilas(int a)
{
    this->filas=a*90;
}

QRectF Explosion::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}



void Explosion::Actualizacion()
{
    columnas +=75;
    if(columnas>=600){
        columnas=675;
    }

    this->update(-ancho,-alto,ancho,alto);

}
