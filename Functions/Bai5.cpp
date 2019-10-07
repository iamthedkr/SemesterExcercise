//
// Created by DKR on 10/2/2019.
//
#include "Bai5.h"

DaThuc::DaThuc() {
    donthuc = NULL;
}

DaThuc::DaThuc(const DaThuc &d) {
    donthuc = NULL;
    pointer p = d.donthuc;
    while (p) {
        add(p->heso, p->somu);
        p = p->next;
    }
}

const DaThuc &DaThuc::operator=(const DaThuc &d) {
    delete donthuc;
    donthuc = NULL;
    pointer p = d.donthuc;
    while (p) {
        add(p->heso, p->somu);
        p = p->next;
    }
    return d;
}

void DaThuc::add(float x, int n) {
    if (x == 0) return;
    pointer r, q, p = searchForExponent(n, &q);
    if (p) {
        p->heso += x;
        if (p->heso == 0) {
            if (p != donthuc) {
                q->next = p->next;
            } else {
                donthuc = p->next;
            }
            p->next = NULL;
            delete p;
        }
    } else {
        q = new node(x, n);
        p = donthuc;
        r = NULL;
        while (p && n < p->somu) {
            r = p;
            p = p->next;
        }
        if (r == NULL)
            donthuc = q;
        else r->next = q;
        q->next = p;
    }
}

DaThuc::DaThuc(const char *conststr) {
    donthuc = NULL;
    char *str = new char[strlen(conststr) + 1];
    strcpy(str, conststr);
    char *pch;
    pch = strtok(str, "+ ");
    while (pch != NULL) {
        float x;
        int n;
        sscanf(pch, "%fx^%d", &x, &n);
        add(x, n);
        pch = strtok(NULL, "+ ");
    }
}

int DaThuc::getDegree() const {
    if (donthuc == NULL) return 0;
    return donthuc->somu;
}

float DaThuc::getMaxExponent() const {
    return donthuc->heso;
}

bool DaThuc::bang0() const {
    return donthuc == NULL;
}

DaThuc DaThuc::daoham() const {
    DaThuc d(*this);
    pointer p = d.donthuc;
    while (p && p->somu) {
        p->heso *= p->somu;
        p->somu -= 1;
        p = p->next;
    }
    if (p) d.add(-(p->heso), 0);
    return d;
}

DaThuc DaThuc::operator-() const {
    DaThuc d(*this);
    pointer p = d.donthuc;
    while (p) {
        p->heso = -(p->heso);
        p = p->next;
    }
    return d;
}

const DaThuc &DaThuc::operator+=(const DaThuc &d) {
    pointer p = d.donthuc;
    while (p) {
        add(p->heso, p->somu);
        p = p->next;
    }

    return *this;
}

DaThuc DaThuc::operator+(const DaThuc &d) const {
    DaThuc ketqua(d);
    pointer p = donthuc;
    while (p) {
        ketqua.add(p->heso, p->somu);
        p = p->next;
    }

    return ketqua;
}

const DaThuc &DaThuc::operator-=(const DaThuc &d) {
    pointer p = d.donthuc;
    while (p) {
        add(-p->heso, p->somu);
        p = p->next;
    }
    return *this;
}

DaThuc DaThuc::operator-(const DaThuc &d) const {
    DaThuc ketqua(-d);
    pointer p = donthuc;
    while (p) {
        ketqua.add(p->heso, p->somu);
        p = p->next;
    }

    return ketqua;
}

DaThuc DaThuc::mul(float x, int n) const {
    DaThuc ketqua(*this);
    pointer p = ketqua.donthuc;
    while (p) {
        p->heso *= x;
        p->somu += n;
        p = p->next;
    }
    return ketqua;
}

DaThuc DaThuc::operator*(const DaThuc &d) const {
    DaThuc ketqua;
    pointer p = donthuc;
    while (p) {
        ketqua += d.mul(p->heso, p->somu);
        p = p->next;
    }

    return ketqua;
}

bool DaThuc::chia(const DaThuc &dtchia, DaThuc &thuong, DaThuc &du) const {
    float x;
    int n;
    du = *this;
    if (getDegree() < dtchia.getDegree())
        return !du.bang0();

    while (du.getDegree() >= dtchia.getDegree()) {
        x = du.getMaxExponent() / dtchia.getMaxExponent();
        n = du.getDegree() - dtchia.getDegree();
        thuong.add(x, n);
        du -= dtchia.mul(x, n);
    }
    return !du.bang0();
}

DaThuc DaThuc::operator/(const DaThuc &d) const {
    DaThuc thuong, du;
    chia(d, thuong, du);
    return thuong;
}

DaThuc DaThuc::operator%(const DaThuc &d) const {
    DaThuc thuong, du;
    chia(d, thuong, du);
    return du;
}

ostream &operator<<(ostream &out, const DaThuc &d) {
    DaThuc::pointer p = d.donthuc;
    if (p == NULL) return out << "0";
    cout << p->heso << "x^" << p->somu;
    p = p->next;
    while (p) {
        cout << "+" << p->heso << "x^" << p->somu;
        p = p->next;
    }

    return out;
}

int menu5(int &m5) {
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
        cin >> m5;
    } while (m5 < 1 && m5 > 8);
    return m5;
}

void CASE5() {
    int nMenu5;
    menu5(nMenu5);

    DaThuc P("1x^7+5x^2+1x^2+2x^4+12x^0");
    DaThuc Q("5x^3+-2x^4+-4x^0");

    switch (nMenu5) {
        case 1: {
            cout << "P(x) = " << P << endl;
            cout << "Q(x) = " << Q << endl;
            break;
        }
        case 2: {
            int x;
            cout << "Nhap x : ";
            cin >> x;

            break;
        }
        case 3: {
            cout << "P'(X) = " << P.daoham() << endl;
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
            menu5(nMenu5);
            break;
        }
    }

}
