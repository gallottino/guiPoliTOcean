#include "vision.h"
#include <iostream>
#include <vector>

RNG rng(12345);

using namespace std;
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


    Mat res,redOnly,redOnly2;

    //COLOR RED IN HSL (N.B in openCV is HLS
    /* RED HUE 340 -> 360 to 0 -> 10  H = H/2 */
    //blur(src,src,Size(2,2));
    inRange(src, Scalar(165, 25, 25), Scalar(180,160, 255), redOnly);
    inRange(src, Scalar(0, 25, 25), Scalar(10, 160, 255), redOnly2);

    src.copyTo(res,redOnly2);
    src.copyTo(res,redOnly);

    cvtColor(res,res,CV_HLS2RGB);
    cvtColor(res,res,CV_RGB2GRAY);
    threshold(res,res,0,255,CV_THRESH_BINARY);



    return res;
}


Mat Vision::filterBlue(Mat src)
{
    Mat res,blueOnly;

    //GAUSSIAN BLUR FOR SMOOTH IMAGE
    //GaussianBlur(src, blur, Size( 3, 3 ), 0, 0 );
    //blur(src,src,Size(5,5));
    //COLOR BLUE IN HSL (N.B in openCV is HLS
    /* Be careful to S value -> low saturation is not good */
    inRange(src, Scalar(100, 25, 90), Scalar(120,200, 255), blueOnly);

    src.copyTo(res,blueOnly);

    cvtColor(res,res,CV_HLS2RGB);
    cvtColor(res,res,CV_RGB2GRAY);

    threshold(res,res,0,255,CV_THRESH_BINARY);

    return res;
}

Mat Vision::filterBlack(Mat src)
{
    Mat res,blackOnly,gray;

    blur(src,src,Size(2,2));
    inRange(src, Scalar(0, 0, 0), Scalar(255,60, 100), blackOnly);
    src.copyTo(res,blackOnly);

    cvtColor(res,res,CV_HLS2RGB);
    cvtColor(res,res,CV_RGB2GRAY);

    threshold(res,res,0,255,CV_THRESH_BINARY);

    return res;
}

void Vision::getLenghtFromCenter(Mat src)
{
    int areaRed,areaBlue;
    int lato = 80;

    double lineTicknessPixel,area,lengthPixel,length;

    Mat red,blue;
    Rect roi;


    roi.x = src.size().width/2 - lato/2;
    roi.y = src.size().height/2 - lato/2;
    roi.width = lato;
    roi.height = lato;
    area = lato * lato;

    red = filterRed(src);
    blue = filterBlue(src);

    areaRed = countNonZero(red(roi));
    areaBlue = countNonZero(blue);


    lineTicknessPixel = (areaRed / (area) ) * lato;

    lengthPixel = areaBlue / lineTicknessPixel;

    cout<< lengthPixel << endl;

    length = lengthPixel * LINE_TICKNESS / lineTicknessPixel ;


    cout<< length << endl;
}


Mat Vision::addROI(Mat src){

    Mat res;

    int lato = 80;
    Point p1(src.size().width/2 - lato/2,src.size().height/2 - lato/2);
    Point p2(src.size().width/2 + lato/2,src.size().height/2 - lato/2);
    Point p3(src.size().width/2 - lato/2,src.size().height/2 + lato/2);
    Point p4(src.size().width/2 + lato/2,src.size().height/2 + lato/2);

    vector<Point> contour;
    contour.push_back(p4);
    contour.push_back(p2);
    contour.push_back(p1);
    contour.push_back(p3);
    vector<vector<Point> > con = vector<vector<Point> >(1, contour);

    Scalar color = Scalar( 255,0,0);
    drawContours(src, con, -1, color, 1, 1);

    return src;
}


bool Vision::isCentered(Mat srcBlackFiltered)
{

    Mat image;
    int cont = 0;

    image = filterBlack(srcBlackFiltered);

    for (int row = 50; row < 90; ++row)
    {
        const uchar *ptr = image.ptr(row);
        const uchar * uc_pixel = ptr;
        int a = uc_pixel[0];
        if(a){
            cont++;
            if(cont > 20) return true;
        }
    }

    return false;
}


int Vision::getLenghtFromBlack(Mat black,Mat blue)
{
    int cont = 0,dist = 0,areaBlue,lengthBluePixel;
    double pixelPerCm,length = 0;

    for(int col = black.size().width - 1; col > 0; col--){


        const uchar *ptr = black.ptr(50);
        const uchar * uc_pixel = ptr + col;

        if(uc_pixel[0]){
            cont = 0;
            for (int row = 50; row < 90; ++row)
            {
                const uchar *ptr = black.ptr(row) + col;
                const uchar * uc_pixel = ptr;

                if(uc_pixel[0]){
                    cont++;
                    if(cont > 20){
                        dist = col;
                        pixelPerCm = double(dist / SQUARE_LENGTH);
                        areaBlue = countNonZero(blue);
                        lengthBluePixel = (double) (areaBlue / (LINE_TICKNESS * pixelPerCm));
                        length = lengthBluePixel / pixelPerCm;

                         cout <<length<<endl;

                         return length;
                    }
                }

                //cout << cont << endl;
            }
        }
    }

    cout<< length <<endl;
    return 0;
}
