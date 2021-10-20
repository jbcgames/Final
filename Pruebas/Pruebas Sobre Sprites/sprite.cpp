#include "sprite.h"

Sprite::Sprite(QObject *parent) : QObject(parent)
{
    c=0;
    timer=new QTimer();
    filas=0;
    columnas=0;
    pixmap = new QPixmap(":/Imagenes/oorjG.png");
    ancho=90;
    alto=90;
    timer->start(150);
    connect(timer, &QTimer::timeout,this,&Sprite::Actualizacion);
}

QRectF Sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}



void Sprite::Actualizacion()
{
    columnas +=90;
    c++;
    if (c==20){
        c=0;
        filas+=90;
    }
    if (filas>=360){
        filas=0;
    }
    if(columnas>=450){
        columnas=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}
