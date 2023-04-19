#include <opencv2/opencv.hpp>
#include <stdio.h>

#include "ImageException/ImageException.hpp"
#include "ImageManager/ImageManager.hpp"

int main(int argc, char **argv)
{
	try {
		ImageManager imageManager(700,700);
		imageManager.loadImage(argv[1]);
		imageManager.printOriginalImage();

	} catch (ImageException exception) {
		std::cerr << exception.what() << std::endl;
	} catch (std::exception exception) {
		std::cerr << exception.what() << std::endl;		
	}
	return (0);
}
