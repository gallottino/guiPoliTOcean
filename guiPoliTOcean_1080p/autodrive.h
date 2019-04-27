#ifndef AUTODRIVE_H
#define AUTODRIVE_H

#include "vision.h"
#include <opencv2/opencv.hpp>
#include "mqtt/client.h"
#include "rovmqtt.h"
#include "commands.h"
#include "messages_publisher.h"

#define MAX_PATH 12

enum class Direction{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class AutoDrive
{

public:
    AutoDrive();
    AutoDrive(Direction startDirection);
    Direction updateDirection(Mat frame);
    Mat getGrid();
    void reset();


private:
    Point currentPos;
    Direction direction;
    MessagesPublisher* publisher;
    Direction path[MAX_PATH];
    Mat grid;


};

#endif // AUTODRIVE_H
