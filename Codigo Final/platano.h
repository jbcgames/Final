#ifndef PLATANO_H
#define PLATANO_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class Platano : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Platano(QObject *parent = nullptr);
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


#endif // PLATANO_H
