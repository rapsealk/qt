#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QGridLayout>

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
    // QSplitter *splitter;
    QGridLayout *gridLayout;
};

#endif // MAINWINDOW_H
