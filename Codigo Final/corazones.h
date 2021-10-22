/*#ifndef CORAZONES_H
#define CORAZONES_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class Corazones : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Corazones(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;
    float filas,columnas,ancho, alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:

public slots:
    void Actualizacion();

};

#endif // CORAZONES_H
*/
