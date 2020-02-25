#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

template<class T>  struct RGB { T r, g, b; };

template<class T>

class Matrix{

public:

vector<T> data;
size_t Zeilen;
size_t Spalten;

class proxy {
        Matrix &m;
        size_t index_1;
    public:
        proxy(Matrix &m, size_t index_1) : m(m), index_1(index_1) { }

        T &operator[](size_t index) {return m.data[index * m.Zeilen + index_1]; }
    };

 class const_proxy {
        Matrix const &m;
        size_t index_1;
    public:
        const_proxy(Matrix const &m, size_t index_1) : m(m), index_1(index_1) { }

        T const &operator[](size_t index) const { return m.data[index * m.Zeilen + index_1]; }
    };

    public:
    Matrix(size_t Zeilen, size_t Spalten) : data(Zeilen * Spalten), Zeilen(Zeilen), Spalten(Spalten) { }

    proxy operator[](size_t index) { return proxy(*this, index); }
    const_proxy operator[](size_t index) const { return const_proxy(*this, index); }

};


template<class T>
ostream &operator<<(ostream &out, Matrix<T> const &m) {
    out << "P6" << endl << m.Spalten << " " << m.Zeilen << endl << 255 << endl;
    for (size_t y = 0; y < m.Zeilen; y++)
        for (size_t x = 0; x < m.Spalten; x++) {
            T pixel = m[y][x];
            out << pixel.r << pixel.g << pixel.b;
        }
    return out;
}

