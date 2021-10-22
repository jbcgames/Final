#define EVENT_H

#include <QObject>

class Event : public QObject
{
    Q_OBJECT
protected:
  bool eventFilter(QObject *obj, QEvent *event) override;
};


