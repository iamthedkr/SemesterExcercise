//
// Created by DKR on 10/2/2019.
//
#include "../include.h"

#ifndef EXERCISES_BAI3_H
#define EXERCISES_BAI3_H

class poly {
    double *coef;
    int deg;
public:
    explicit poly(int _deg = 0);

    poly(const poly &);

    poly(int k, double v);

    ~poly() { delete coef; }

    poly &operator=(const poly &);

    friend int operator==(const poly &, const poly &);

    //poly daoham();

    double value(double);

    double &operator[](int k) const { return coef[k]; }

    poly operator*(const poly &) const;

    poly operator/(const poly &) const;

    poly operator%(const poly &) const;

    poly operator+(const poly &) const;

    poly operator-(const poly &) const;

    poly operator-() const;

    poly operator*(double);

    poly operator/(double f) { return (*this) * (1 / f); }

    poly operator+(double f) { return (*this) + poly(0, f); }

    poly operator-(double f) { return (*this) - poly(0, f); }

    friend poly operator*(double f, poly a) { return a * f; }

    friend poly operator+(double f, poly a) { return a + f; }

    friend poly operator-(double f, poly a) { return -a + f; }

    friend ostream &operator<<(ostream &, const poly &);

    friend istream &operator>>(istream &, poly &);

    void set(int m, const double v[]);

};

void CASE3();

int menu3(int &m3);

#endif //EXERCISES_BAI3_H
