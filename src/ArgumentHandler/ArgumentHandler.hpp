/*
** EPITECH PROJECT, 2023
** replace_pixels_by_image
** File description:
** ArgumentHandler
*/

#ifndef ARGUMENTHANDLER_HPP_
#define ARGUMENTHANDLER_HPP_ 5

#include "../ImageManager/ImageManager.hpp"
#include "../ImageException/ImageException.hpp"
#include <unordered_map>

class ArgumentHandler {
    public:

        /**
         * @brief Manage arguments and option recieved by the program 
         * 
         * @param argv the list of args
         * @param start the start index for argument handling
         */

        void manageArguments(char **argv, int start);

        /**
         * @brief print the help associated to the project
         * 
         * @param argv arguments
         * @param index of argument
         */

        void printHelp(char **argv, int & index);

        ArgumentHandler();
        ~ArgumentHandler();

    protected:
    private:
        std::unordered_map<std::string, void (ArgumentHandler::*)(char **, int &)> _functionMap;

        std::string _green;
        std::string _blue;
        std::string _red;
        std::string _yellow;
        std::string _white;

};

#endif /* !ARGUMENTHANDLER_HPP_ */
