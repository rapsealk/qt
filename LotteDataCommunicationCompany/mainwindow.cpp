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

    MainWidget *mainwidget = new MainWidget();
    //QGridLayout *gridLayout = new QGridLayout(this);
    //gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
    //gridLayout->addWidget(mainwidget);
    //this->setLayout(gridLayout);
    this->setCentralWidget(mainwidget);
    //ui->gridLayout->addWidget(mainwidget);
    /*
    // gridLayout = new QGridLayout(parent);
    QLabel *label = new QLabel(this);
    QLabel *label1 = new QLabel(this);
    QLabel *label2 = new QLabel(this);
    QLabel *label3 = new QLabel(this);

    label->setText("111111111");
    label1->setText("22222222");
    label2->setText("33333333");
    label3->setText("44444444");

    ui->gridLayout->addWidget(label, 0, 0, 1, 1);
    ui->gridLayout->addWidget(label1, 0, 1, 1, 1);
    ui->gridLayout->addWidget(label2, 1, 0, 1, 1);
    ui->gridLayout->addWidget(label3, 1, 1, 1, 1);
    // gridLayout->addWidget(videoWidget01, 0, 0, 1, 1);
    //this->setLayout(ui->gridLayout);
    //this->resize(700, 700);

    // splitter = new QSplitter(parent);
    */

    // this->statusBar()->setSizeGripEnabled(false);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen->geometry();
    this->setMinimumSize(rect.width(), rect.height());
    this->setMaximumSize(rect.width(), rect.height());
    this->setFixedSize(rect.width(), rect.height());

}

MainWindow::~MainWindow()
{
    delete ui;
}
