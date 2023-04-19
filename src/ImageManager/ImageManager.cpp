/*
** EPITECH PROJECT, 2023
** replace_pixels_by_image
** File description:
** ImageManager
*/

#include "ImageManager.hpp"

void ImageManager::printOriginalImage(std::string title, int waitTime)
{
    cv::imshow(title, _originalImage);
    cv::waitKey(waitTime);
}

void ImageManager::loadImage(std::string path)
{
    _originalImage = cv::imread(path);
    _imageCols = _originalImage.cols;
    _imageRows = _originalImage.rows;

    if (_imageRows * _imageCols > _maxImageCols * _maxImageRows)
        throw ImageException("The Image you loaded is too big");

}

ImageManager::ImageManager(int maxImageRows, int maxImageCols, int sampleRows, int sampleCols) : _maxImageRows(maxImageRows),_maxImageCols(maxImageCols),_sampleRows(sampleRows), _sampleCols(sampleCols)
{
}

ImageManager::~ImageManager()
{
}
