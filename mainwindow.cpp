#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "vision.h"
#include <iostream>

using namespace std;
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
    ui->atMega_status->setIcon(icon);
    ui->atMega_status->setIconSize(QSize(60, 60));
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

    Mat img_hls,res,frame;
    if(video){
        cap >> frame;
        //img = cam.getFrame();
        img = frame;

        //img = imread("prova2.png");
        cvtColor(img,img_hls,CV_BGR2HLS);
        cvtColor(img,img,CV_BGR2RGB);

//        if(Vision::isCentered(img_hls)){
//            cout<<"SONO AL CENTRO"<<endl;
//            Vision::getLenghtFromBlack(Vision::filterBlack(img_hls),Vision::filterBlue(img_hls));
//        }

        img = Vision::addROI(img);
        QImage cam1((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
        ui->display_image->setPixmap(QPixmap::fromImage(cam1));

        if(mode == MODE_HOME){
            res = Vision::filterRed(img_hls);
            QImage cam2((uchar*)res.data, res.cols, res.rows, res.step, QImage::Format_Grayscale8);
            ui->display_image_2->setPixmap(QPixmap::fromImage(cam2));
        }

        Vision::getLenghtFromCenter(img_hls);
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

    ui->display_image_2->setVisible(false);
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

    ui->display_image_2->setVisible(false);
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

    ui->display_image_2->setVisible(true);

}
