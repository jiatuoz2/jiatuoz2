#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>
#include <cmath>
#include <iostream>

using namespace cs225;

void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  PNG png;
  png.readFromFile(inputFile);
  PNG png2(png);
  for (unsigned x = 0; x < png.width(); ++x) {
    for (unsigned y = 0; y < png.height(); ++y) {
      png2.getPixel(png.width() - 1 - x, png.height() - 1 - y) = png.getPixel(x, y);
    }
  }
  png2.writeToFile(outputFile);
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  unsigned centerX = png.width() / 2;
  unsigned centerY = png.height() / 2;
  for (unsigned x = 0; x < png.width(); ++x) {
    for (unsigned y = 0; y < png.height(); ++y) {
      int distance = sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
      // std::cout << pow(x - centerX, 2) << " " << pow(y - centerY, 2) << std::endl;
      HSLAPixel& pixel = png.getPixel(x, y);
      pixel.h = distance % 360;
      pixel.l = 0.5;
      pixel.s = 1;
      pixel.a = 1;
    }
  }
  return png;
}
