#include "RGB/png.h"
#include "RGB/rgbapixel.h"

#include <string>
#include <cmath>

void rotate(std::string inputFile, std::string outputFile) {
    PNG pic(inputFile);
    
    // get width and height of the image
    int width = pic.width();
    int height = pic.height();

    // new object to hold the new rotated image
    PNG rotatedPic(width, height);

    // Access the pixel data arrays of the original and rotated images
    RGBAPixel* pixels = pic.operator()(0, 0);
    RGBAPixel* rotatedPixels = rotatedPic.operator()(0, 0);

    // row 
    for (int h = 0; h < height; h++) {
        // collumn (each px)
        for (int w = 0; w < width; w++) {
            // get px position of rotated image
            int w_rot = width - w - 1;
            int h_rot = height - h - 1;

            // get  pixel value from the main img
            RGBAPixel* pixel = &pixels[h * width + w];

            // update px of new img
            rotatedPixels[h_rot * width + w_rot] = *pixel;
        }
    }

    // write to out.img
    rotatedPic.writeToFile(outputFile);
}

PNG myArt(unsigned int width, unsigned int height) {
    PNG png(width, height);

    // init img data array 
    RGBAPixel* px = png.operator()(0, 0);

    // horzontal gradient 
    for (unsigned int x = 0; x < width; x++) {
        // 3 intensity of different color 
        int R = x * 255 / width;    // red
        int G = x * 510 / width;    // green
        int B = 255 - x * 255 / width;  // blue

        // make px with the color
        RGBAPixel px_color(R, G, B);

        // set px to the img co ordinate
        for (unsigned int y = 0; y < height; y++) {
            px[y * width + x] = px_color;
        }
    }

    return png;
}
