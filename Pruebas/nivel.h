#ifndef NIVEL_H
#define NIVEL_H
#include <QGraphicsTextItem>
#include <QTimer>

class Nivel : public QGraphicsTextItem
{
public:
   Nivel(QGraphicsTextItem *parent=0);
   void increase(int);
   void decrease();
   int getScore();
   QTimer *timer;
   void espera();
   int a=1;
private:
   int nivel=1;
};
#endif // NIVEL_H
