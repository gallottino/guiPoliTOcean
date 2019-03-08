#include "vision.h"

Vision::Vision()
{

}

bool Vision::checkTop(Mat src)
{
    //DEFINE ROI (Region Of Interest)
    Rect top;

    top.x = src.size().width/2 - OFFSET;
    top.y = 0;
    top.width = OFFSET *2;
    top.height = src.size().height/2 - OFFSET;

    //COUNT NUMBER OF PIXEL != BLACK
    int n_pixels = countNonZero(src(top));
    if(n_pixels > TOLERANCE)
        return true;

    return false;
}

bool Vision::checkLeft(Mat src)
{
    //DEFINE ROI (Region Of Interest)
    Rect roi;

    roi.x = 0;
    roi.y = src.size().height/2 - OFFSET;
    roi.width = OFFSET *2;
    roi.height = src.size().height/2 - OFFSET;

    //COUNT NUMBER OF PIXEL != BLACK
    int n_pixels = countNonZero(src(roi));
    if(n_pixels > TOLERANCE)
        return true;

    return false;
}

bool Vision::checkRight(Mat src)
{
    //DEFINE ROI (Region Of Interest)
    Rect roi;

    roi.x = src.size().height;
    roi.y = src.size().width/2 - OFFSET;
    roi.width = OFFSET *2;
    roi.height = src.size().height/2 - OFFSET;


    //COUNT NUMBER OF PIXEL != BLACK
    int n_pixels = countNonZero(src(roi));
    if(n_pixels > TOLERANCE)
        return true;

    return false;
}

bool Vision::checkBottom(Mat src)
{
    //DEFINE ROI (Region Of Interest)
    Rect roi;

    roi.x = src.size().width;
    roi.y = src.size().height/2 + OFFSET;
    roi.width = OFFSET *2;
    roi.height = src.size().height/2 - OFFSET;

    //COUNT NUMBER OF PIXEL != BLACK
    int n_pixels = countNonZero(src(roi));
    if(n_pixels > TOLERANCE)
        return true;

    return false;
}

Mat Vision::filterRed(Mat src)
{
    Mat blur,res,redOnly;

    //GAUSSIAN BLUR FOR SMOOTH IMAGE
    //GaussianBlur(src, blur, Size( 3, 3 ), 0, 0 );

    //COLOR RED IN HSL (N.B in openCV is HLS
    inRange(src, Scalar(160, 0, 0), Scalar(180, 200, 200), redOnly);
    src.copyTo(res,redOnly);

    return res;
}
