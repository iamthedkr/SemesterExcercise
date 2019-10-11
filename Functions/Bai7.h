//
// Created by DKR on 10/2/2019.
//
#include "../include.h"

#ifndef EXERCISES_BAI7_H
#define EXERCISES_BAI7_H


struct Sach {
    char Name[100];
    char ID[8];
    char Title[100];
    char Author[100];
};

typedef Sach ListSach[50];

int Tim_MSSach(ListSach a, int n, char c[8]);

void InChiTietSach(ListSach a, int n, char ms[8]);


class SACH {
public:

};

void CASE7();

int menu7(int &m7);

#endif //EXERCISES_BAI7_H
