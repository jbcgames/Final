#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
class Score : public QGraphicsTextItem
{
public:
   Score(QGraphicsTextItem *parent=0);
   void increase();
   void decrease();
   int getScore();
private:
   int score,vida=3;
};

#endif // SCORE_H
