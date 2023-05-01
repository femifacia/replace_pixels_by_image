# replace_pixels_by_image
We create an image from one but with its pixels replaced by other images

## How to build the project ?

### Requirements

* OpenCV on [Linux](https://www.geeksforgeeks.org/how-to-install-opencv-in-c-on-linux/) or [Windows](https://www.tutorialspoint.com/how-to-install-opencv-for-cplusplus-in-windows) (the c++ library)
* g++
* [Cmake](https://cmake.org/install/)

### Build it on linux

You can just exec the
    [build.sh](./build.sh) file by typing this command at the root of the repository

    ./build.sh

The binary **replace_pixel_by_image** will be on the build folder

## How to run the project

    ./build/replace_pixel_by_image -i path_to_image -s sample_images... [options]...

### Arguments and Options

-**i** or **--image** *path* (**required**) : after this flag, specify the path to the image you want to replace its pixels by images. If you want to use a path which start by **-** you have to put before this path **--** flag

**-s** or **--sample** *sample...*  (**required**) : after this flag, specify the path to the images you want to replace the pixels of the main image with. You can use as many images you want. They will randomly be used to constitute your new image. If you want to use a path which start by **-** you have to put before this path **--** flag

Examples

    replace_pixel_by_image -i joconde.jpg -r chicken.jpg ../images/flower.png ./car.png
    replace_pixel_by_image -s fox.png -i dog.png
    replace_pixel_by_image --sample cat.png -i dog.png
    replace_pixel_by_image --sample cat.png --sample -- -my_cat.png -i dog.png (We put -- before an argument which start by -)
    replace_pixel_by_image --sample pong.png -i -- -ball.png (We put -- before an argument which start by -)
    replace_pixel_by_image --image rainbow.png --sample dog.png -s cat.png

**-o** or **--output** *path* (**optional**) : after this flag, specify the name of the output image. If you want to use a path which start by **-** you have to put before this path **--** flag

Examples

    replace_pixel_by_image -o ./my_animal.png -i joconde.jpg -r chicken.jpg ../images/flower.png ./car.png
    replace_pixel_by_image --output ../image/predators.jpeg -s fox.png -i dog.png
    replace_pixel_by_image --sample cat.png -i dog.png -o -- -cute-animal.jpg (We put -- before an argument which start by -)
    replace_pixel_by_image --image rainbow.png --sample dog.png -s cat.png -o ./beatiful.png

**--size-sample** *height* *width* (**optional**) : after this flag, change the height and the width we will use to crop sample images. By default it is set to 100 100

**--size-image** *height* *width* (**optional**) : after this flag, change the height and the width we will use to crop the main image. By default it is set to 150 150
Examples

    replace_pixel_by_image  --size-image 40 50 -o ./my_animal.png -i joconde.jpg -r chicken.jpg ../images/flower.png ./car.png
    replace_pixel_by_image --size-sample 90 90 -o ../image/predators.jpeg --size-image 200 200 -s fox.png -i dog.png
    replace_pixel_by_image --sample cat.png -i dog.png --size-sample 40 40 -o -- -cute-animal.jpg (We put -- before an argument which start by -)
    replace_pixel_by_image -i rainbow.png --size-image 30 30 -s dog.png -s cat.png -o ./beatiful.png
