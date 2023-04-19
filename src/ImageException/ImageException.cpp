/*
** EPITECH PROJECT, 2023
** replace_pixels_by_image
** File description:
** ImageException
*/

#include "ImageException.hpp"

ImageException::ImageException(std::string message)
{
    _message = message;
}

ImageException::~ImageException()
{
}

std::string ImageException::what()
{
    return _message;
}