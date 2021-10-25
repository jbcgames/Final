#include "comiendo.h"

#include "uva.h"
#include "sprite.h"
#include "objeto.h"
#include <QGraphicsScene>
#include "math.h"
#include "widget.h"
extern Widget *w;
Comiendo::Comiendo(QObject *parent) : QObject(parent)
{   s=0;
    m=true;
    timer=new QTimer();

    filas=0;
    columnas=0;
    pixmap = new QPixmap(":/Comiendofinal.png");
    ancho=70;
    alto=70;
    timer->start(110);
    connect(timer, &QTimer::timeout,this,&Comiendo::Actualizacion);

}
void Comiendo::setFilas(int a)
{
    this->filas=a*70;
}

QRectF Comiendo::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Comiendo::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}



void Comiendo::Actualizacion()
{

    columnas +=70;
    if(columnas==280){
       w->move=true;
        w->donalt->setPos(w->w,w->z);

       delete this;

    }
    this->update(-ancho,-alto,ancho,alto);

}
