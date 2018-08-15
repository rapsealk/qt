#include <QWidget>
#include <QOpenGLWidget>
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


class MainWidget : /*public QOpenGLWidget*/ public QWidget
{
    Q_OBJECT
public:
    MainWidget();
    ~MainWidget();
private slots:
    void clickMoveButton();
/*
    void animate();
protected:
    void paintEvent(QPaintEvent *event) override;
*/
protected:
    void resizeEvent(QResizeEvent *event);
private:
    // Helper *helper;
    int elapsed;
    QMediaPlayer *player01, *player02, *player03;
    QMediaContent *mediaContent01, *mediaContent02, *mediaContent03;
    char urls[3][42] = {
        "http://localhost:3000/2.mp4",
        "http://localhost:3000/4.mp4",
        "http://localhost:3000/3.mp4"
        /*
        "http://localhost:3000/WhyDon'tYouKnow.mp4",
        "http://localhost:3000/RollerCoaster.mp4",
        "http://localhost:3000/LoveU.mp4"
        */
    };
    QVideoWidget *videoWidget01, *videoWidget02, *videoWidget03;
    QGridLayout *gridLayout;

    QPixmap cipix;
    QLabel *cilabel;

    QPixmap bgpix;
    QLabel *bglabel;

    QPixmap leaderpix;
    QLabel *leaderlabel;
    QPixmap followerpix;
    QLabel *followerLabel01, *followerLabel02;

    QPushButton *pushButton;
    // QWebEngineView *webEngineView;
};

#endif // MAINWIDGET_H
