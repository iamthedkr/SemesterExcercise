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

Complex Add(Complex, Complex);

Complex Sub(Complex, Complex);

Complex Mul(Complex, Complex);

Complex Div(Complex, Complex);

Complex Pow(Complex);

float Modulus(Complex);

Complex SquareRoot(Complex);

void inputComplex(Complex &, Complex &);

void outputComplex(Complex);

void CASE6();

int menu6(int &m6);

#endif //EXERCISES_BAI6_H
