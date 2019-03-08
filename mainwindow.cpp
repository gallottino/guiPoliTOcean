#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "vision.h"
#include <iostream>

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
    connect(ui->auto_drive,SIGNAL(clicked()),SLOT(modeAuto()));
    connect(ui->home,SIGNAL(clicked()),SLOT(modeHome()));
    connect(ui->shapes_recognize,SIGNAL(clicked()),SLOT(modeShapes()));


    //LOAD ICONS BUTTONS
    icon.addFile(QString::fromUtf8("images/microchip-solid.png"), QSize(), QIcon::Normal, QIcon::Off);
    icon2.addFile(QString::fromUtf8("images/gamepad-solid_w.png"), QSize(), QIcon::Normal, QIcon::Off);
    video_icon.addFile(QString::fromUtf8("images/video_error.png"), QSize(), QIcon::Normal, QIcon::Off);
    auto_icon.addFile(QString::fromUtf8("images/robot-solid.png"), QSize(), QIcon::Normal, QIcon::Off);
    shapes_icon.addFile(QString::fromUtf8("images/shapes-solid.png"), QSize(), QIcon::Normal, QIcon::Off);
    home_icon.addFile(QString::fromUtf8("images/home.png"), QSize(), QIcon::Normal, QIcon::Off);

    auto_icon_w.addFile(QString::fromUtf8("images/robot-solid_w.png"), QSize(), QIcon::Normal, QIcon::Off);
    shapes_icon_w.addFile(QString::fromUtf8("images/shapes-solid_w.png"), QSize(), QIcon::Normal, QIcon::Off);
    home_icon_w.addFile(QString::fromUtf8("images/home_w.png"), QSize(), QIcon::Normal, QIcon::Off);

    //SET ICON
    ui->joystick_status_2->setIcon(icon);
    ui->joystick_status_2->setIconSize(QSize(60, 60));

    ui->joystick_status->setIcon(icon2);
    ui->joystick_status->setIconSize(QSize(60, 60));

    ui->error_video->setIcon(video_icon);
    ui->error_video->setIconSize(QSize(400,400));

    ui->error_video_2->setIcon(video_icon);
    ui->error_video_2->setIconSize(QSize(400,400));

    ui->auto_drive->setIcon(auto_icon);
    ui->auto_drive->setIconSize(QSize(100,100));

    ui->shapes_recognize->setIcon(shapes_icon);
    ui->shapes_recognize->setIconSize(QSize(100,100));

    ui->home->setIcon(home_icon_w);
    ui->home->setIconSize(QSize(100,100));


}

MainWindow::~MainWindow()
{
    cap.release();
    delete ui;
}

void MainWindow::DisplayImage(){

    Mat img_hsv,res;
    if(video){
        cap >> img;
        //img = cam.getFrame();
        cv::cvtColor(img,img_hsv,CV_BGR2HSV);
        cv::cvtColor(img,img,CV_BGR2RGB);

        res = Vision::filterRed(img_hsv);

        //PROVA
        //cvtColor( img, src_gray, COLOR_BGR2GRAY );
        //blur( src_gray, src_gray, Size(3,3) );

//        createTrackbar( " Canny thresh:", "Source", &thresh, max_thresh, thresh_callback );
//        thresh_callback( 0, 0 );

        QImage cam1((uchar*)res.data, res.cols, res.rows, res.step, QImage::Format_RGB888);
        ui->display_image->setPixmap(QPixmap::fromImage(cam1));
        QImage cam2((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
        ui->display_image_2->setPixmap(QPixmap::fromImage(cam2));
    }
}

void MainWindow::setVideoStart()
{
    //TOOGLE START VIDEO
    video = !video;
    if(video){
        ui->error_video->setIcon(QIcon());
        ui->error_video_2->setIcon(QIcon());
    }
    else{
        ui->error_video->setIcon(video_icon);
        ui->error_video->setIconSize(QSize(400,400));
        ui->error_video_2->setIcon(video_icon);
        ui->error_video_2->setIconSize(QSize(400,400));
    }
}

void MainWindow::modeAuto()
{
    mode = MODE_AUTO;
    ui->auto_drive->setIcon(auto_icon_w);
    ui->auto_drive->setIconSize(QSize(100,100));

    ui->home->setIcon(home_icon);
    ui->home->setIconSize(QSize(100,100));
    ui->shapes_recognize->setIcon(shapes_icon);
    ui->shapes_recognize->setIconSize(QSize(100,100));

}

void MainWindow::modeShapes()
{
    mode = MODE_SHAPES;
    ui->shapes_recognize->setIcon(shapes_icon_w);
    ui->shapes_recognize->setIconSize(QSize(100,100));

    ui->auto_drive->setIcon(auto_icon);
    ui->auto_drive->setIconSize(QSize(100,100));
    ui->home->setIcon(home_icon);
    ui->home->setIconSize(QSize(100,100));

}
void MainWindow::modeHome()
{
    mode = MODE_HOME;
    ui->home->setIcon(home_icon_w);
    ui->home->setIconSize(QSize(100,100));

    ui->shapes_recognize->setIcon(shapes_icon);
    ui->shapes_recognize->setIconSize(QSize(100,100));
    ui->auto_drive->setIcon(auto_icon);
    ui->auto_drive->setIconSize(QSize(100,100));


}
