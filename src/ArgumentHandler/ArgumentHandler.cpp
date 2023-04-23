/*
** EPITECH PROJECT, 2023
** replace_pixels_by_image
** File description:
** ArgumentHandler
*/

#include "ArgumentHandler.hpp"

void ArgumentHandler::printHelp(char **argv, int &index)
{
    std::cout << "------This is the help section------" << std::endl << std::endl;

    std::cout << "This command replace pixels of an image by others images" << std::endl;
    std::cout << "Usage" << std::endl;
    std::cout << "\treplace_pixel_by_image -i path_to_image -s sample_images... [options]..." << std::endl << std::endl;
    std::cout << "Arguments and Options" << std::endl << std::endl;
    std::cout << _green <<"-i "<< _red <<"[required]" << _white<< "\t:\tafter this flag, specify the path to the image you want to replace its pixels by images" << std::endl << std::endl;
    std::cout << _green <<"-s "<< _red <<"[required]" << _white<< "\t:\tafter this flag, specify the path to the images you want to replace the pixels of the main image with.";
    std::cout << " You can use as many images you want. They will randomly be used to constitute your new image"<< std::endl << std::endl;
    std::cout << "Examples" << std::endl << std::endl;
    std::cout << "\treplace_pixel_by_image -i joconde.jpg -r chicken.jpg ../images/flower.png ./car.png" << std::endl;
    std::cout << "\treplace_pixel_by_image -r fox.png -i dog.png" << std::endl << std::endl;
    std::cout << _green <<"-o "<< _yellow <<"[optional]" << _white<< "\t:\tafter this flag, specify the name of the output image" << std::endl << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    while (argv[index])
       index++;
}

void ArgumentHandler::manageArguments(char **argv, int start)
{
    void (ArgumentHandler::*ptr)(char **, int &);

    while (argv[start]) {
//        (this->*(_functionMap[argv[start]]))(argv, start);
        ptr = (_functionMap[argv[start]]);
        if (ptr)
            (this->*ptr)(argv, start);
        else {
            throw ImageException(std::string("unknown argument \033[01;91m") + std::string(argv[start]) + std::string("\033[00m"));
        }
    }
}

ArgumentHandler::ArgumentHandler()
{
    _white = "\033[00m";
    _green = "\033[01;92m";
    _red = "\033[01;91m";
    _yellow = "\033[01;93m";
    _blue = "\033[01;91m";
    _functionMap["-h"] = &ArgumentHandler::printHelp;
    _functionMap["--help"] = &ArgumentHandler::printHelp;
}

ArgumentHandler::~ArgumentHandler()
{
}
