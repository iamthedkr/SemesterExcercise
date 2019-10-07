//
// Created by DKR on 10/2/2019.
//
#include "../include.h"

#ifndef EXERCISES_BAI6_H
#define EXERCISES_BAI6_H

#pragma once

struct Complex {
    float Re; //phần thực - real
    float Im; //phần ảo - imaginary
};

class sophuc {
public:
    void OutputComplex(Complex);

    float Modulus(Complex);

    Complex Add(Complex, Complex);

    Complex Sub(Complex, Complex);

    Complex Mul(Complex, Complex);

    Complex Div(Complex, Complex);

    Complex Square(Complex);

    Complex SquareRoot(Complex);
};

void CASE6();

int menu6(int &m6);

#endif //EXERCISES_BAI6_H
