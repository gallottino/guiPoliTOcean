#ifndef VISION_H
#define VISION_H

#include <opencv2/opencv.hpp>

#define LINE_TICKNESS 2.0
#define SQUARE_LENGTH 21.0
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

    /* FILTERS */
    static Mat filterRed(Mat src);
    static Mat filterBlue(Mat src);
    static Mat filterBlack(Mat src);
    static Mat addROI(Mat src);
    static bool isCentered(Mat srcBlackFiltered);
    static int getLenghtFromBlack(Mat black,Mat blue);
    static void getLenghtFromCenter(Mat src);


private:
    int height,width;
};

#endif // VISION_H
