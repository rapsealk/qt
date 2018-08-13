#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
//#include <QWebEngineView>
//#include <QMessageBox>

#ifndef MAINWIDGET_H
#define MAINWIDGET_H


class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget();
    ~MainWidget();
private:
    QMediaPlayer *player01, *player02, *player03;
    QMediaContent *mediaContent01, *mediaContent02, *mediaContent03;
    char urls[3][42] = {
        "http://localhost:3000/WhyDon'tYouKnow.mp4",
        "http://localhost:3000/RollerCoaster.mp4",
        "http://localhost:3000/LoveU.mp4"
    };
    QVideoWidget *videoWidget01, *videoWidget02, *videoWidget03;
    QGridLayout *gridLayout;

    QPixmap cipix;
    QLabel *cilabel;

    QPixmap bgpix;
    QLabel *bglabel;

    QPixmap leaderpix;
    QLabel *leaderlabel;
    QPixmap followerpix01, followerpix02;
    QLabel *followerlabel01, *followerlabel02;

    // QWebEngineView *webEngineView;
};

#endif // MAINWIDGET_H
