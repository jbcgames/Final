#ifndef MANZANA_H
#define MANZANA_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class Manzana : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Manzana(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    void setFilas(int);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
signals:
public slots:
    void Actualizacion();
};

#endif // MANZANA_H
