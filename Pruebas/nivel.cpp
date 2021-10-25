#include "nivel.h"  
#include <QFont>
#include<widget.h>
extern Widget *w;
    Nivel::Nivel(QGraphicsTextItem *parent):QGraphicsTextItem(parent){
        setPlainText("Nivel " + QString::number(a));
        setDefaultTextColor(Qt::black);
        setFont(QFont("times",100));
        timer=new QTimer();
        timer->start(2000);
        connect(timer,&QTimer::timeout,this,&Nivel::espera);
    }

    void Nivel::increase(int a)
    {
        this->a=a;
        setPlainText("Nivel " + QString::number(a));
    }

   void Nivel::espera(){
        delete this;

    }


