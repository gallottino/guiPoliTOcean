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

    Mat img;
    cap >> img;
    cv::cvtColor(img,img,CV_BGR2HLS);
    Mat redOnly;
    inRange(img, Scalar(0, 0, 40), Scalar(180, 200, 255), redOnly);
    Mat res;
    img.copyTo(res,redOnly);
    //cv::imshow("red",res);
    QImage imdisplay((uchar*)res.data, redOnly.cols, res.rows, res.step, QImage::Format_RGB888);
    ui->display_image->setPixmap(QPixmap::fromImage(imdisplay));
}

