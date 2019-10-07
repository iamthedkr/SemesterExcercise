//
// Created by DKR on 10/2/2019.
//

#include <fstream>
#include "Bai4.h"

void swapColum(double **matrix, int size, int m, int n) {
    for (int i = 0; i < size; i++) {
        double tmp = matrix[i][m];
        matrix[i][m] = matrix[i][n];
        matrix[i][n] = tmp;
    }
}

void swapRow(double **matrix, int size, int m, int n) {
    double *v = new double[size];
    memcpy(v, matrix[m], size * sizeof(double));
    memcpy(matrix[m], matrix[n], size * sizeof(double));
    memcpy(matrix[n], v, size * sizeof(double));
}

SquareMatrix::SquareMatrix(int n) {
    size = n;
    matrix = new double *[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
        memset(matrix[i], 0, size * sizeof(double));
    }
}

SquareMatrix::SquareMatrix(istream &in) {
    in >> size;
    matrix = new double *[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
        for (int j = 0; j < size; j++)
            in >> matrix[i][j];
    }
}

int SquareMatrix::getSize() const {
    return size;
}

void SquareMatrix::releseMemory() {
    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = NULL;
}

double *SquareMatrix::operator[](int i) {
    return matrix[i];
}

SquareMatrix::SquareMatrix(const SquareMatrix &m) {
    size = m.size;
    matrix = new double *[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
        memcpy(matrix[i], m.matrix[i], size * sizeof(double));
    }
}

const SquareMatrix &SquareMatrix::operator=(const SquareMatrix &m) {
    size = m.size;
    releseMemory();
    matrix = new double *[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
        memcpy(matrix[i], m.matrix[i], size * sizeof(double));
    }
    return m;
}

int SquareMatrix::findNonZeroCell(int i) {
    for (int j = 0; j < size; j++) {
        if (matrix[i][j] != 0) return j;
    }
    return -1;
}

SquareMatrix SquareMatrix::transposed() const {
    SquareMatrix t(size);
    for (int i = 0; i < size; i++) {
        t[i][i] = matrix[i][i];
        for (int j = i + 1; j < size; j++) {
            t[i][j] = matrix[j][i];
            t[j][i] = matrix[i][j];
        }
    }
    return t;
}

int SquareMatrix::toUpperTriangle(double **v = NULL) {
    int j, rank = size;

    for (int i = 0; i < rank; i++) {

        while (rank > 0) {
            j = findNonZeroCell(i);
            if (j == -1) {
                swapRow(matrix, size, i, --rank);
                swapRow(v, size, i, rank);
            } else break;
        }

        if (j != i) {
            swapColum(matrix, size, i, j);
            swapColum(v, size, i, j);
        }

        double b = matrix[i][i];
        for (j = i + 1; j < rank; j++) {
            double a = matrix[j][i];
            matrix[j][i] = 0;
            int k;
            if (v)
                for (k = 0; k < size; k++)
                    v[k][j] -= (a * v[k][i]) / b;

            for (k = i + 1; k < rank; k++) {
                matrix[j][k] -= (a * matrix[i][k]) / b;
            }
        }
        while (rank > 0 && findNonZeroCell(rank - 1) == -1) {
            rank--;
        }
    }
    return rank;
}

bool SquareMatrix::eliminate(double **v = NULL) {
    int rank = toUpperTriangle(v);
    if (rank < size) return false;
    for (int i = size - 1; i >= 0; i--) {
        double b = matrix[i][i];
        for (int j = 0; j < i; j++) {
            double a = matrix[j][i];
            matrix[j][i] = 0;
            int k;
            if (v)
                for (k = 0; k < size; k++)
                    v[k][j] -= (a * v[k][i]) / b;
            //gauss - jordan

            for (k = i + 1; k < size; k++) {
                matrix[j][k] -= (a * matrix[i][k]) / b;
            }
        }
    }
    return true;
}


int SquareMatrix::rank() const {
    SquareMatrix tmp(*this);
    return tmp.toUpperTriangle();
}

double SquareMatrix::det() const {
    SquareMatrix tmp(*this);
    if (tmp.toUpperTriangle() < size) return 0;
    double det = 1;
    for (int i = 0; i < size; i++) {
        det *= tmp.matrix[i][i];
    }
    return det;
}

SquareMatrix SquareMatrix::reverse() const {
    SquareMatrix tmp = transposed(), unit(size);
    for (int i = 0; i < size; i++)
        unit[i][i] = 1;
    if (tmp.eliminate(unit.matrix)) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                unit[j][i] /= tmp[i][i];
            }
        }
    }
    return unit;
}

bool SquareMatrix::solve(const double *right, double *result) const {
    double detA = det();
    if (detA == 0) return 0;
    SquareMatrix rv = reverse();
    for (int i = 0; i < size; i++) {
        result[i] = 0;
        for (int j = 0; j < size; j++) {
            result[i] += rv.matrix[i][j] * right[j];
        }
    }
    return 1;
}

ostream &operator<<(ostream &out, const SquareMatrix &m) {
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            out << setw(10) << setprecision(6) << m.matrix[i][j];
        }
        out << endl;
    }
    return out;
}

void nhap(int a[MAX][MAX], int d, int c) {
    int i, j;

    for (i = 0; i < d; i++) {
        for (j = 0; j < c; j++) {
            cout << "Nhap phan tu thu" << "[" << i << "]" << '[' << j << "]";
            cin >> a[i][j];
            cout << endl;
        }
    }
}

void xuat(int a[MAX][MAX], int d, int c) {
    int i, j;
    for (i = 0; i < d; i++) {
        for (j = 0; j < c; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void tich(int a[MAX][MAX], int b[MAX][MAX], int t[MAX][MAX], int da, int ca, int cb) {
    int i, j, k;
    for (i = 0; i < da; i++) {
        for (j = 0; j < cb; j++) {
            t[i][j] = 0;
            for (k = 0; k < ca; k++) {
                t[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int menu4(int &m4) {
    do {
        cout << "\t\t1. Tao lap ma tran." << endl;
        cout << "\t\t2. Nhan hai ma tran." << endl;
        cout << "\t\t3. Tim phan tu lon nhat cua ma tran." << endl;
        cout << "\t\t4. Tim hang cua ma tran." << endl;
        cout << "\t\t5. Tim cac vecto rieng va gia tri rieng." << endl;
        cout << "\t\t6. Tim chuyen vi cua ma tran." << endl;
        cout << "\t\t7. Tim dinh thuc cua ma tran." << endl;
        cout << "\t\t8. Tim nghich dao cua ma tran." << endl;
        cout << "\t\t9. Giai he phuong trinh tuyen tinh thuan nhat AX = B." << endl;
        cout << "\t\t0. De quay lai." << endl;
        cout << "--------------------------------------MOI BAN CHON--------------------------------------" << endl;
        cin >> m4;
    } while (m4 < 1 && m4 > 9);
    return m4;
}

void CASE4() {
    int nMenu4;
    menu4(nMenu4);

    ifstream file("matrix.txt", ios::in);
    SquareMatrix A(file);
    int i, j, size = A.getSize();

    double *v = new double[size];
    for (i = 0; i < size; i++)
        file >> v[i];

    switch (nMenu4) {
        //case 0: {
        //    return 0;
        //}
        case 1: {
            cout << "Ma tran A:\n" << A << endl;
            break;
        }
        case 2: {
            int a[MAX][MAX], b[MAX][MAX], t[MAX][MAX];
            int da, db, ca, cb, dc, cc;
            cout << "Nhap vao so dong ma tran A:";
            cin >> da;
            cout << "Nhap vao so cot ma tran A:";
            cin >> ca;
            nhap(a, da, ca);
            cout << "A: " << endl;
            xuat(a, da, ca);
            cout << "Nhap vao so dong ma tran B:";
            cin >> db;
            cout << "Nhap vao so cot ma tran B:";
            cin >> cb;
            nhap(b, db, cb);
            cout << "B: " << endl;
            xuat(b, db, cb);
            tich(a, b, t, da, ca, cb);
            cout << "Tich cua 2 ma tran la: " << endl;
            dc = da;
            cc = cb;
            xuat(t, dc, cc);
            break;
        }
        case 3: {
            int a[MAX][MAX];
            int da, ca;
            cout << "Nhap vao so dong ma tran A:";
            cin >> da;
            cout << "Nhap vao so cot ma tran A:";
            cin >> ca;
            nhap(a, da, ca);
            cout << "A: " << endl;
            xuat(a, da, ca);
            int maximum = 0;
            for (int m = 0; m < da; m++) {
                for (int n = 0; n < ca; n++) {
                    if (maximum < a[m][n]) {
                        maximum = a[m][n];
                    }
                }

            }
            cout << "Phan tu lon nhat la: " << maximum << endl;
            break;
        }
        case 4: {
            cout << "rank(A) = " << A.rank() << endl;
            break;
        }
        case 5: {

            break;
        }
        case 6: {
            cout << "Ma tran chuyen vi:\n" << A.transposed() << endl;
            break;
        }
        case 7: {
            double detA = A.det();
            cout << "det(A) = " << detA << endl;
            break;
        }
        case 8: {
            double detA = A.det();
            cout << "\nMa tran nghich dao:\n";
            if (detA) cout << A.reverse();
            else cout << "Khong co!";
            break;
        }
        case 9: {
            cout << "\nGiai phuong trinh:" << endl;

            for (i = 0; i < size; i++) {
                for (j = 0; j < size - 1; j++)
                    cout << A[i][j] << char('a' + j) << " + ";
                cout << A[i][j] << char('a' + j) << " = " << v[i] << endl;
            }

            double *x = new double[size];
            if (!A.solve(v, x))
                cout << "\nKhong giai duoc!";
            else {
                cout << "\nNghiem:\n";
                for (i = 0; i < size; i++)
                    cout << char('a' + i) << " = " << x[i] << endl;
            }
            break;
        }

        default: {
            cout << "\t\tKHONG CO TRONG MENU, YEU CAU NHAP LAI!!!" << endl;
            cout << "\t\t****************************************" << endl;
            menu4(nMenu4);
            break;
        }
    }

}
