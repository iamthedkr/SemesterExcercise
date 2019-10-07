//
// Created by DKR on 10/2/2019.
//

#include "Bai6.h"

void sophuc::OutputComplex(Complex a) {
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

Complex sophuc::Add(Complex a, Complex b) {
    Complex c;
    c.Re = a.Re + b.Re;
    c.Im = a.Im + b.Im;
    return c;
}

Complex sophuc::Sub(Complex a, Complex b) {
    Complex c;
    c.Re = a.Re - b.Re;
    c.Im = a.Im - b.Im;
    return c;
}

Complex sophuc::Mul(Complex a, Complex b) {
    Complex c;
    c.Re = a.Re * b.Re - a.Im * b.Im;
    c.Im = a.Re * b.Im + a.Im * b.Re;
    return c;
}

float sophuc::Modulus(Complex) {
    return 0;
}

Complex sophuc::Div(Complex a, Complex b) {
    Complex Conjgb;
    Conjgb.Re = b.Re;
    Conjgb.Im = -b.Im;
    Complex c = Mul(a, Conjgb);
    float d = b.Re * b.Re + b.Im * b.Im;
    c.Re /= d;
    c.Im /= d;
    return c;
}

Complex sophuc::Square(Complex a) {
    return Mul(a, a);
}

Complex sophuc::SquareRoot(Complex a, Complex complex) {
    Complex c;
    float delta = Modulus(a);
    if ((a.Re + delta) / 2 >= 0)
        c.Re = sqrt((a.Re + delta) / 2);
    else
        c.Re = sqrt((a.Re - delta) / 2);
    c.Im = a.Im / c.Re / 2;
    return c;
}

Complex sophuc::SquareRoot(Complex) {
    return Complex();
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

void CASE6() {
    int nMenu6;
    menu6(nMenu6);
    Complex a, b;
    cout << "Nhap so phuc a: ";
    cin >> a.Re >> a.Im;
    cout << "Nhap so phuc b: ";
    cin >> b.Re >> b.Im;
    switch (nMenu6) {
        case 1: {
            cout << "So phuc a,b la: " << a.Re << "+" << a.Im << "i" << " , " << b.Re << "+" << b.Im << "i" << endl;
            break;
        }
        case 2: {
            cout << "a + b = ";
            sophuc::OutputComplex(sophuc::Add(a, b));
            break;
        }
        case 3: {
            cout << "a * b = ";
            sophuc::OutputComplex(sophuc::Mul(a, b));
            break;
        }
        case 4: {
            cout << "a - b = ";
            sophuc::OutputComplex(sophuc::Div(a, b));
            break;
        }
        case 5: {
            //cout << "P " << P - Q << endl;
            break;
        }
        case 6: {
            cout << "Sqrt(a) = ";
            sophuc::OutputComplex(sophuc::SquareRoot(a));
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