#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QtDebug>
#include "sprite.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    Sprite *donalt;
    float x,y,ancho,alto;

};
#endif // WIDGET_H
