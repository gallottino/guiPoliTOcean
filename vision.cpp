#include "vision.h"

Vision::Vision()
{

}

bool Vision::checkTop(Mat src)
{
    Rect top;

    top.x = 0;
    top.y = src.size().width/2 - OFFSET;
    top.width = OFFSET *2;
    top.height = src.size().height/2 - OFFSET;

    return false;
}

bool Vision::checkLeft(Mat src)
{
    return false;
}

bool Vision::checkRight(Mat src)
{
    return false;
}

bool Vision::checkBottom(Mat src)
{
    return false;
}

Mat Vision::filterRed(Mat src)
{
    Mat blur,res,redOnly;
    inRange(src, Scalar(150, 20, 10), Scalar(180, 255, 255), redOnly);
    GaussianBlur(src, blur, Size( 5, 5 ), 0, 0 );
    blur.copyTo(res,redOnly);
    return res;
}
