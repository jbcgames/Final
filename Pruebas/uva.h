#ifndef UVA_H
#define UVA_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Uva : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Uva(QObject *parent = nullptr);
    bool m;
    int mx,inix,my,iniy,s;
    void setMx(int);
    void setMy(int);
    QTimer *timer,*timer2;
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    void setFilas(int);
    void Mov();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
signals:
public slots:
    void Actualizacion();
};


#endif // UVA_H
