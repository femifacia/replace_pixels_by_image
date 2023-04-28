/*
** EPITECH PROJECT, 2023
** replace_pixels_by_image
** File description:
** ArgumentHandler
*/

#include "ArgumentHandler.hpp"


void ArgumentHandler::setSamplesImages(char **argv, int &index)
{
    bool isFullNameEnabled = false;
    index += 1;
    if (argv[index] && std::string(argv[index]) == "--") {
        index += 1;
//        std::cout <<"jjjj";
        isFullNameEnabled = true;
    }
    std::string arg = (argv[index]) ? argv[index] : "";
//    arg = argv[index];
    if (argv[index] == NULL || (_functionMap.count(arg) && !isFullNameEnabled)) {
        std::cout << "After typing " << _cyan << "-s" << _white <<" or " << _cyan;
        std::cout <<"--sample" << _white << " you have to put the path to the new output" << std::endl << std::endl;
        throw ImageException("Bad flag manipulation");
    }
    while (argv[index] && !(_functionMap.count(arg) && !isFullNameEnabled)) {
        arg = (argv[index]) ? argv[index] : "";
        if (argv[index] == std::string("--")) {
            index += 1;
            isFullNameEnabled = true;
            continue;
        }
        if (arg[0] == '-' && !isFullNameEnabled) {
            std::cout << "If you want to use a path which start by " << _yellow <<"-" << _white;
            std::cout <<" you have to put before this path " << _yellow <<"--" << _white << " flag"<<std::endl;

            std::cout << "Your command would have been" << std::endl;
            std::cout << "\t";
            for (int i = 0; argv[i]; i++) {
                if (i == index)
                    std::cout << _green << "-- "<< _white;
                std::cout << argv[i];
                if (argv[i + 1])
                    std::cout << " ";
            }
            std::cout << std::endl << std::endl;
            throw ImageException(std::string("unknown argument \033[01;91m") + arg + std::string("\033[00m"));
            }
        _sampleImages.push_back(arg);
        index+=1;
        isFullNameEnabled = false;
    }
}

void ArgumentHandler::setImagePath(char **argv, int &index)
{
    bool isFullNameEnabled = false;
    index += 1;
    if (argv[index] && std::string(argv[index]) == "--") {
        index += 1;
//        std::cout <<"jjjj";
        isFullNameEnabled = true;
    }
    std::string arg = (argv[index]) ? argv[index] : "";
//    arg = argv[index];
    if (argv[index] == NULL || (_functionMap.count(arg) && !isFullNameEnabled)) {
        std::cout << "After typing " << _cyan << "-i" << _white <<" or " << _cyan;
        std::cout <<"--image" << _white << " you have to put the path to the new output" << std::endl << std::endl;
        throw ImageException("Bad flag manipulation");
    }
    if (arg[0] == '-' && !isFullNameEnabled) {
        std::cout << "If you want to use a path which start by " << _yellow <<"-" << _white;
        std::cout <<" you have to put before this path " << _yellow <<"--" << _white << " flag"<<std::endl;

        std::cout << "Your command would have been" << std::endl;
        std::cout << "\t";
        for (int i = 0; argv[i]; i++) {
            if (i == index)
                std::cout << _green << "-- "<< _white;
            std::cout << argv[i];
            if (argv[i + 1])
                std::cout << " ";
        }
        std::cout << std::endl << std::endl;
        throw ImageException(std::string("unknown argument \033[01;91m") + arg + std::string("\033[00m"));
    }
    _pathToImage = arg;
    index+=1;
}

void ArgumentHandler::printParameterSummary()
{
    int size = _sampleImages.size();
    std::cout << "The Image:\t" << _blue << _pathToImage << _white <<std::endl;
    std::cout << "Sample Images:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout  << "\t-> " << _blue <<_sampleImages[i] << _white << std::endl;
    }
    if (!size)
        std::cout  << std::endl;
    std::cout << "Path of the new Image:\t" << _blue << _output << _white <<std::endl;
}

void ArgumentHandler::changeOutput(char **argv, int &index)
{
    bool isFullNameEnabled = false;
    index += 1;
    if (argv[index] && std::string(argv[index]) == "--") {
        index += 1;
//        std::cout <<"jjjj";
        isFullNameEnabled = true;
    }
    std::string arg = (argv[index]) ? argv[index] : "";
//    arg = argv[index];
    if (argv[index] == NULL || (_functionMap.count(arg) && !isFullNameEnabled)) {
        std::cout << "After typing " << _cyan << "-o" << _white <<" or " << _cyan;
        std::cout <<"--output" << _white << " you have to put the path to the new output" << std::endl << std::endl;
        throw ImageException("Bad flag manipulation");
    }
    if (arg[0] == '-' && !isFullNameEnabled) {
        std::cout << "If you want to use a path which start by " << _yellow <<"-" << _white;
        std::cout <<" you have to put before this path " << _yellow <<"--" << _white << " flag"<<std::endl;

        std::cout << "Your command would have been" << std::endl;
        std::cout << "\t";
        for (int i = 0; argv[i]; i++) {
            if (i == index)
                std::cout << _green << "-- "<< _white;
            std::cout << argv[i];
            if (argv[i + 1])
                std::cout << " ";
        }
        std::cout << std::endl << std::endl;
        throw ImageException(std::string("unknown argument \033[01;91m") + arg + std::string("\033[00m"));
    }
    _output = arg;
    index+=1;
}

void ArgumentHandler::printHelp(char **argv, int &index)
{
    std::cout << "------This is the help section------" << std::endl << std::endl;

    std::cout << "This command replace pixels of an image by others images" << std::endl;
    std::cout << "Usage" << std::endl;
    std::cout << "\treplace_pixel_by_image -i path_to_image -s sample_images... [options]..." << std::endl << std::endl;
    std::cout << "Arguments and Options" << std::endl << std::endl;
    std::cout << _green <<"-i "<< _red <<"[required]" << _white<< "\t:\tafter this flag, specify the path to the image you want to replace its pixels by images. ";
    std::cout << "If you want to use a path which start by " << _yellow <<"-" << _white;
    std::cout <<" you have to put before this path " << _yellow <<"--" << _white << " flag"<<std::endl;
    std::cout << std::endl << std::endl;
    std::cout << _green <<"-s "<< _red <<"[required]" << _white<< "\t:\tafter this flag, specify the path to the images you want to replace the pixels of the main image with.";
    std::cout << " You can use as many images you want. They will randomly be used to constitute your new image. ";
    std::cout << "If you want to use a path which start by " << _yellow <<"-" << _white;
    std::cout <<" you have to put before this path " << _yellow <<"--" << _white << " flag"<<std::endl;
    std::cout<< std::endl << std::endl;
    std::cout << "Examples" << std::endl << std::endl;
    std::cout << "\treplace_pixel_by_image -i joconde.jpg -r chicken.jpg ../images/flower.png ./car.png" << std::endl;
    std::cout << "\treplace_pixel_by_image -r fox.png -i dog.png" << std::endl << std::endl;
    std::cout << _green <<"-o "<< _white << "or "<< _green<< "--output " <<_yellow <<"[optional]" << _white<< "\t:\tafter this flag, specify the name of the output image. ";
    std::cout << "If you want to use a path which start by " << _yellow <<"-" << _white;
    std::cout <<" you have to put before this path " << _yellow <<"--" << _white << " flag"<<std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    exit(0);
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
    _blue = "\033[01;94m";
    _cyan = "\033[01;96m";

    _pathToImage = "";
    _output = "./transformed.png";

    _functionMap["-h"] = &ArgumentHandler::printHelp;
    _functionMap["--help"] = &ArgumentHandler::printHelp;
    _functionMap["-o"] = &ArgumentHandler::changeOutput;
    _functionMap["--output"] = &ArgumentHandler::changeOutput;
    _functionMap["-i"] = &ArgumentHandler::setImagePath;
    _functionMap["--image"] = &ArgumentHandler::setImagePath;
    _functionMap["-s"] = &ArgumentHandler::setSamplesImages;
}

ArgumentHandler::~ArgumentHandler()
{
}
