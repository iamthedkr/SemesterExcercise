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

    static float Modulus(Complex);

    static Complex Add(Complex, Complex);

    static Complex Sub(Complex, Complex);

    static Complex Mul(Complex, Complex);

    static Complex Div(Complex, Complex);

    static Complex Square(Complex);

    static Complex SquareRoot(Complex);

    static void OutputComplex(Complex);

};

void CASE6();

int menu6(int &m6);

#endif //EXERCISES_BAI6_H
