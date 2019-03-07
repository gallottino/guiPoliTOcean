#ifndef VISION_H
#define VISION_H

#include <opencv2/opencv.hpp>

#define LINE_WIDTH 1.8
#define OFFSET 2
#define TOLERANCE 3000

using namespace cv;

class Vision
{
public:
    Vision();
    static bool checkTop(Mat src);
    static bool checkLeft(Mat src);
    static bool checkRight(Mat src);
    static bool checkBottom(Mat src);
    static Mat filterRed(Mat src);

private:
    int height,width;
};

#endif // VISION_H
