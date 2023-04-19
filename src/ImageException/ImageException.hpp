/*
** EPITECH PROJECT, 2023
** replace_pixels_by_image
** File description:
** ImageException
*/

#ifndef IMAGEEXCEPTION_HPP_
#define IMAGEEXCEPTION_HPP_

#include <iostream>
#include <exception>

class ImageException : public std::exception {
    public:
        ImageException(std::string message="An error occured");
        ~ImageException();

        std::string what();


    protected:
        std::string _message;
    private:
};

#endif /* !IMAGEEXCEPTION_HPP_ */
