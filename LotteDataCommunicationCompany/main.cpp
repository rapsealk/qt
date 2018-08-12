#include "mainwindow.h"
#include <QApplication>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QPushButton>

void button_action_01();
void button_action_02();

static QMediaPlayer *player = NULL, *player2 = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    /*
    QMediaPlayer *player = new QMediaPlayer;
    QMediaPlaylist *playlist = new QMediaPlaylist(player);
    playlist->addMedia(QUrl("http://localhost:3000/TT.mp4"));
    QVideoWidget *videoWidget = new QVideoWidget;
    videoWidget->resize(700, 700);
    player->setVideoOutput(videoWidget);
    videoWidget->show();
    playlist->setCurrentIndex(1);
    player->play();
    */

   //  QMediaPlayer *player = new QMediaPlayer;
    player = new QMediaPlayer;
    QMediaContent *mediaContent = new QMediaContent(QUrl("http://localhost:3000/TT.mp4"));
    player->setMedia(*mediaContent);
    player->setVolume(50);
    QVideoWidget *videoWidget = new QVideoWidget();
    //videoWidget->resize(700, 700);
    // videoWidget->show();

    // w.addDockWidget(videoWidget);
    // w.addWidget(videoWidget, 0, 0, 1, 1);

    // Q2
    // QMediaPlayer *player2 = new QMediaPlayer;
    player2 = new QMediaPlayer;
    QMediaContent *mediaContent2 = new QMediaContent(QUrl("http://localhost:3000/LoveU.mp4"));
    player2->setMedia(*mediaContent2);
    player2->setVolume(50);
    QVideoWidget *videoWidget2 = new QVideoWidget();

    // Button
    QPushButton *button1 = new QPushButton("Button 1");
    QPushButton *button2 = new QPushButton("Button 2");

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(videoWidget, 0, 0, 1, 1);
    gridLayout->addWidget(videoWidget2, 1, 1, 1, 1);
    // w.setLayout(gridLayout);
    gridLayout->addWidget(button1, 2, 0, 1, 1);
    gridLayout->addWidget(button2, 2, 1, 1, 1);

    // w.show();

    QWidget *w = new QWidget();
    w->setWindowIcon(QIcon("://resources/lotte.ico"));
    w->setWindowTitle("Lotte Data Communication Company");
    w->setLayout(gridLayout);
    w->resize(700, 700);
    w->show();

    // w->connect(button1, SIGNAL (released()), w, SLOT (button_action_01()));
    // w->connect(button2, SIGNAL (released()), w, SLOT (button_action_02()));

    player->setVideoOutput(videoWidget);
    player->play();

    player2->setVideoOutput(videoWidget2);
    player2->play();

    qDebug() << player->availableMetaData() << player->currentMedia().canonicalUrl();
    qDebug() << player->errorString();

    return a.exec();
}

void button_action_01() {
    qDebug() << "Button 01 clicked!";
    if (player->state() != QMediaPlayer::State::PlayingState) {
        player->play();
    } else {
        player->stop();
    }
}

void button_action_02() {
    qDebug() << "Button 02 clicked!";
    if (player2->state() != QMediaPlayer::State::PlayingState) {
        player2->play();
    } else {
        player2->stop();
    }
}
