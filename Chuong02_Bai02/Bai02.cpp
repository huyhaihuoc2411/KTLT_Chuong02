#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Cấu trúc phân số
typedef struct {
    int tuSo;    // Tử số
    int mauSo;   // Mẫu số
} PhanSo;

// Hàm tính UCLN
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tối giản phân số
PhanSo toiGianPhanSo(PhanSo p) {
    int ucln = gcd(p.tuSo, p.mauSo);
    p.tuSo /= ucln;
    p.mauSo /= ucln;
    if (p.mauSo < 0) {  // Đưa mẫu số về dương
        p.tuSo = -p.tuSo;
        p.mauSo = -p.mauSo;
    }
    return p;
}

// Hàm nhập phân số
void nhapPhanSo(PhanSo* p) {
    printf("Nhap tu so: ");
    scanf("%d", &p->tuSo);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &p->mauSo);
        if (p->mauSo == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (p->mauSo == 0);
    *p = toiGianPhanSo(*p);
}

// Hàm xuất phân số
void xuatPhanSo(PhanSo p) {
    if (p.mauSo == 1) {
        printf("%d", p.tuSo);
    }
    else if (p.mauSo < 0) {
        printf("%d/%d", -p.tuSo, -p.mauSo);
    }
    else {
        printf("%d/%d", p.tuSo, p.mauSo);
    }
}

// Hàm nhập danh sách phân số
void nhapDanhSachPhanSo(PhanSo a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&a[i]);
    }
}

// Hàm xuất danh sách phân số
void xuatDanhSachPhanSo(PhanSo a[], int n) {
    for (int i = 0; i < n; i++) {
        xuatPhanSo(a[i]);
        printf("\n");
    }
}

// Hàm so sánh phân số
float giaTriThuc(PhanSo p) {
    return (float)p.tuSo / p.mauSo;
}

// Tìm phân số có giá trị lớn nhất
PhanSo timPhanSoLonNhat(PhanSo a[], int n) {
    PhanSo max = a[0];
    for (int i = 1; i < n; i++) {
        if (giaTriThuc(a[i]) > giaTriThuc(max)) {
            max = a[i];
        }
    }
    return max;
}

// Tìm phân số có giá trị nhỏ nhất
PhanSo timPhanSoNhoNhat(PhanSo a[], int n) {
    PhanSo min = a[0];
    for (int i = 1; i < n; i++) {
        if (giaTriThuc(a[i]) < giaTriThuc(min)) {
            min = a[i];
        }
    }
    return min;
}

// Tính tổng các phân số
PhanSo tongPhanSo(PhanSo a[], int n) {
    PhanSo tong = { 0, 1 }; // Khởi tạo phân số 0/1
    for (int i = 0; i < n; i++) {
        tong.tuSo = tong.tuSo * a[i].mauSo + a[i].tuSo * tong.mauSo;
        tong.mauSo = tong.mauSo * a[i].mauSo;
        tong = toiGianPhanSo(tong);
    }
    return tong;
}

// Tính tích các phân số
PhanSo tichPhanSo(PhanSo a[], int n) {
    PhanSo tich = { 1, 1 }; // Khởi tạo phân số 1/1
    for (int i = 0; i < n; i++) {
        tich.tuSo *= a[i].tuSo;
        tich.mauSo *= a[i].mauSo;
        tich = toiGianPhanSo(tich);
    }
    return tich;
}

// Xuất nghịch đảo phân số
void nghichDaoDanhSach(PhanSo a[], int n) {
    for (int i = 0; i < n; i++) {
        int temp = a[i].tuSo;
        a[i].tuSo = a[i].mauSo;
        a[i].mauSo = temp;
        a[i] = toiGianPhanSo(a[i]);
    }
}

// Hàm hoán đổi 2 phân số
void swap(PhanSo* a, PhanSo* b) {
    PhanSo temp = *a;
    *a = *b;
    *b = temp;
}

// Sắp xếp mảng tăng dần theo giá trị thực
void sapXepTangDan(PhanSo a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTriThuc(a[i]) > giaTriThuc(a[j])) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

// Sắp xếp mảng giảm dần theo giá trị thực
void sapXepGiamDan(PhanSo a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTriThuc(a[i]) < giaTriThuc(a[j])) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

// Hàm chính
int main() {
    PhanSo a[50];
    int n;

    printf("Nhap so luong phan so (n <= 50): ");
    scanf("%d", &n);

    // Nhập danh sách phân số
    nhapDanhSachPhanSo(a, n);

    // Xuất danh sách phân số
    printf("Danh sach phan so:\n");
    xuatDanhSachPhanSo(a, n);

    // Tìm phân số lớn nhất
    PhanSo max = timPhanSoLonNhat(a, n);
    printf("Phan so lon nhat: ");
    xuatPhanSo(max);
    printf("\n");

    // Tìm phân số nhỏ nhất
    PhanSo min = timPhanSoNhoNhat(a, n);
    printf("Phan so nho nhat: ");
    xuatPhanSo(min);
    printf("\n");

    // Tính tổng các phân số
    PhanSo tong = tongPhanSo(a, n);
    printf("Tong cac phan so: ");
    xuatPhanSo(tong);
    printf("\n");

    // Tính tích các phân số
    PhanSo tich = tichPhanSo(a, n);
    printf("Tich cac phan so: ");
    xuatPhanSo(tich);
    printf("\n");

    // Xuất nghịch đảo các phân số
    printf("Danh sach nghich dao cua cac phan so:\n");
    nghichDaoDanhSach(a, n);
    xuatDanhSachPhanSo(a, n);

    // Sắp xếp mảng tăng dần
    sapXepTangDan(a, n);
    printf("Danh sach phan so sap xep tang dan:\n");
    xuatDanhSachPhanSo(a, n);

    // Sắp xếp mảng giảm dần
    sapXepGiamDan(a, n);
    printf("Danh sach phan so sap xep giam dan:\n");
    xuatDanhSachPhanSo(a, n);

    return 0;
}