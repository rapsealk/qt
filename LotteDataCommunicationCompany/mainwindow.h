#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QLabel>
#include "mainwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // QGridLayout *gridLayout;
    QMediaPlayer *player01;
    QMediaContent *mediaContent01;
    QVideoWidget *videoWidget01;
};

#endif // MAINWINDOW_H
