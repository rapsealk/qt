#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QGridLayout>
#include <QPushButton>

#ifndef MAINWIDGET_H
#define MAINWIDGET_H


class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget();
    ~MainWidget();
private slots:
    void clickedSlot();
private:
    QMediaPlayer *player01, *player02;
    QMediaContent *mediaContent01, *mediaContent02;
    char urls[2][36] = {
        "http://localhost:3000/TT.mp4",
        "http://localhost:3000/LoveU.mp4"
    };
    QVideoWidget *videoWidget01, *videoWidget02;
    QGridLayout *gridLayout;
    QPushButton *button01, *button02;
};

#endif // MAINWIDGET_H
