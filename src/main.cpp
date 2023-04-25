#include <opencv2/opencv.hpp>
#include <stdio.h>

#include "ImageException/ImageException.hpp"
#include "ImageManager/ImageManager.hpp"
#include "ArgumentHandler/ArgumentHandler.hpp"

int main(int argc, char **argv)
{
	try {
		ArgumentHandler argHandler;
		argHandler.manageArguments(argv, 1);
		argHandler.printParameterSummary();
//		ImageManager imageManager(700,700);
//		imageManager.loadImage(argv[1]);
// not		imageManager.printOriginalImage();
//		for (int i = 2; i < argc; i++) {
//			imageManager.loadSampleImage(argv[i]);
//		}
// not		imageManager.printSampleImages();
//		imageManager.replacePixelsByImages();
//	not	imageManager.printTransformedImage();
		return 0;
	} catch (ImageException exception) {
		std::cerr << exception.what() << std::endl;
	} catch (std::exception exception) {
		std::cerr << exception.what() << std::endl;
	}
	return (1);
}
