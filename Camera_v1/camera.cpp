#include <ctime>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>

using namespace std;
using namespace raspicam;

int main ( int argc,char **argv ) 
{
	RaspiCam camera;
	cout << "Opening Camera..." << endl;

	if (!camera.open()) 
	{
		cerr << "Error opening camera" << endl;
		return -1;
	}

	sleep(3);

	int imageSize = camera.getImageTypeSize(RASPICAM_FORMAT_RGB);
	unsigned char *data=new unsigned char[imageSize];

	camera.grab();
	camera.retrieve(data, RASPICAM_FORMAT_IGNORE);

    	std::ofstream file("raspicam_image.ppm", std::ios::binary);
    	file << "P6\n" << camera.getWidth() << " " << camera.getHeight() << " 255\n";
    	file.write((char*)data, imageSize);

	cout << "Image saved at raspicam_image.ppm" << endl;

	delete [] data;
	return 0;
}
