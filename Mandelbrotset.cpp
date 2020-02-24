#pragma once
#include </home/david/Schreibtisch/C++ /Exercise/Image/Imag.h>
#include <complex>

template <class T>
void draw_Mandelbrot(T & image, const int w, const int h, double xmin, double xmax, double ymin, double ymax, int n_max) {

    for (int kx = 0; kx < w; kx++)
        for (int ky = 0; ky < h; ky++)
        {
            complex<double> c(xmin + kx / (w - 0.5)*(xmax - xmin),ymin + ky /  (h - 0.5)*(ymax - ymin));
            complex<double> z = 0;
            int n;

            for (n = 0; n < n_max && abs(z) < 2.0; n++)
                 z = z*z + c;
            image[ky][kx].r =  n*2;
            image[ky][kx].b = n*3;
            image[ky][kx].g = 2*log(n);

        }
}
int main(){
const int w = 2500;
const int h = 2200;

    Matrix<RGB<unsigned char>>image(h,w);

    draw_Mandelbrot(image, w, h, -1.9, 0.6, -1.1, 1.1, 1024);

    ofstream out("Mandelbrot2.pgm",ios::binary);
    out << image;
    return 0;
}
