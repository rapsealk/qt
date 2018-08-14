#include <QPainter>
#include <QPaintEvent>

#ifndef HELPER_H
#define HELPER_H


class Helper
{
public:
    Helper();

public:
    void paint(QPainter *painter, QPaintEvent *event, int elapsed);

private:
    QBrush background;
    QBrush circleBrush;
    QFont testFont;
    QPen circlePen;
    QPen textPen;
};

#endif // HELPER_H
