#ifndef PIEDRA_H
#define PIEDRA_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class Piedra : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Piedra(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    void setFilas(int);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);


};

#endif // PIEDRA_H
