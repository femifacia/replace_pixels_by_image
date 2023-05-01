/*
** EPITECH PROJECT, 2023
** replace_pixels_by_image
** File description:
** ImageManager
*/

#include "ImageManager.hpp"

void ImageManager::printTransformedImage(std::string title, int waitTime)
{
    cv::imshow(title, _transformedImage);
    cv::waitKey(waitTime);
}

void ImageManager::createTransformedImage()
{
    int newCols = _imageCols * _sampleCols;
    int newRows = _imageRows * _sampleRows;

    _transformedImage = cv::Mat(cv::Mat::zeros(cv::Size(newCols,newRows),CV_8UC1));
    _transformedImageCols = newCols;
    _transformedImageRows = newRows;
}

cv::Mat ImageManager::getSampleImage()
{
    int index = rand() % _sampleImage.size();

    return _sampleImage[index];
}

void ImageManager::fillTransformedImage(double lightFactor)
{
    cv::Vec3b pixel;
    cv::Vec3b samplePixel;
    cv::Mat sample;
    int nI = 0;
    int nJ = 0;

    std::cout << "init" << std::endl;
    std::cout << _imageCols << std::endl;

    _transformedImage = cv::imread("./transformed.jpg");
    double max_rows = (((double)((_sampleRows * _imageRows))));
    for (int i = 0; i < _imageRows; i++) {
        nI = i * _sampleRows;
        std::cout <<"finished at " << ((double)(nI / max_rows)) * 100<< "%" <<std::endl;
        for (int j = 0; j < _imageCols; j++) {
            pixel = _originalImage.at<cv::Vec3b>(i,j);
            sample = getSampleImage();
            for (int i1 = 0; i1 < sample.rows; i1++,nI++) {
                for (int j1 = 0, nJ = j * _sampleCols; j1 < sample.cols; j1++,nJ++) {
                    samplePixel = sample.at<cv::Vec3b>(i1,j1);
                    samplePixel[0] = samplePixel[0] + (pixel[0] - samplePixel[0]) * lightFactor;
                    samplePixel[1] = samplePixel[1] + (pixel[1] - samplePixel[1]) * lightFactor;
                    samplePixel[2] = samplePixel[2] + (pixel[2] - samplePixel[2]) * lightFactor;
                    //std::cout << "nj " << nJ<<std::endl; 
                    _transformedImage.at<cv::Vec3b>(nI, nJ)[0] = samplePixel[0];
                    _transformedImage.at<cv::Vec3b>(nI, nJ)[1] = samplePixel[1];
                    _transformedImage.at<cv::Vec3b>(nI, nJ)[2] = samplePixel[2];


//                    _transformedImage.at<cv::Vec3b>(nI, nJ)[0] = 25;
//                    _transformedImage.at<cv::Vec3b>(nI, nJ)[1] = 0;
//                    _transformedImage.at<cv::Vec3b>(nI, nJ)[2] = 255;
                }
            }
            nI = i * _sampleRows;
        }
    }
    /*for (int i = 0; i < _transformedImage.rows; i++) {
        for (int j = 0; j < _transformedImage.cols; j++) {
                    _transformedImage.at<cv::Vec3b>(i, j)[0] = 255;
                    _transformedImage.at<cv::Vec3b>(i, j)[1] = 0;
                    _transformedImage.at<cv::Vec3b>(i, j)[2] = 0;
        }
    }*/
    std::cout << "finished at 100%" << std::endl;
}

void ImageManager::replacePixelsByImages(std::string path, double lightFactor)
{
    std::cout << "Let's start the creation of our new image" << std::endl;
    createTransformedImage();
    cv::imwrite(path, _transformedImage);
    fillTransformedImage(lightFactor);
    cv::imwrite(path, _transformedImage);
    std::cout << "It is over" << std::endl;
}

void ImageManager::printSampleImages(int waitTime)
{
    std::string title = "";

    for (int i = 0; i < _sampleImage.size(); i++) {
        title = "image sample Number " + std::to_string(i);
        cv::imshow(title, _sampleImage[i]);
        cv::waitKey(waitTime);
    }
}

void ImageManager::loadSampleImage(std::string path)
{
    cv::Mat image = cv::imread(path);

    cv::resize(image, image, cv::Size(_sampleCols, _sampleRows), cv::INTER_LINEAR);
//    std::cout << "okkkk" << image.rows << " "<< image.cols << std::endl;
    _sampleImage.push_back(image);
}

void ImageManager::printOriginalImage(std::string title, int waitTime)
{
    cv::imshow(title, _originalImage);
    cv::waitKey(waitTime);
}

void ImageManager::loadImage(std::string path)
{
    _originalImage = cv::imread(path);
    cv::resize(_originalImage, _originalImage, cv::Size(_imageCols, _imageCols), cv::INTER_LINEAR);
    _imageCols = _originalImage.cols;
    _imageRows = _originalImage.rows;

    if (_imageRows * _imageCols > _maxImageCols * _maxImageRows)
        throw ImageException("The Image you loaded is too big");

}

ImageManager::ImageManager(int imageRows, int imageCols, int sampleRows, int sampleCols,int maxImageRows, int maxImageCols) : _maxImageRows(maxImageRows),_maxImageCols(maxImageCols),_sampleRows(sampleRows), _sampleCols(sampleCols), _imageCols(imageCols), _imageRows(imageRows)
{
}

ImageManager::~ImageManager()
{
}
