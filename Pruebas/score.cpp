#include "score.h"
#include <QFont>

Score::Score(QGraphicsTextItem *parent):QGraphicsTextItem(parent){
    score=0;
    setPlainText("Score: " + QString::number(score*100)+"                                                                                                 Vidas: "+QString::number(vida));
    setDefaultTextColor(Qt::black);

    setFont(QFont("times",15));
}

void Score::increase()
{
    score++;
    setPlainText("Score: " + QString::number(score*100)+"                                                                                             Vidas: "+QString::number(vida));
}
void Score::decrease(){
    vida--;
    setPlainText("Score: " + QString::number(score*100)+"                                                                                             Vidas: "+QString::number(vida));
  }

int Score::getScore()
{
    return score;
}
