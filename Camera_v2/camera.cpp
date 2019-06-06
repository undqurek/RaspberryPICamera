#include "camera.h"

Camera::Camera()
{
    this->_camera.setHorizontalFlip(true);
    this->_camera.setVerticalFlip(true);
   // this->_camera.setCaptureSize(1920, 1080);
    this->_camera.setCaptureSize(1280, 960);
    this->_camera.setFormat(raspicam::RASPICAM_FORMAT_RGB);
}

Camera::~Camera()
{
    this->close();
}

bool Camera::isOpened() const
{
    return this->_camera.isOpened();
}

bool Camera::open(uint16_t width, uint16_t height)
{
    this->_camera.setCaptureSize(width, height);

    if(this->_camera.open())
    {
        ::sleep(2*3); // waiting for camera ready

        //this->_camera.setCaptureSize(2592, 1944);
        //this->_camera.setCaptureSize(1920, 1080);
//        this->_camera.setCaptureSize(1280, 960);
//        this->_camera.setFormat(raspicam::RASPICAM_FORMAT_RGB);
//        this->_camera.setHorizontalFlip(true);
//        this->_camera.setVerticalFlip(true);
        //this->_camera.setISO(800);

        return true;
    }

    return false;
}

void Camera::close()
{
    this->_camera.release();
}

uint16_t Camera::getWidth()
{
    return this->_camera.getWidth();
}

uint16_t Camera::getHeight()
{
    return this->_camera.getHeight();
}

bool Camera::capture(uint8_t *data)
{
    if(this->_camera.isOpened() && this->_camera.grab())
    {
        this->_camera.retrieve(data);

        return true;
    }

    return false;
}

uint8_t Camera::getCamerasCount()
{
    return 1;
}

Camera *Camera::getCamera(uint8_t index)
{
    if(index > 1)
        return NULL;

    return new Camera();
}
