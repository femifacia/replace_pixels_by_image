/*
** EPITECH PROJECT, 2023
** replace_pixels_by_image
** File description:
** ImageManager
*/

#ifndef IMAGEMANAGER_HPP_
#define IMAGEMANAGER_HPP_ 5

#include <opencv2/opencv.hpp>

class ImageManager {
    public:
        ImageManager(int maxImageRows, int maxImageCols, int sampleRows = 50, int sampleCols = 50);
        ~ImageManager();

    protected:
    private:
        const int _maxImageRows;
        const int _maxImageCols;
        const int _sampleRows;
        const int _sampleCols;

        cv::Mat _originalImage;
        cv::Mat _transformedImage;
};

#endif /* !IMAGEMANAGER_HPP_ */
