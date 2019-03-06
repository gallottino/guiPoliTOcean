#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cap.open(0);
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(DisplayImage()));
    Timer->start(33);
}

MainWindow::~MainWindow()
{
    cap.release();
    delete ui;
}

void MainWindow::DisplayImage(){

    Mat img,img_hls,redOnly,res,laplace;
    cap >> img;

    cv::cvtColor(img,img_hls,CV_BGR2HLS);
    //cv::cvtColor(img,img,CV_BGR2RGB);


    //RED RECOGNIZE
    inRange(img_hls, Scalar(150, 20, 10), Scalar(180, 255, 255), redOnly);
    img.copyTo(res,redOnly);
    
    //CHECK BORDER
//    Laplacian(img,laplace,CV_16S,5);
//    convertScaleAbs(laplace, res, (3+1)*0.25);

    //img = cam.getFrame();
    QImage cam1((uchar*)res.data, res.cols, res.rows, res.step, QImage::Format_RGB888);
    //QImage cam2((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->display_image->setPixmap(QPixmap::fromImage(cam1));
    //ui->display_image_2->setPixmap(QPixmap::fromImage(cam2));

}

