//
// Created by DKR on 10/6/2019.
//
#include "../include.h"

#ifndef EXERCISES_BAI5_H
#define EXERCISES_BAI5_H

class DaThuc {
    typedef struct node {
        float heso;
        int somu;
        node *next;

        node(float x, int n) {
            heso = x;
            somu = n;
            next = nullptr;
        }

        ~node() {
            delete next;
        }
    } *pointer;
    //--------------------------------
    pointer donthuc;

    //--------------------------------
    pointer searchForExponent(int n, pointer *before) const {
        pointer p = *before = donthuc;
        while (p) {
            if (p->somu == n)
                return p;
            *before = p;
            p = p->next;
        }
        return nullptr;
    }

public:
    DaThuc();

    explicit DaThuc(const char *);

    DaThuc(const DaThuc &);

    const DaThuc &operator=(const DaThuc &);

    const DaThuc &operator-=(const DaThuc &);

    const DaThuc &operator+=(const DaThuc &);

    DaThuc operator-() const;

    float getMaxExponent() const;

    int getDegree() const;

    bool bang0() const;

    void add(float, int);

    DaThuc mul(float, int) const;

    DaThuc daoham() const;

    DaThuc operator+(const DaThuc &) const;

    DaThuc operator-(const DaThuc &) const;

    DaThuc operator*(const DaThuc &) const;

    bool chia(const DaThuc &, DaThuc &, DaThuc &) const;

    DaThuc operator/(const DaThuc &) const;

    DaThuc operator%(const DaThuc &) const;

    friend ostream &operator<<(ostream &, const DaThuc &);

    ~DaThuc() {
        delete donthuc;
    }
};

void CASE5();

int menu5(int &m5);

#endif //EXERCISES_BAI5_H
