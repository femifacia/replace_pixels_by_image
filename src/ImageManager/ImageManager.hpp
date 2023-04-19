/*
** EPITECH PROJECT, 2023
** replace_pixels_by_image
** File description:
** ImageManager
*/

#ifndef IMAGEMANAGER_HPP_
#define IMAGEMANAGER_HPP_ 5

#include <opencv2/opencv.hpp>
#include <vector>
#include "../ImageException/ImageException.hpp"

class ImageManager {
    public:

        /**
         * @brief Print each Sample Image
         * 
         * @param waitTime the time to wait before skipping if no touches are pressed
         * It is set to 0 by default
         * If it is set to 0 the program will wait indefinitely untill a touch would be pressed
         */

        void printSampleImages(int waitTime = 0);

        /**
         * @brief Load an image and add it into our sample image vector
         * 
         * @param path the path to the vector image
         */

        void loadSampleImage(std::string path);

        /**
         * @brief Print our Original Image
         *
         * @param title the title of our screen
         *  
         * @param waitTime the time to wait before skipping if no touches are pressed
         * It is set to 0 by default
         * If it is set to 0 the program will wait indefinitely untill a touch would be pressed
         */

        void printOriginalImage(std::string title = "Original Image", int waitTime = 0);

        /**
         * @brief Load an Image from a path
         * This image will be our OriginalImage
         * 
         * @param path
         * The path to the image
         */
        void loadImage(std::string path);

        /**
         * @brief Construct a new Image Manager object
         * 
         * @param maxImageRows the Max rows of Pixels for our image
         * @param maxImageCols the Max column of Pixels for our image
         * @param sampleRows Number of Rows for sample images
         * @param sampleCols Number of Columns for sample images
         */

        ImageManager(int maxImageRows, int maxImageCols, int sampleRows = 50, int sampleCols = 50);

        /**
         * @brief Destroy the Image Manager object
         * 
         */

        ~ImageManager();


    protected:

    private:
        /**
         * @brief The max Rows for out image
         * 
         */
        const int _maxImageRows;
        /**
         * @brief the max Columns for our image
         * 
         */
        const int _maxImageCols;
        /**
         * @brief The number of rows for sample images
         * 
         */
        const int _sampleRows;
        /**
         * @brief The number of columns for our sample images
         * 
         */
        const int _sampleCols;

        /**
         * @brief the number of rows of our image
         * 
         */
        int _imageRows;

        /**
         * @brief The number of columns of our image
         * 
         */
        int _imageCols;

        /**
         * @brief The matrix representation of our original Image
         * 
         */
        cv::Mat _originalImage;

        /**
         * @brief The matrix representation of our transformed image
         * 
         */
        cv::Mat _transformedImage;

        /**
         * @brief The vector containing sample images
         * 
         */

        std::vector<cv::Mat> _sampleImage;
};

#endif /* !IMAGEMANAGER_HPP_ */
