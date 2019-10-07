//
// Created by DKR on 10/2/2019.
//

#include "Bai3.h"

void poly::set(int m, double v[]) {
    this->~poly();
    deg = m;
    coef = new double[deg + 1];
    for (int k = 0; k <= deg; k++) coef[k] = v[k];
}

poly::poly(int _deg) {
    deg = _deg;
    if (deg < 0) deg = 0;
    coef = new double[deg + 1];
    for (int k = 0; k <= deg; k++) coef[k] = 0;
}

poly::poly(const poly &a) {
    deg = a.deg;
    coef = new double[deg + 1];
    for (int k = 0; k <= deg; k++) coef[k] = a[k];
}

poly &poly::operator=(const poly &b) {
    if (this != &b) {
        this->~poly();
        deg = b.deg;
        coef = new double[deg + 1];
        for (int k = 0; k <= deg; k++) coef[k] = b[k];
    }
    return *this;
}

poly::poly(int k, double v) {
    deg = k;
    coef = new double[k + 1];
    for (int j = 0; j < deg; j++) coef[j] = 0;
    coef[deg] = v;
}


poly poly::operator*(double f) {
    poly c(*this);
    for (int k = 0; k <= deg; k++) c[k] *= f;
    while (c.deg && c[c.deg] == 0) c.deg--;
    return c;
}

poly poly::operator+(const poly &b) const {
    if (deg <= b.deg) {
        poly c(b);
        for (int k = 0; k <= deg; k++) c[k] += coef[k];
        while (c.deg && c[c.deg] == 0) c.deg--;
        return c;
    } else return b + *this;
}

poly poly::operator-() const {
    poly c(*this);
    for (int k = 0; k <= deg; k++) c[k] = -c[k];
    return c;
}

poly poly::operator-(const poly &b) const {
    return *this + -b;
}

poly poly::operator*(const poly &b) const {
    poly c(deg + b.deg);
    for (int k = 0; k <= deg; k++)
        for (int j = 0; j <= b.deg; j++)
            c[k + j] = c[k + j] + coef[k] * b[j];
    while (c.deg && c[c.deg] == 0) c.deg--;
    return c;
}

poly poly::operator/(const poly &b) const {
    if (deg < b.deg) return poly(0, 0);
    poly c(deg - b.deg), a(*this);
    int jc = c.deg, ja = deg;
    while (jc >= 0) {
        c[jc] = a[ja] / b[b.deg];
        a = a - b * poly(jc, c[jc]);
        jc--;
        ja--;
    }
    return c;
}

poly poly::operator%(const poly &b) const {
    poly a(*this);
    if (deg >= b.deg) {
        a = a - (a / b) * b;
        while (a[a.deg] == 0) a.deg--;
    }
    return a;
}

int operator==(const poly &a, const poly &b) {
    if (a.deg != b.deg) return 0;
    int k = 0;
    while (k <= a.deg && a[k] == b[k]) k++;
    return k > a.deg;
}

/*
poly poly::daoham() {
    poly d2;
    for (int i = 1; i <= deg; i++) {
        d2.coef[i - 1] = coef[i].daoham();
    }
    d2.deg = deg - 1;
    return d2;
}
*/
//TODO: fix this.

double poly::value(double x) {
    double val = coef[deg];
    for (int k = deg - 1; k >= 0; k--)
        val = val * x + coef[k];
    return val;
}

ostream &operator<<(ostream &pout, const poly &p) {
    int k = 0;
    while (k <= p.deg && p[k] == 0) k++;
    if (k > p.deg) {
        pout << 0;
        return pout;
    }
    if (k == 0) pout << p[k];
    else {
        if (p[k] == 1) pout << "x";
        else if (p[k] == -1) pout << "-x";
        else pout << p[k] << "x";
        if (k > 1) pout << "^" << k;
    }

    while (++k <= p.deg)
        if (p[k] > 0) {
            pout << " + ";
            if (p[k] != 1) pout << p[k];
            pout << "x";
            if (k > 1) pout << "^" << k;
        } else if (p[k] < 0) {
            pout << " - ";
            if (p[k] != -1) pout << -p[k];
            pout << "x";
            if (k > 1) pout << "^" << k;
        }
    return pout;
}

istream &operator>>(istream &pin, poly &p) {
    do {
        cout << "Bac cua da thuc: ";
        pin >> p.deg;
    } while (p.deg < 0);

    p.coef = new double[p.deg + 1];
    cout << "Nhap lien tiep " << p.deg + 1 << " he so tu bac 0 den bac " << p.deg << ": ";
    for (int k = 0; k <= p.deg; k++) pin >> p[k];
    while (p[p.deg] == 0) p.deg--;
    return pin;
}

int menu3(int &m3) {
    do {
        cout << "\t\t1. Tao lap hai da thuc Pn(X), Qm(X)." << endl;
        cout << "\t\t2. Tim Pn(Xo), Qm(Xo)." << endl;
        cout << "\t\t3. Tim dao ham cap L cua Pn(X), Qm(X)." << endl;
        cout << "\t\t4. Tim R = P + Q." << endl;
        cout << "\t\t5. Tim R = P - Q." << endl;
        cout << "\t\t6. Tim R = P * Q." << endl;
        cout << "\t\t7. Tim R = P / Q va da thuc du." << endl;
        cout << "\t\t8. Xay dung cac thao tac cong, tru, nhan, chia hai so nguyen bang da thuc." << endl;
        cout << "\t\t0. De quay lai." << endl;
        cout << "--------------------------------------MOI BAN CHON--------------------------------------" << endl;
        cin >> m3;
    } while (m3 < 1 && m3 > 8);
    return m3;
}

void CASE3() {
    int nMenu3;
    menu3(nMenu3);
    poly P, Q;
    switch (nMenu3) {
        case 1: {
            cout << "Da thuc P(x):\n";
            cin >> P;
            cout << "Da thuc Q(x):\n";
            cin >> Q;
            cout << "P(x) = " << P << endl;
            cout << "Q(x) = " << Q << endl;
            break;
        }
        case 2: {
            int x;
            cout << "Nhap x : ";
            cin >> x;
            cout << "P(" << x << ") = " << P.value(x) << endl;
            cout << "Q(" << x << ") = " << Q.value(x) << endl;
            break;
        }
        case 3: {
            //cout << "P'(X) = " << P.daoham() << endl;
            break;
        }
        case 4: {
            cout << "P + Q = " << P + Q << endl;
            break;
        }
        case 5: {
            cout << "P - Q = " << P - Q << endl;
            break;
        }
        case 6: {
            cout << "P x Q = " << P * Q << endl;
            break;
        }
        case 7: {
            cout << "P / Q = " << P / Q << endl;
            cout << "P % Q = " << P % Q << endl;
            break;
        }
        case 8: {

            break;
        }
        default: {
            cout << "\t\tKHONG CO TRONG MENU, YEU CAU NHAP LAI!!!" << endl;
            cout << "\t\t****************************************" << endl;
            menu3(nMenu3);
            break;
        }
    }

}
