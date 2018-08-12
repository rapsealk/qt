#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QPushButton>
#include <QGridLayout>

#ifndef MAINWIDGET_H
#define MAINWIDGET_H


class mainwidget : public QWidget
{
    Q_OBJECT
public:
    mainwidget();
    void button_action_01();
    void button_action_02();
private:
    QMediaPlayer *player01, *player02;
    QMediaContent *mediaContent01, *mediaContent02;
    char urls[2][36] = {
        "http://localhost:3000/TT.mp4",
        "http://localhost:3000/LoveU.mp4"
    };
    QPushButton *button01, *button02;
    QGridLayout *gridLayout;
};

#endif // MAINWIDGET_H
