#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100

// Bài 1: Tính tổng các phần tử nằm trên đường chéo chính
int tongDuongCheoChinh(int a[MAX][MAX], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][i];
    }
    return tong;
}

// Bài 2: Tính tổng các phần tử nằm trên đường chéo phụ
int tongDuongCheoPhu(int a[MAX][MAX], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][n - i - 1];
    }
    return tong;
}

// Bài 3: Tính tổng các phần tử nằm phía trên đường chéo chính
int tongPhiaTrenDuongCheoChinh(int a[MAX][MAX], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tong += a[i][j];
        }
    }
    return tong;
}

// Bài 4: Tính tổng các phần tử nằm phía trên đường chéo phụ
int tongPhiaTrenDuongCheoPhu(int a[MAX][MAX], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            tong += a[i][j];
        }
    }
    return tong;
}

int main() {
    int a[MAX][MAX], n;

    // Nhập kích thước ma trận vuông
    printf("Nhap kich thuoc ma tran vuong n: ");
    scanf("%d", &n);

    // Nhập các phần tử của ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap phan tu a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Bài 1: Tính tổng các phần tử nằm trên đường chéo chính
    int tongChinh = tongDuongCheoChinh(a, n);
    printf("Tong cac phan tu tren duong cheo chinh: %d\n", tongChinh);

    // Bài 2: Tính tổng các phần tử nằm trên đường chéo phụ
    int tongPhu = tongDuongCheoPhu(a, n);
    printf("Tong cac phan tu tren duong cheo phu: %d\n", tongPhu);

    // Bài 3: Tính tổng các phần tử nằm phía trên đường chéo chính
    int tongTrenChinh = tongPhiaTrenDuongCheoChinh(a, n);
    printf("Tong cac phan tu nam phia tren duong cheo chinh: %d\n", tongTrenChinh);

    // Bài 4: Tính tổng các phần tử nằm phía trên đường chéo phụ
    int tongTrenPhu = tongPhiaTrenDuongCheoPhu(a, n);
    printf("Tong cac phan tu nam phia tren duong cheo phu: %d\n", tongTrenPhu);

    return 0;
}