#include "ipcamera.h"

using namespace FlyCapture2;

IpCamera::IpCamera()
{
    //Connect the camera
    camera.Connect( 0 );

    // Get the camera info and print it out
    camera.GetCameraInfo( &camInfo );
    std::cout << camInfo.vendorName << " "
              << camInfo.modelName << " "
              << camInfo.serialNumber << std::endl;

    camera.StartCapture();
}

Mat IpCamera::getFrame()
{
    Image raw;
    camera.RetrieveBuffer(&raw);

    printf("Frames lost: %d \n", lost);
    Image rgb;
    raw.Convert( FlyCapture2::PIXEL_FORMAT_BGR, &rgb );

    unsigned int row = (double)rgb.GetReceivedDataSize()/(double)rgb.GetRows();

    return cv::Mat(rgb.GetRows(), rgb.GetCols(), CV_8UC3, rgb.GetData(),row);
}
