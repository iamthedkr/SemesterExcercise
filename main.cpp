#include "Functions/Bai1.h"
#include "Functions/Bai2.h"
#include "Functions/Bai3.h"
#include "Functions/Bai4.h"
#include "Functions/Bai5.h"
#include "Functions/Bai6.h"
#include "Functions/Bai7.h"
#include "Functions/Bai8.h"
#include "Functions/Bai9.h"

using namespace std;

int menu(int &m) {
    do {
        cout << "\t\t1. Thao tac voi so nguyen." << endl;
        cout << "\t\t2. Thao tac voi xau ky tu." << endl;
        cout << "\t\t3. Thao tac voi da thuc." << endl;
        cout << "\t\t4. Thao tac tren ma tran." << endl;
        cout << "\t\t5. Thao tac voi da thuc bang cau truc." << endl;
        cout << "\t\t6. Thao tac tren so phuc bang cau truc." << endl;
        cout << "\t\t7. Quan ly sach." << endl;
        cout << "\t\t8. Thao tac tren FILE." << endl;
        cout << "\t\t9. Thao tac voi tap hop." << endl;
        cout << "\t\t0. De thoat." << endl;
        cout << "\t\t-------------MOI BAN CHON-------------" << endl;
        cin >> m;
    } while (m < 1 || m > 9);
    return m;
}

int main(int argc, char const *argv[]) {
    int nMenu(1);
    bool T(true);
    while (T) {
        menu(nMenu);
        switch (nMenu) {
            case 0: {
                T = false;
                break;
            }
            case 1: {
                CASE1();
                break;
            }
            case 2: {
                CASE2();
                break;
            }
            case 3: {
                CASE3();
                break;
            }
            case 4: {
                CASE4();
                break;
            }
            case 5: {
                CASE5();
                break;
            }
            case 6: {
                CASE6();
                break;
            }
            case 7: {
                CASE7();
                break;
            }
            case 8: {

                break;
            }
            case 9: {

                break;
            }
            default: {
                cout << "\t\tKHONG CO TRONG MENU, YEU CAU NHAP LAI!!!" << endl;
                cout << "\t\t****************************************" << endl;
            }
        }
    }
}
