# replace_pixels_by_image
We create an image from one but with its pixels replaced by other images

## How to build the project ?

### Requirements

* OpenCV on [Linux](https://www.geeksforgeeks.org/how-to-install-opencv-in-c-on-linux/) or [Windows](https://www.tutorialspoint.com/how-to-install-opencv-for-cplusplus-in-windows) (the c++ library)
* g++
* [Cmake](https://cmake.org/install/)

### Build it on linux

You can just exec the
    [build.sh](./build.sh) file

The binary **replace_pixel_by_image** will be on the build folder

## How to run the project

    ./build/replace_pixel_by_image -i path_to_image -s sample_images... [options]...

### Arguments and Options

-i (**required**) : after this flag, specify the path to the image you want to replace its pixels by images

-s (**required**) : after this flag, specify the path to the images you want to replace the pixels of the main image with. You can use as many images you want. They will randomly be used to constitute your new image

Examples

    replace_pixel_by_image -i joconde.jpg -r chicken.jpg ../images/flower.png ./car.png
    replace_pixel_by_image -r fox.png -i dog.png

-o (**optional**) : after this flag, specify the name of the output image
