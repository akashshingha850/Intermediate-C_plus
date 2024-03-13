/**
 * @file rgbapixel.h
 * Definition of the RGBAPixel class for the EasyPNG library.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H

#include <cstdint>

class RGBAPixel
{
public: 
// Declare the valraiables
uint8_t red;
uint8_t green;
uint8_t blue;
uint8_t alpha;

//Declare the Constructor
RGBAPixel();
RGBAPixel(uint8_t _r, uint8_t _g, uint8_t _b);


private:

};

#endif // RGBAPIXEL_H
