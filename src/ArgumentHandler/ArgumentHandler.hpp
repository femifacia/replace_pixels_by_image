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
#include <vector>
#include <string.h>

class ArgumentHandler {
    public:


        /**
         * @brief Print Parameter Summary
         * 
         * 
         */

        void printParameterSummary(void);



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

        /**
         * @brief return true if the arg is a number, otherwise false
         * 
         * @param arg 
         * @return true 
         * @return false 
         */
        bool isNumber(std::string arg);

        /**
         * @brief change the output
         * 
         * @param argv arguments
         * @param index of argument
         */

        void setSampleSize(char **argv, int &index);


        /**
         * @brief change the output
         * 
         * @param argv arguments
         * @param index of argument
         */

        void setImageSize(char **argv, int &index);

        /**
         * @brief change the output
         * 
         * @param argv arguments
         * @param index of argument
         */

        void setSamplesImages(char **argv, int &index);

        /**
         * @brief change the output
         * 
         * @param argv arguments
         * @param index of argument
         */

        void changeOutput(char **argv, int &index);

        /**
         * @brief load the main image
         * 
         * @param argv the arguments
         * @param index the index of arguments
         */

        void setImagePath(char **argv, int & index);

        std::string _pathToImage;

        std::vector<std::string> _sampleImages;

        std::string _output;

        /**
         * @brief a Map which associate to a string a pointer on a function of this class
         * 
         */
        std::unordered_map<std::string, void (ArgumentHandler::*)(char **, int &)> _functionMap;

        /**
         * @brief green Color Code
         * 
         */
        std::string _green;
        /**
         * @brief blue color code
         * 
         */
        std::string _blue;
        /**
         * @brief red color code
         * 
         */
        std::string _red;
        /**
         * @brief yellow color code
         * 
         */
        std::string _yellow;
        /**
         * @brief white color code
         * 
         */
        std::string _white;

        /**
         * @brief cyan color code
         * 
         */

        std::string _cyan;

        int _imageWidth;
        int _imageHeight;
        int _sampleWidth;
        int _sampleHeight;

};

#endif /* !ARGUMENTHANDLER_HPP_ */
