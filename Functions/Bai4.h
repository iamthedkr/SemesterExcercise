//
// Created by DKR on 10/2/2019.
//
#include "../include.h"

#ifndef EXERCISES_BAI4_H
#define EXERCISES_BAI4_H


class SquareMatrix {
    double **matrix;
    int size;

public:
    SquareMatrix(int);

    SquareMatrix(istream &);

    SquareMatrix(const SquareMatrix &);

    const SquareMatrix &operator=(const SquareMatrix &);

    int getSize() const;

    double *operator[](int);

    int findNonZeroCell(int);

    SquareMatrix transposed() const;

    int toUpperTriangle(double **);

    bool eliminate(double **v);

    int rank() const;

    double det() const;

    bool solve(const double *right, double *result) const;

    SquareMatrix reverse() const;

    friend ostream &operator<<(ostream &, const SquareMatrix &);

    void releseMemory();

    virtual ~SquareMatrix() {
        releseMemory();
    }

};

void CASE4();

int menu4(int &m4);

#endif //EXERCISES_BAI4_H
