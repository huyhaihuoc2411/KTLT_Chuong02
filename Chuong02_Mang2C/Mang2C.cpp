#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX 100

// Hàm kiểm tra chữ số đầu tiên có phải là số lẻ
int chuSoDauLe(int num) {
    if (num < 0) num = -num;
    while (num >= 10) {
        num /= 10;
    }
    return num % 2 != 0;
}

// Hàm kiểm tra số hoàn thiện
int laSoHoanThien(int num) {
    if (num <= 0) return 0;
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

// Hàm kiểm tra số nguyên tố
int laSoNguyenTo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
int tongChuSoDauLe(int a[MAX][MAX], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (chuSoDauLe(a[i][j])) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

// Bài 2: Liệt kê các số hoàn thiện trong ma trận
void lietKeSoHoanThien(int a[MAX][MAX], int m, int n) {
    printf("Cac so hoan thien trong ma tran: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(a[i][j])) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

// Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int tongLonHonLienSau(int a[MAX][MAX], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] > abs(a[i][j + 1])) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

// Bài 4: Tính tổng giá trị trên dòng k của ma trận
int tongDongK(int a[MAX][MAX], int m, int n, int k) {
    int sum = 0;
    if (k >= 0 && k < m) {
        for (int j = 0; j < n; j++) {
            sum += a[k][j];
        }
    }
    return sum;
}

// Bài 5: Tính tổng các giá trị nằm trên biên của ma trận
int tongBienMaTran(int a[MAX][MAX], int m, int n) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += a[0][j] + a[m - 1][j]; // hàng đầu và cuối
    }
    for (int i = 1; i < m - 1; i++) {
        sum += a[i][0] + a[i][n - 1]; // cột đầu và cuối
    }
    return sum;
}

// Bài 6: Đếm tần suất xuất hiện của 1 giá trị x trong ma trận
int demTanSuatX(int a[MAX][MAX], int m, int n, int x) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                count++;
            }
        }
    }
    return count;
}

// Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
void demSoLuong(int a[MAX][MAX], int m, int n) {
    int soChan = 0, soLe = 0, soAm = 0, soDuong = 0, soNguyenTo = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) soChan++;
            if (a[i][j] % 2 != 0) soLe++;
            if (a[i][j] < 0) soAm++;
            if (a[i][j] > 0) soDuong++;
            if (laSoNguyenTo(a[i][j])) soNguyenTo++;
        }
    }
    printf("So phan tu chan: %d\n", soChan);
    printf("So phan tu le: %d\n", soLe);
    printf("So phan tu am: %d\n", soAm);
    printf("So phan tu duong: %d\n", soDuong);
    printf("So phan tu la so nguyen to: %d\n", soNguyenTo);
}

int main() {
    int a[MAX][MAX], m, n, k, x;

    // Nhập kích thước mảng
    printf("Nhap so hang m: ");
    scanf("%d", &m);
    printf("Nhap so cot n: ");
    scanf("%d", &n);

    // Nhập các phần tử của mảng
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap phan tu a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
    printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tongChuSoDauLe(a, m, n));

    // Bài 2: Liệt kê các số hoàn thiện trong ma trận
    lietKeSoHoanThien(a, m, n);

    // Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
    printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: %d\n", tongLonHonLienSau(a, m, n));

    // Bài 4: Tính tổng giá trị trên dòng k của ma trận
    printf("Nhap dong k: ");
    scanf("%d", &k);
    printf("Tong gia tri tren dong %d cua ma tran: %d\n", k, tongDongK(a, m, n, k));

    // Bài 5: Tính tổng các giá trị nằm trên biên của ma trận
    printf("Tong cac gia tri nam tren bien cua ma tran: %d\n", tongBienMaTran(a, m, n));

    // Bài 6: Đếm tần suất xuất hiện của 1 giá trị x trong ma trận
    printf("Nhap gia tri x: ");
    scanf("%d", &x);
    printf("Tan suat xuat hien cua %d trong ma tran: %d\n", x, demTanSuatX(a, m, n, x));

    // Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
    demSoLuong(a, m, n);

    return 0;
}