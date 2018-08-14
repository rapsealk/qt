#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addWidget(QWidget *widget, int row, int column, int rowspan, int colspan);

private:
    Ui::MainWindow *ui;
    QGridLayout *gridLayout;
    QMediaPlayer *player01;
    QMediaContent *mediaContent01;
    QVideoWidget *videoWidget01;
};

#endif // MAINWINDOW_H
