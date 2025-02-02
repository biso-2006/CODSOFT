#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat originalImage, processedImage;
int brightness = 50, contrast = 50;

void applyFilters(int, void*) {
    Mat newImage;
    double alpha = contrast / 50.0;
    int beta = brightness - 50;
    originalImage.convertTo(newImage, -1, alpha, beta);
    processedImage = newImage;
    imshow("Image Processing Tool", processedImage);
}

void grayscale(int state, void*) {
    if (state) {
        cvtColor(originalImage, processedImage, COLOR_BGR2GRAY);
        imshow("Image Processing Tool", processedImage);
    } else {
        processedImage = originalImage.clone();
        imshow("Image Processing Tool", processedImage);
    }
}

void blurImage(int state, void*) {
    if (state) {
        GaussianBlur(originalImage, processedImage, Size(15, 15), 0);
        imshow("Image Processing Tool", processedImage);
    } else {
        processedImage = originalImage.clone();
        imshow("Image Processing Tool", processedImage);
    }
}

void saveImage(int, void*) {
    imwrite("processed_image.jpg", processedImage);
    cout << "Image saved as processed_image.jpg\n";
}

int main() {
    string imagePath;
    cout << "Enter the path to the image: ";
    cin >> imagePath;

    originalImage = imread(imagePath);
    if (originalImage.empty()) {
        cerr << "Error: Could not load image!\n";
        return -1;
    }
    processedImage = originalImage.clone();
    
    namedWindow("Image Processing Tool", WINDOW_AUTOSIZE);
    imshow("Image Processing Tool", originalImage);

    createTrackbar("Brightness", "Image Processing Tool", &brightness, 100, applyFilters);
    createTrackbar("Contrast", "Image Processing Tool", &contrast, 100, applyFilters);
    
    int grayscaleState = 0, blurState = 0;
    createButton("Grayscale", grayscale, &grayscaleState, QT_PUSH_BUTTON, false);
    createButton("Blur", blurImage, &blurState, QT_PUSH_BUTTON, false);
    createButton("Save Image", saveImage, NULL, QT_PUSH_BUTTON, false);
    
    waitKey(0);
    return 0;
}
