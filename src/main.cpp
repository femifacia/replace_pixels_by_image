#include <opencv2/opencv.hpp>
#include <stdio.h>

#include "ImageException/ImageException.hpp"

int main(int argc, char **argv)
{
	try {
		
	} catch (ImageException exception) {
		std::cerr << exception.what() << std::endl;
	} catch (std::exception exception) {
		std::cerr << exception.what() << std::endl;		
	}
	return (0);
}
