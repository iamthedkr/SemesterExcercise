//
// Created by DKR on 10/2/2019.
//

#include "Bai2.h"

int menu2(int &m2) {
    do {
        cout << "\t\t1. Tim X = (x thuoc S1 hoac S2)." << endl;
        cout << "\t\t2. Tim X = (x thuoc S1 va S2)." << endl;
        cout << "\t\t3. Tim X (x thuoc S1 và khong thuoc S2)." << endl;
        cout << "\t\t4. Tim tap ky tu va so lan xuat hien moi ky tu trong ca S1, S2." << endl;
        cout << "\t\t5. Tim tap ky tu va so lan xuat hien moi ky tu trong ca S1 va S2." << endl;
        cout << "\t\t6. Tim tap ky tu va so lan xuat hien moi ky tu thuoc S1 nhung khong thuoc S2." << endl;
        cout << "\t\t7. Ma hoa X bang ky thuat chan le." << endl;
        cout << "\t\t8. Giai ma X bang ky thuat chan le." << endl;
        cout << "\t\t9. Tim tap tu va so lan xuat hien moi tu trong S1 hoac S2." << endl;
        cout << "\t\t10. Tim tap tu va so lan xuat hien moi tu trong S1 va S2." << endl;
        cout << "\t\t11 Tim tap tu va so lan xuat hien moi tu trong S1 nhung khong xuat hien trong S2." << endl;
        cout << "0. De quay lai." << endl;
        cout << "--------------------------------------MOI BAN CHON--------------------------------------" << endl;
        cin >> m2;
    } while (m2 < 1 && m2 > 11);
    return m2;
}

void CASE2() {
    int nMenu2;
    menu2(nMenu2);
    switch (nMenu2) {
        //case 0: {
        //    return 0;
        //}
        case 1: {

            break;
        }
        case 2: {

            break;
        }
        case 3: {

            break;
        }
        case 4: {

            break;
        }
        case 5: {

            break;
        }
        case 6: {

            break;
        }
        case 7: {

            break;
        }
        case 8: {

            break;
        }
        case 9: {

            break;
        }
        case 10: {

            break;
        }
        case 11: {

            break;
        }
        default: {
            cout << "\t\tKHONG CO TRONG MENU, YEU CAU NHAP LAI!!!" << endl;
            cout << "\t\t****************************************" << endl;
            menu2(nMenu2);
            break;
        }
    }

}
