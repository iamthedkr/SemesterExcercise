//
// Created by DKR on 10/2/2019.
//
#include "../include.h"

#ifndef EXERCISES_BAI6_H
#define EXERCISES_BAI6_H

#pragma once

typedef struct tagcomplex {
    float thuc, ao;
} Complex;

class SOPHUC {
public:

    static Complex Add(Complex, Complex);

    static Complex Sub(Complex, Complex);

    static Complex Mul(Complex, Complex);

    static Complex Div(Complex, Complex);

    static Complex Pow(Complex);

    static float Modulus(Complex);

    static Complex SquareRoot(Complex);

    static void inputComplex(Complex &, Complex &);

    static void outputComplex(Complex);
};

void CASE6();

int menu6(int &m6);

#endif //EXERCISES_BAI6_H
