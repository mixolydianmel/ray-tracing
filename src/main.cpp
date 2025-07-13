#include "color.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

const int IMAGE_WIDTH = 256;
const int IMAGE_HEIGHT = 256;

int main(int argc, char **argv) {
  std::cout << "P3" << std::endl
            << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << std::endl
            << "255" << std::endl;

  for (int row = 0; row < IMAGE_HEIGHT; row++) {
    std::clog << "\rScanlines remaining: " << (IMAGE_HEIGHT - row) << ' '
              << std::flush;

    for (int col = 0; col < IMAGE_WIDTH; col++) {
      auto pixel_color = color(double(col)/(IMAGE_WIDTH-1), double(row)/(IMAGE_HEIGHT-1), 0);
      write_color(std::cout, pixel_color);
    }
  }

  std::clog << "\rDone.                      " << std::endl;

  return EXIT_SUCCESS;
}
