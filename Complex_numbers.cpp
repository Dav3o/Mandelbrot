#include <iostream>
#include <cmath>

using namespace std;

template <class T>

class complex_{

public:

T Re_z;
T Im_z;

complex_(T Re_z,T Im_z): Re_z(Re_z), Im_z(Im_z) {}

complex_ Conj(){
    return complex_((*this).Re_z,((*this).Im_z)*(-1));
}

complex_ operator+(complex_& other){
    return complex_((*this).Re_z + other.Re_z, (*this).Im_z + other.Im_z);
}

complex_ operator-(complex_& other){
     return complex_((*this).Re_z - other.Re_z, (*this).Im_z - other.Im_z);
}

complex_ operator*(complex_& other){
     return complex_(((*this).Re_z)*(other.Re_z)-((*this).Im_z)*(other.Im_z),((*this).Re_z)*(other.Im_z)+((*this).Im_z)*(other.Re_z));
}
complex_ operator/(complex_& other){
     T Denominater = other.Re_z*other.Re_z + other.Im_z*other.Im_z;
     return complex_(((*this).Re_z*other.Re_z + (*this).Im_z*other.Im_z)/(Denominater),((*this).Im_z*other.Re_z - (*this).Re_z*other.Im_z)/(Denominater));
}

double abs_(){
    return sqrt((*this).Re_z*(*this).Re_z+(*this).Im_z*(*this).Im_z);
}

T real(){
      return (*this).Re_z;
}

T imag(){
      return (*this).Im_z;
}

};


