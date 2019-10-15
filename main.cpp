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
    //do {
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
    cout << "\t\t--------------MOI BAN CHON--------------" << endl;
        cin >> m;
    //} while (m < 1 || m > 9);
    return m;
}

int main(int argc, char const *argv[]) {
    int nMenu(0);
    LABEL1:
    menu(nMenu);
    switch (nMenu) {
        case 0:
            return 0;
        case 1:
            CASE1();
            goto LABEL2;
        case 2:
            CASE2();
            goto LABEL2;
        case 3:
            CASE3();
            goto LABEL2;
        case 4:
            CASE4();
            goto LABEL2;
        case 5:
            CASE5();
            goto LABEL2;
        case 6:
            CASE6();
            goto LABEL2;
        case 7:
            CASE7();
            goto LABEL2;
        case 8:
            goto LABEL2;
        case 9:
            goto LABEL2;
        default:
            goto LABEL2;
    }
    LABEL2:
    char choice;
    cout << "\t\t****************************************\n";
    cout << "\t\tDo you want to continue ?" << endl;
    cout << "\t\t\t- Yes, I do. (press y, Y)" << endl;
    cout << "\t\t\t- No, I dont. (press n, N)" << endl;
    cout << "\t\t****************************************" << endl;
    cout << "Your choice: ";
    cin >> choice;
    while (choice == '\n') {
        cin >> choice;
    }
    switch (choice) {
        case 'y':
        case 'Y':
            goto LABEL1;
        case 'n':
        case 'N':
            return 0;
        default:
            goto LABEL2;
    }
}
