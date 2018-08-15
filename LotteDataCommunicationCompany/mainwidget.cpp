#include "mainwidget.h"

#define MEDIA_VOLUME    0
#define ROW_SPAN        1
#define COL_SPAN        1

MainWidget::MainWidget()
{
    this->setWindowIcon(QIcon("://resources/lotte.ico"));
    this->setWindowTitle("Drone GCS");

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
    gridLayout->addWidget(videoWidget01, 0, 0, ROW_SPAN, COL_SPAN);
    gridLayout->addWidget(videoWidget02, 0, 1, ROW_SPAN, COL_SPAN);
    gridLayout->addWidget(videoWidget03, 1, 0, ROW_SPAN, COL_SPAN);

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

    /**
     * Grid Layout
     */
    QGridLayout *mapGridLayout = new QGridLayout();

    // TODO: Background sample
    this->bgpix = QPixmap("://resources/sample.PNG");
    this->bglabel = new QLabel(this);

    this->bgpix = this->bgpix.scaled(this->videoWidget02->width(), videoWidget02->height(), Qt::AspectRatioMode::IgnoreAspectRatio);

    this->bglabel->setPixmap(bgpix);
    this->bglabel->setAlignment(Qt::AlignHCenter);
    // this->bglabel->resize(videoWidget02->width(), videoWidget02->height());
    mapGridLayout->addWidget(bglabel, 0, 0, 0, 0);
    // gridLayout->addWidget(bglabel, 1, 1, 1, 1);

    // TODO: Lotte CI
    this->cipix = QPixmap("://resources/lotte_dc_ci.png");
    this->cilabel = new QLabel(this);
    //this->cilabel->resize(320, 240);
    this->cilabel->setPixmap(cipix);
    this->cilabel->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    mapGridLayout->addWidget(cilabel, 0, 0, 0, 0);
    // gridLayout->addWidget(cilabel, 1, 1, 1, 1);

    // TODO: Drones
    this->leaderpix = QPixmap("://resources/leader.png");
    this->leaderpix = this->leaderpix.scaled(32, 32, Qt::AspectRatioMode::KeepAspectRatio);
    this->leaderlabel = new QLabel(this);
    this->leaderlabel->setMinimumSize(1, 1);
    this->leaderlabel->setPixmap(leaderpix);
    //this->leaderlabel->setScaledContents(true);
    // this->leaderlabel->adjustSize();
    mapGridLayout->addWidget(leaderlabel, 0, 0, 0, 0);
    this->leaderlabel->move(50, 50);

    this->followerpix = QPixmap("://resources/follower.png");
    this->followerpix = this->followerpix.scaled(32, 32, Qt::AspectRatioMode::KeepAspectRatio);
    this->followerLabel01 = new QLabel(this);
    this->followerLabel01->setPixmap(followerpix);
    mapGridLayout->addWidget(followerLabel01, 0, 0);

    this->followerLabel02 = new QLabel(this);
    this->followerLabel02->setPixmap(followerpix);
    mapGridLayout->addWidget(followerLabel02, 1, 1);
/*
    this->pushButton = new QPushButton("Move", this);
    QObject::connect(pushButton, SIGNAL (clicked()), this, SLOT(clickMoveButton()));
    mapGridLayout->addWidget(pushButton, 1, 1);
*/
    gridLayout->addLayout(mapGridLayout, 1, 1, ROW_SPAN, COL_SPAN);

    this->setLayout(gridLayout);
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

void MainWidget::clickMoveButton() {
    qDebug() << ((QPushButton*) sender())->text();
    qDebug() << "leaderpix.size: " << this->leaderpix.size();
    qDebug() << "leaderlabel->size: " << this->leaderlabel->size();
    qDebug() << "center: " << this->leaderlabel->geometry().center();
    qDebug() << "topLeft: " << this->leaderlabel->geometry().topLeft();
    qDebug() << "topRight: " << this->leaderlabel->geometry().topRight();
    qDebug() << "bottomLeft: " << this->leaderlabel->geometry().bottomLeft();
    qDebug() << "bottomRight: " << this->leaderlabel->geometry().bottomRight();
    // this->leaderlabel->move(this->leaderlabel->geometry().center());
}

void MainWidget::resizeEvent(QResizeEvent *event) {
    qDebug() << "resize!";
    //this->repaint();
    //this->gridLayout->update();
}
