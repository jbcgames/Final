#include "uva.h"
#include "sprite.h"
#include "objeto.h"
#include <QGraphicsScene>
#include "math.h"
Uva::Uva(QObject *parent) : QObject(parent)
{   s=0;
    m=true;
    timer=new QTimer();

    filas=0;
    columnas=0;
    pixmap = new QPixmap(":/SpriteUva.png");
    ancho=25;
    alto=39;
    timer->start(350);
    connect(timer, &QTimer::timeout,this,&Uva::Actualizacion);

}

QRectF Uva::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Uva::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}



void Uva::Actualizacion()
{
    columnas +=25;
    if(columnas>=50){
        columnas=0;
    }
    this->update(-ancho,-alto,ancho,alto);

}
