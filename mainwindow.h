#ifndef MAINWINDOW_H
#define MAINWINDOW_H


enum MODE{
    MODE_HOME,
    MODE_AUTO,
    MODE_SHAPES
};

#include <QMainWindow>
#include <iostream>
#include <opencv2/opencv.hpp>
//#include "ipcamera.h"

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
    //IpCamera cam;
    VideoCapture cap;

    ~MainWindow();

public slots:    // A slot or function is defined which will be intiated by timer
    void DisplayImage();
    void setVideoStart();
    void modeAuto();
    void modeShapes();
    void modeHome();

private:
    bool video;
    Ui::MainWindow *ui;
    Mat img;   
    QIcon icon,icon2,video_icon,auto_icon,shapes_icon,home_icon;
    QIcon auto_icon_w,shapes_icon_w,home_icon_w;
    MODE mode = MODE_HOME;
};

#endif // MAINWINDOW_H
