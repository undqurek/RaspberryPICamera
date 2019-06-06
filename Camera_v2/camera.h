#ifndef CAMERA_H
#define CAMERA_H

#include <stddef.h>
#include <stdint.h>
#include <raspicam/raspicam.h>


class Camera
{
private:
    raspicam::RaspiCam _camera;

public:
    Camera();
    virtual ~Camera();

    bool isOpened() const;

    bool open(uint16_t width = 1920, uint16_t height = 1080);
    void close();

    uint16_t getWidth();
    uint16_t getHeight();


    bool capture(uint8_t *data);

    static uint8_t getCamerasCount();
    static Camera *getCamera(uint8_t index);
};

#endif // CAMERA_H
