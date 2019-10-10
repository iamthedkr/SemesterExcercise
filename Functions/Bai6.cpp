//
// Created by DKR on 10/2/2019.
//

#include "Bai6.h"

Complex SOPHUC::Add(Complex a, Complex b) {
    Complex c;
    c.thuc = a.thuc + b.thuc;
    c.ao = a.ao + b.ao;
    return c;
}

Complex SOPHUC::Sub(Complex a, Complex b) {
    Complex c;
    c.thuc = a.thuc - b.thuc;
    c.ao = a.ao - b.ao;
    return c;
}

Complex SOPHUC::Mul(Complex a, Complex b) {
    Complex c;
    c.thuc = a.thuc * b.thuc - a.ao * b.ao;
    c.ao = a.thuc * b.ao + a.ao * b.thuc;
    return c;
}

Complex SOPHUC::Pow(Complex a) {
    Complex c;
    int mu;
    c.thuc = a.thuc, c.ao = a.ao;
    cout << "Nhap so mu: ";
    cin >> mu;
    if (mu == 0) cout << "1" << endl;
    else {
        for (int i = 1; i < mu; i++) {
            float Re = c.thuc, Im = c.ao;
            c.thuc = Re * a.thuc - Im * a.ao;
            c.ao = Re * a.ao + Im * a.thuc;
        }
    }
    return c;
}

Complex SOPHUC::Div(Complex a, Complex b) {
    Complex c;
    float tongbp = b.thuc * b.thuc + b.ao * b.ao;
    c.thuc = (a.thuc * a.ao + b.thuc * b.ao) / tongbp;
    c.ao = (a.ao * b.thuc - a.thuc * b.ao) / tongbp;
    return c;
}


float SOPHUC::Modulus(Complex a) {
    return sqrt(a.thuc * a.ao + a.thuc * a.ao);
}

Complex SOPHUC::SquareRoot(Complex a) {
    Complex c;
    float delta = Modulus(a);
    if ((a.thuc + delta) / 2 >= 0)
        c.thuc = sqrt((a.thuc + delta) / 2);
    else
        c.thuc = sqrt((a.thuc - delta) / 2);
    c.ao = a.ao / c.thuc / 2;
    return c;
}

void SOPHUC::inputComplex(Complex &a, Complex &b) {
    cout << "Nhap so phuc a: ";
    cin >> a.thuc >> a.ao;
    cout << "Nhap so phuc b: ";
    cin >> b.thuc >> b.ao;
}

void SOPHUC::outputComplex(Complex a) {
    cout << a.thuc << " + " << a.ao << "i";
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
        cout << "\t\t------------------MOI BAN CHON------------------" << endl;
        cin >> m6;
    } while (m6 < 1 || m6 > 6);
    return m6;
}

void CASE6() {
    int nMenu6;
    menu6(nMenu6);
    Complex a = Complex(), b = Complex();
    SOPHUC Comp;
    switch (nMenu6) {
        case 1: {
            Comp.inputComplex(a, b);
            cout << "So phuc a va b la: " << endl;
            Comp.outputComplex(a);
            cout << endl;
            Comp.outputComplex(b);
            break;
        }
        case 2: {
            Comp.inputComplex(a, b);
            cout << "Ban muon tinh tong hay hieu?   1:Tong , 0:Hieu" << endl;
            int tongHieu;
            cin >> tongHieu;
            switch (tongHieu) {
                case 1: {
                    cout << "a + b = ";
                    Comp.outputComplex(Comp.Add(a, b));
                    break;
                }
                case 2: {
                    cout << "a - b = ";
                    Comp.outputComplex(Comp.Sub(a, b));
                    break;
                }
            }


            break;
        }
        case 3: {
            Comp.inputComplex(a, b);
            cout << "a * b = ";
            Comp.outputComplex(Comp.Mul(a, b));
            break;
        }
        case 4: {
            Comp.inputComplex(a, b);
            cout << "a / b = ";
            Comp.outputComplex(Comp.Div(a, b));
            break;
        }
        case 5: {
            Comp.inputComplex(a, b);
            cout << " A^x = ";
            Comp.outputComplex(Comp.Pow(a));
            break;
        }
        case 6: {
            Comp.inputComplex(a, b);
            cout << "Sqrt(a) = ";
            Comp.outputComplex(Comp.SquareRoot(a));
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