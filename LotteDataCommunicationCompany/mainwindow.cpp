#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("://resources/lotte.ico"));
    this->setWindowTitle("Lotte Data Communication Company");

    // gridLayout = new QGridLayout(parent);
    // this->setLayout(gridLayout);

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
