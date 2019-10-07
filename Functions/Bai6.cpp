//
// Created by DKR on 10/2/2019.
//

#include "Bai6.h"

void OutputComplex(Complex a) {
    if (a.Re != 0) cout << a.Re;
    if (a.Im != 0) {
        if (a.Im == -1) cout << "-i";
        else if (a.Im == 1) {
            if (a.Re == 0) cout << "i";
            else cout << "+i";
        } else {
            if (a.Re != 0 && a.Im > 0)
                cout << "+" << a.Im << "i" << endl;
            else
                cout << a.Im << "i" << endl;
        }
    }
    if (a.Re == 0 & a.Im == 0)
        cout << "0" << endl;
}

float Modulus(Complex a) {
    return sqrt(a.Re * a.Re + a.Im * a.Im);
}

_Resetiosflags Add(Complex a, Complex b) {
    Complex c;
    c.Re = a.Re + b.Re;
    c.Im = a.Im + b.Im;
    return c;
}

Complex Sub(Complex a, Complex b) {
    Complex c;
    c.Re = a.Re - b.Re;
    c.Im = a.Im - b.Im;
    return c;
}

_Resetiosflags Mul(Complex a, Complex b) {
    Complex c;
    c.Re = a.Re * b.Re - a.Im * b.Im;
    c.Im = a.Re * b.Im + a.Im * b.Re;
    return c;
}

_Resetiosflags Div(Complex a, Complex b) {
    Complex c = Mul(a, Conjg(b));
    float d = b.Re * b.Re + b.Im * b.Im;
    c.Re /= d;
    c.Im /= d;
    return c;
}

Complex Square(Complex a) {
    return Mul(a, a);
}

Complex SquareRoot(Complex a) {
    Complex c;
    float delta = Modulus(a);
    if ((a.Re + delta) / 2 >= 0)
        c.Re = sqrt((a.Re + delta) / 2);
    else
        c.Re = sqrt((a.Re - delta) / 2);
    c.Im = a.Im / c.Re / 2;
    return c;
}

int menu6(int &m6) {
    do {
        cout << "\t\t1. Tao lap hai so phuc." << endl;
        cout << "\t\t2. Cong hai so phuc." << endl;
        cout << "\t\t3. Nhan hai so phuc." << endl;
        cout << "\t\t4. Chia hai so phuc." << endl;
        cout << "\t\t5. Luy thua so phuc." << endl;
        cout << "\t\t6. Can bac hai cua so phuc." << endl;
        cout << "\t\t0. De quay lai." << endl;
        cout << "------------------MOI BAN CHON------------------" << endl;
        cin >> m6;
    } while (m6 < 1 && m6 > 6);
    return m6;
}

void CASE5() {
    int nMenu6;
    menu6(nMenu6);
    Complex a, b;
    cout << "Nhap so phuc a: ";
    cin >> a.Re >> a.Im;
    cout << "Nhap so phuc b: ";
    cin >> b.Re >> b.Im;
    switch (nMenu6) {
        case 1: {
            cout << "Nhap so phuc a: ";
            cin >> a.Re >> a.Im;
            cout << "Nhap so phuc b: ";
            cin >> b.Re >> b.Im;
            cout << "So phuc a,b la: " << a.Re << "+" << a.Im << "i" << " , " << b.Re << "+" << b.Im << "i" << endl;
            break;
        }
        case 2: {
            cout << "a + b = " << Add(a, b) << endl;
            break;
        }
        case 3: {
            cout << "a * b = " << Mul(a, b) << endl;
            break;
        }
        case 4: {
            cout << "a / b = " << Div(a, b) << endl;
            break;
        }
        case 5: {
            //cout << "P " << P - Q << endl;
            break;
        }
        case 6: {
            //cout << "P - Q = " << P - Q << endl;
            break;
        }
        default: {
            cout << "\t\tKHONG CO TRONG MENU, YEU CAU NHAP LAI!!!" << endl;
            cout << "\t\t****************************************" << endl;
            menu6(nMenu6);
            break;
        }
    }

}
