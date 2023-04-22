/*
** EPITECH PROJECT, 2023
** replace_pixels_by_image
** File description:
** ArgumentHandler
*/

#include "ArgumentHandler.hpp"

void ArgumentHandler::printHelp(char **argv, int &index)
{
    std::cout << "help nigga" << std::endl;
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
    _functionMap["-h"] = &ArgumentHandler::printHelp;
    _functionMap["--help"] = &ArgumentHandler::printHelp;
}

ArgumentHandler::~ArgumentHandler()
{
}
