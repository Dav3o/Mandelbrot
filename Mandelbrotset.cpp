#pragma once
#include </home/david/Schreibtisch/C++ /Exercise/Image/Imag.h>
#include </home/david/Schreibtisch/C++ /Exercise/Complex_lib/Complex_numbers.h>

template <class T>
void draw_Mandelbrot(T & image, const int& w, const int& h,const double xmin,const double xmax,const double ymin,const double ymax,const int n_max) {

    const double xdif = xmax-xmin;
    const double& xdifr = xdif;
    const double ydif = ymax - ymin;
    const double& ydifr = ydif;
    const double& xminr = xmin;
    const double yminr = ymin;

    for (int kx = 0; kx < w; kx++)
        for (int ky = 0; ky < h; ky++)
        {
            int& kxr = kx;
            int& kyr = ky;
            complex_<double> c(xminr + kxr / (w - 0.5)*(xdifr),yminr + kyr /  (h - 0.5)*(ydifr));
            complex_<double> z(0,0);
            int n;

            for (n = 0; n < n_max && z.abs_() < 2.0; n++)
                 z = z*z + c;
            image[kyr][kxr].r =  n;
            image[kyr][kxr].b = n*3;
            image[kyr][kxr].g = 2*log(n);

        }
}
int main(){
const int w = 2000;
const int h = 2000;
const int& wp = w;
const int& hp = h;


    Matrix<RGB<unsigned char>>image(hp,wp);

    draw_Mandelbrot(image, wp, hp, -1.9, 0.6, -1.1, 1.1, 1024);

    ofstream out("Mandelbrot2.ppm",ios::binary);
    out << image;
    return 0;
}
