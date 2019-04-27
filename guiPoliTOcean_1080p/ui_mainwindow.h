/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *display_image;
    QLabel *display_image_2;
    QPushButton *startVideo;
    QPushButton *joystick_status;
    QPushButton *atMega_status;
    QLabel *gradient;
    QLabel *gradient_2;
    QPushButton *error_video;
    QPushButton *error_video_2;
    QLabel *gradient_3;
    QPushButton *auto_drive;
    QPushButton *shapes_recognize;
    QLabel *gradient_4;
    QLabel *gradient_5;
    QLabel *gradient_6;
    QPushButton *home;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1300, 823);
        MainWindow->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:white;\n"
"border-style: solid;\n"
"\n"
"border-width: 1px;\n"
"border-radius: 7px;\n"
"}\n"
"QMainWindow{\n"
"	background-color: #37474f;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        display_image = new QLabel(centralWidget);
        display_image->setObjectName(QStringLiteral("display_image"));
        display_image->setGeometry(QRect(0, 0, 640, 480));
        display_image->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-color: #00838f ;\n"
"border-width: 3px;\n"
""));
        display_image_2 = new QLabel(centralWidget);
        display_image_2->setObjectName(QStringLiteral("display_image_2"));
        display_image_2->setGeometry(QRect(650, 0, 640, 480));
        display_image_2->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-color: #00838f ;\n"
"border-width: 3px;"));
        startVideo = new QPushButton(centralWidget);
        startVideo->setObjectName(QStringLiteral("startVideo"));
        startVideo->setGeometry(QRect(10, 630, 191, 54));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        startVideo->setFont(font);
        startVideo->setStyleSheet(QLatin1String("background-color:#eeeeee;\n"
"color: black;\n"
"border-color: white;"));
        joystick_status = new QPushButton(centralWidget);
        joystick_status->setObjectName(QStringLiteral("joystick_status"));
        joystick_status->setGeometry(QRect(10, 510, 96, 96));
        joystick_status->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #64dd17; \n"
"\n"
"}"));
        atMega_status = new QPushButton(centralWidget);
        atMega_status->setObjectName(QStringLiteral("atMega_status"));
        atMega_status->setGeometry(QRect(110, 510, 96, 96));
        atMega_status->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #c62828;\n"
"}"));
        gradient = new QLabel(centralWidget);
        gradient->setObjectName(QStringLiteral("gradient"));
        gradient->setGeometry(QRect(10, 520, 95, 92));
        gradient->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        gradient_2 = new QLabel(centralWidget);
        gradient_2->setObjectName(QStringLiteral("gradient_2"));
        gradient_2->setGeometry(QRect(110, 520, 95, 92));
        gradient_2->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 79, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        error_video = new QPushButton(centralWidget);
        error_video->setObjectName(QStringLiteral("error_video"));
        error_video->setGeometry(QRect(120, 40, 400, 400));
        error_video->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0);"));
        error_video_2 = new QPushButton(centralWidget);
        error_video_2->setObjectName(QStringLiteral("error_video_2"));
        error_video_2->setGeometry(QRect(770, 40, 400, 400));
        error_video_2->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0);"));
        gradient_3 = new QLabel(centralWidget);
        gradient_3->setObjectName(QStringLiteral("gradient_3"));
        gradient_3->setGeometry(QRect(10, 630, 191, 61));
        gradient_3->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        auto_drive = new QPushButton(centralWidget);
        auto_drive->setObjectName(QStringLiteral("auto_drive"));
        auto_drive->setGeometry(QRect(440, 510, 194, 174));
        auto_drive->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        shapes_recognize = new QPushButton(centralWidget);
        shapes_recognize->setObjectName(QStringLiteral("shapes_recognize"));
        shapes_recognize->setGeometry(QRect(650, 510, 194, 174));
        shapes_recognize->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        gradient_4 = new QLabel(centralWidget);
        gradient_4->setObjectName(QStringLiteral("gradient_4"));
        gradient_4->setGeometry(QRect(440, 630, 191, 61));
        gradient_4->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        gradient_5 = new QLabel(centralWidget);
        gradient_5->setObjectName(QStringLiteral("gradient_5"));
        gradient_5->setGeometry(QRect(650, 630, 191, 61));
        gradient_5->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        gradient_6 = new QLabel(centralWidget);
        gradient_6->setObjectName(QStringLiteral("gradient_6"));
        gradient_6->setGeometry(QRect(230, 630, 191, 61));
        gradient_6->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        home = new QPushButton(centralWidget);
        home->setObjectName(QStringLiteral("home"));
        home->setGeometry(QRect(230, 510, 194, 174));
        home->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        display_image->raise();
        display_image_2->raise();
        gradient->raise();
        joystick_status->raise();
        gradient_2->raise();
        atMega_status->raise();
        error_video->raise();
        error_video_2->raise();
        gradient_3->raise();
        startVideo->raise();
        gradient_4->raise();
        gradient_5->raise();
        shapes_recognize->raise();
        auto_drive->raise();
        gradient_6->raise();
        home->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        display_image->setText(QString());
        display_image_2->setText(QString());
        startVideo->setText(QApplication::translate("MainWindow", "Start Video", nullptr));
        joystick_status->setText(QString());
        atMega_status->setText(QString());
        gradient->setText(QString());
        gradient_2->setText(QString());
        error_video->setText(QString());
        error_video_2->setText(QString());
        gradient_3->setText(QString());
        auto_drive->setText(QString());
        shapes_recognize->setText(QString());
        gradient_4->setText(QString());
        gradient_5->setText(QString());
        gradient_6->setText(QString());
        home->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
