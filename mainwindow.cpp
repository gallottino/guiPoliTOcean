#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "vision.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cap.open(0);

    //INIT PRIVATE VARIABLE
    video = false;

    /*TIMER DISPLAY CAMERAS*/
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(DisplayImage()));
    Timer->start(33);

    /*CONNECTION BUTTONS*/
    connect(ui->startVideo,SIGNAL(clicked()),SLOT(setVideoStart()));
}

MainWindow::~MainWindow()
{
    cap.release();
    delete ui;
}

void MainWindow::DisplayImage(){

    Mat img_hls,res;
    if(video){

        cap >> img;
        //img = cam.getFrame();
        cv::cvtColor(img,img_hls,CV_BGR2HLS);
        res = Vision::filterRed(img_hls);

        QImage cam1((uchar*)res.data, res.cols, res.rows, res.step, QImage::Format_RGB888);
        ui->display_image->setPixmap(QPixmap::fromImage(cam1));

        //QImage cam2((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
        //ui->display_image_2->setPixmap(QPixmap::fromImage(cam2));
    }
    else
    {

    }
}


void MainWindow::setVideoStart()
{
    video = !video;
}

