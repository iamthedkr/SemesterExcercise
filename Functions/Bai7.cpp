//
// Created by DKR on 10/2/2019.
//

#include "Bai7.h"

void ThemSach(ListSach a, int &n) {
    n++;
    cout << "\n                         THEM MOT DAU SACH MOI VAO THU VIEN                  \n";
    cout << "===============================================================================\n";
    nhaplaimasach:
    cout << "Nhap MS :";
    cin >> a[n].ID;
    if (Tim_MSSach(a, n - 1, a[n].ID) != 0) {
        cout << "Ma Sach Da Co , Vui Long Nhap Lai \n";
        goto nhaplaimasach;
    }
    cout << "Nhap ten sach: ";
    cin.ignore();
    cin.getline(a[n].Name, 100);
    //  gets(a[n].Name);
    cout << "Nhap the loai: ";
    gets(a[n].Title);
    cout << "Nhap ten tac gia: ";
    gets(a[n].Author);
    cout << "\n THEM DAU SACH MOI THANH CONG " << endl;
    cout << "===============================================================================\n";
}

int Tim_MSSach(ListSach a, int n, char c[8]) {
    int i;
    i = 1;
    while ((i <= n) && (strcmp(a[i].ID, c) != 0))
        i++;
    if (i > n)
        return 0;
    else
        return i;
}

void InToanBoSach(ListSach a, int n) {
    cout << "\n \n                 DANH SACH CAC DAU SACH CO TRONG THU VIEN ";
    cout << "\n  ---------------------------------------------------------------------------------------------";
    cout << "\n  |       Ma Sach      |            Ten Sach            |       The Loai       |    Tac gia   |";
    cout << "\n  ---------------------------------------------------------------------------------------------";
    for (int i = 1; i <= n; i++) {
        cout << "\n\t     " << a[i].ID << setw(25 - strlen(a[i].ID) + 1);
        cout << " " << a[i].Name << setw(25 - strlen(a[i].Name) + 1);
        cout << " " << a[i].Title << setw(17 - strlen(a[i].Title) + 1);
        cout << " " << a[i].Author;
    }
    cout << "\n  -----------------------------------------------------------------------------\n";
}

void InChiTietSach(ListSach a, int n, char ms[8]) {
    int vitri;
    vitri = Tim_MSSach(a, n, ms);
    if (vitri == 0)
        cout << "Ko Tim Thay Ma So Sach Nhap Vao \n";
    else {
        cout << "\n    THONG TIN CHI TIET SACH \n" << endl;
        cout << "Ma So       : " << a[vitri].ID << endl;
        cout << "Ten Sach    : " << a[vitri].Name << endl;
        cout << "The Loai    : " << a[vitri].Title << endl;
        cout << "Tac Gia     : " << a[vitri].Author << endl;

    }
}

void TimSachTheLoai(ListSach a, int n) {
    char tentheloai[50];
    int dem = 0;
    cout << "\n                         LIET KE CAC SACH THEO MOT THE LOAI                  \n";
    cout << "===============================================================================\n";
    cout << "Nhap Vao Ten The Loai Muon Tim :";
    cin.ignore();
    cin.getline(tentheloai, 50);
    cout << "\n  ----------------------------------------------------------------------------";
    cout << "\n                      Ma Sach           |          Ten Sach                    ";
    cout << "\n  ----------------------------------------------------------------------------";
    for (int i = 1; i <= n; i++) {
        if (strcmp(a[i].Title, tentheloai) == 0) {
            cout << "\n\t\t\t" << a[i].ID << setw(28 - strlen(a[i].ID) + 1) << " " << a[i].Name
                 << setw(60 - strlen(a[i].Name) + 1) << " ";
            dem++;
        }
    }
    cout << "\n  ----------------------------------------------------------------------------" << endl;
    if (dem == 0)
        cout << "\n \n KO TIM THAY THE LOAI SACH MA BAN NHAP VAO \n";
}

void GhiDuLieu(ListSach a, int n) {
    FILE *f;
    f = fopen("DATA.DAT", "wb");
    fwrite(&n, sizeof(int), 1, f);
    for (int i = 1; i <= n; i++)
        fwrite(&a[i], sizeof(Sach), 1, f);
    fclose(f);
    cout << "\n GHI DU LIEU VAO FILE THANH CONG \n";
}

void DocDuLieu(ListSach &a, int &n) {
    FILE *f;
    Sach g{};
    f = fopen("DATA.DAT", "rb");
    if (f == nullptr)
        cout << "\n                FILE DU LIEU KHONG TON TAI VUI LONG TAO MOI DANH SACH \n \n \n";
    else {
        fread(&n, sizeof(int), 1, f);
        for (int i = 1; i <= n; i++) {
            fread(&g, sizeof(Sach), 1, f);
            a[i] = g;
        }
        fclose(f);
    }
}

/*
int compareTitle(ListSach a, int n) {
    for (int i = 1; i <= n; ++i) {
        if (strcmp(a->Title, (a + i)->Title) > 0)
            return 1;
    }
}
*/
void sortTitle(ListSach a, int n) {
    sort(a->Title, (a + n)->Title);
    InToanBoSach(a, n);
}

int menu7(int &m7) {
    //do {
        cout << "\t\t1. Nhap sach." << endl;
        cout << "\t\t2. Hien thi thong tin ve sach." << endl;
        cout << "\t\t3. Sap xep theo chu de sach." << endl;
        cout << "\t\t4. Tim kiem theo chu de sach." << endl;
        cout << "\t\t0. De quay lai." << endl;
        cout << "--------------------------------------MOI BAN CHON--------------------------------------" << endl;
        cin >> m7;
    //} while (m7 < 1 || m7 > 4);
    return m7;
}

void CASE7() {
    int nMenu7, n = 0;
    ListSach a;
    menu7(nMenu7);
    switch (nMenu7) {
        case 0:
            break;
        case 1: {
            DocDuLieu(a, n);
            ThemSach(a, n);
            GhiDuLieu(a, n);
            break;
        }
        case 2: {
            DocDuLieu(a, n);
            InToanBoSach(a, n);
            char ms[8];
            cout << "Nhap Vao Ma So Sach Can Xem Thong Tin \n ";
            cin >> ms;
            InChiTietSach(a, n, ms);
            break;
        }
        case 3: {
            DocDuLieu(a, n);
            sortTitle(a, n);
            break;
        }
        case 4: {
            DocDuLieu(a, n);
            TimSachTheLoai(a, n);
            break;
        }
        default: {
            cout << "\t\tKHONG CO TRONG MENU, YEU CAU NHAP LAI!!!" << endl;
            //menu7(nMenu7);
            break;
        }
    }

}
