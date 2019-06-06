#include <iostream>
#include <stdio.h>

#include "camera.h"

inline void setPixel(uint8_t *data, uint8_t r, uint8_t g, uint8_t b, uint16_t width, uint16_t y, uint16_t x)
{
    uint8_t *p = data + y*width*3 + x*3;
    p[0] = b;
    p[1] = g;
    p[2] = r;
}

inline void drawCross(uint8_t *data, uint16_t width, uint16_t height)
{
    uint16_t x0 = width/2;
    uint16_t y0 = height/2;
    for (uint16_t i = 0; i < width; ++i)
    {
        setPixel(data, 255, 255, 255, width, y0, i);
    }
    for (uint16_t i = 0; i < height; ++i)
    {
        setPixel(data, 255, 255, 255, width, i, x0);
    }
}

int main()
{
    uint8_t camerasCount = Camera::getCamerasCount();

    if(camerasCount == 0)
        return 0;

    Camera *camera = Camera::getCamera(0);

    if(camera->open(1920, 1080))
    {
        uint16_t width = camera->getWidth();
        uint16_t height = camera->getHeight();

        uint32_t size = width * height * 3;
        uint8_t *data = new uint8_t[size];

        if(camera->capture(data))
        {
            drawCross(data, width, height);
            std::cout << "OK";

            FILE *file = fopen("image_1080.ppm", "w");

            if(file != NULL)
            {
                fprintf(file, "P6\n%d %d 255\n", width, height); // writing raw file header
                fwrite((char *)data, 1, size, file);
                fclose(file);
            }
        }
        else
        {
            std::cout << "ERROR";
        }

        std::cout.flush();

        delete [] data;
        camera->close();
    }

    if(camera->open(1280, 960))
    {
        uint16_t width = camera->getWidth();
        uint16_t height = camera->getHeight();

        uint32_t size = width * height * 3;
        uint8_t *data = new uint8_t[size];

        if(camera->capture(data))
        {
            drawCross(data, width, height);
            std::cout << "OK";

            FILE *file = fopen("image_960.ppm", "w");

            if(file != NULL)
            {
                fprintf(file, "P6\n%d %d 255\n", width, height); // writing raw file header
                fwrite((char *)data, 1, size, file);
                fclose(file);
            }
        }
        else
        {
            std::cout << "ERROR";
        }

        std::cout.flush();

        delete [] data;
        camera->close();

    }
}
