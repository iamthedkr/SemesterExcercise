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

void ThemSach(ListSach, int &);

int Tim_MSSach(ListSach, int, char c[8]);

void InToanBoSach(ListSach, int);

void InChiTietSach(ListSach, int, char ms[8]);

void TimSachTheLoai(ListSach, int);


class SACH {
public:

};

void CASE7();

int menu7(int &m7);

#endif //EXERCISES_BAI7_H
