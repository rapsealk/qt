#include "mainwidget.h"

#define MEDIA_VOLUME    50
#define WIDTH           700
#define HEIGHT          700

MainWidget::MainWidget() : webEngineView(new QWebEngineView(this))
{
    this->setWindowIcon(QIcon("://resources/lotte.ico"));
    this->setWindowTitle("Drone GCS");

    /* TODO: Lotte CI
    this->cipix = QPixmap("://resources/lotte_dc_ci.png");
    this->cilabel = new QLabel(this);
    this->cilabel->resize(320, 240);
    this->cilabel->move(200, -200);
    this->cilabel->setPixmap(cipix);
    // this->cilabel->show();
    */

    this->player01 = new QMediaPlayer;
    this->mediaContent01 = new QMediaContent(QUrl(urls[0]));
    this->player01->setMedia(*mediaContent01);
    this->player01->setVolume(MEDIA_VOLUME);

    this->player02 = new QMediaPlayer;
    this->mediaContent02 = new QMediaContent(QUrl(urls[1]));
    this->player02->setMedia(*mediaContent02);
    this->player02->setVolume(MEDIA_VOLUME);

    this->player03 = new QMediaPlayer;
    this->mediaContent03 = new QMediaContent(QUrl(urls[2]));
    this->player03->setMedia(*mediaContent03);
    this->player03->setVolume(MEDIA_VOLUME);

    videoWidget01 = new QVideoWidget();
    player01->setVideoOutput(videoWidget01);
    player01->play();

    videoWidget02 = new QVideoWidget();
    player02->setVideoOutput(videoWidget02);
    player02->play();

    videoWidget03 = new QVideoWidget();
    player03->setVideoOutput(videoWidget03);
    player03->play();

    gridLayout = new QGridLayout();
    gridLayout->addWidget(videoWidget01, 0, 0, 1, 1);
    gridLayout->addWidget(videoWidget02, 0, 1, 1, 1);
    gridLayout->addWidget(videoWidget03, 1, 0, 1, 1);

    // webEngineView->resize(300, 300);

    /* this->webEngineView = new QWebEngineView(this);
    QWebEnginePage *webEnginePage = webEngineView->page();
    QObject::connect(webEnginePage, &QWebEnginePage::featurePermissionRequested, [this, webEnginePage](const QUrl &securityOrigin, QWebEnginePage::Feature feature) {
        if (feature != QWebEnginePage::Geolocation) return;

        QMessageBox msgBox(this);
        msgBox.setText(tr("%1 wants to know your location.").arg(securityOrigin.host()));
        msgBox.setInformativeText(tr("Do you want to send your current location to this website?"));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);

        qDebug() << "msgBox.exec(): " << msgBox.exec();
        qDebug() << "QMessageBox::Yes: " << QMessageBox::Yes;
        qDebug() << "QMessageBox::No: " << QMessageBox::No;

        if (msgBox.exec() == QMessageBox::Yes) {
            webEnginePage->setFeaturePermission(securityOrigin, feature, QWebEnginePage::PermissionGrantedByUser);
        } else {
            webEnginePage->setFeaturePermission(securityOrigin, feature, QWebEnginePage::PermissionDeniedByUser);
        }
    });
    webEnginePage->load(QUrl("://resources/googlemap.html"));
    gridLayout->addWidget(webEngineView, 1, 1, 1, 1);
    */

    // gridLayout->addWidget(cilabel, 2, 0, 1,1);
    // this->cilabel->showNormal();

    this->setLayout(gridLayout);
    this->resize(WIDTH, HEIGHT);
}

MainWidget::~MainWidget() {
    delete player01;
    delete player02;
    delete player03;
    delete mediaContent01;
    delete mediaContent02;
    delete mediaContent03;
    delete videoWidget01;
    delete videoWidget02;
    delete videoWidget03;
    delete gridLayout;
    // delete button01;
    // delete button02;
}
/*
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
*/
