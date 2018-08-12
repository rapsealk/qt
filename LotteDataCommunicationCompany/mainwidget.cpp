#include "mainwidget.h"

#define MEDIA_VOLUME    50
#define WIDTH           700
#define HEIGHT          700

MainWidget::MainWidget()
{
    this->setWindowIcon(QIcon("://resources/lotte.ico"));
    this->setWindowTitle("Lotte Data Communication Company");

    this->player01 = new QMediaPlayer;
    this->mediaContent01 = new QMediaContent(QUrl(urls[0]));
    this->player01->setMedia(*mediaContent01);
    this->player01->setVolume(MEDIA_VOLUME);

    this->player02 = new QMediaPlayer;
    this->mediaContent02 = new QMediaContent(QUrl(urls[1]));
    this->player02->setMedia(*mediaContent02);
    this->player02->setVolume(MEDIA_VOLUME);

    videoWidget01 = new QVideoWidget();
    player01->setVideoOutput(videoWidget01);
    player01->play();

    videoWidget02 = new QVideoWidget();
    player02->setVideoOutput(videoWidget02);
    player02->play();

    gridLayout = new QGridLayout();
    gridLayout->addWidget(videoWidget01, 0, 0, 1, 1);
    gridLayout->addWidget(videoWidget02, 1, 1, 1, 1);

    button01 = new QPushButton("Button 01", this);
    QObject::connect(button01, SIGNAL (clicked()), this, SLOT(clickedSlot()));
    gridLayout->addWidget(button01, 2, 0, 1, 1);

    button02 = new QPushButton("Button 02", this);
    QObject::connect(button02, SIGNAL (clicked()), this, SLOT(clickedSlot()));
    gridLayout->addWidget(button02, 2, 1, 1, 1);

    this->setLayout(gridLayout);
    this->resize(WIDTH, HEIGHT);
}

MainWidget::~MainWidget() {
    delete player01;
    delete player02;
    delete mediaContent01;
    delete mediaContent02;
    delete videoWidget01;
    delete videoWidget02;
    delete gridLayout;
    delete button01;
    delete button02;
}

void MainWidget::clickedSlot() {
    qDebug() << ((QPushButton*) sender())->text();
    QString buttonTag = ((QPushButton*)sender())->text();
    QMediaPlayer *player = NULL;
    if (buttonTag == "Button 01") player = player01;
    else if (buttonTag == "Button 02") player = player02;

    if (player == NULL) {
        qDebug() << "Button is null!";
        return;
    }

    if (player->state() != QMediaPlayer::State::PlayingState) {
        player->play();
    } else {
        player->pause();
    }
}

/*
void MainWidget::button_action_01() {
    qDebug() << "Button_01 has clicked!";
    if (player01->state() != QMediaPlayer::State::PlayingState) {
        player01->play();
    } else {
        player01->pause();
    }
}

void MainWidget::button_action_02() {
    qDebug() << "Button_02 has clicked!";
    if (player02->state() != QMediaPlayer::State::PlayingState) {
        player02->play();
    } else {
        player02->pause();
    }
}
*/
