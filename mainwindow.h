#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "ipcamera.h"

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QImage imdisplay;  //This will create QImage which is shown in Qt label
    QTimer* Timer;   // A timer is needed in GUI application
    IpCamera cam;
    VideoCapture cap;

    ~MainWindow();

public slots:    // A slot or function is defined which will be intiated by timer
    void DisplayImage();
    void setVideoStart();

private:
    Ui::MainWindow *ui;
    Mat img;
    bool video;
};

#endif // MAINWINDOW_H
