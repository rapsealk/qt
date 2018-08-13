#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("://resources/lotte.ico"));
    this->setWindowTitle("Lotte Data Communication Company");

    /*
    this->player01 = new QMediaPlayer;
    this->mediaContent01 = new QMediaContent(QUrl("http://localhost:3000/TT.mp4"));
    this->player01->setMedia(*mediaContent01);
    this->player01->setVolume(50);
    this->videoWidget01 = new QVideoWidget();
    this->player01->setVideoOutput(videoWidget01);
    this->player01->play();
    */

    gridLayout = new QGridLayout(parent);
    // gridLayout->addWidget(videoWidget01, 0, 0, 1, 1);
    this->setLayout(gridLayout);
    this->resize(700, 700);

    // splitter = new QSplitter(parent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addWidget(QWidget *widget, int row, int column, int rowspan, int colspan) {
    // splitter->addWidget(widget);
    gridLayout->addWidget(widget, row, column, rowspan, colspan);
    //widget->resize(300, 300);
    /*
    QSizePolicy policy = widget->sizePolicy();
    policy.setHorizontalStretch(300);
    policy.setVerticalStretch(360);
    widget->setSizePolicy(policy);
    */
    // qDebug() << splitter->sizes() << std::endl;
}
