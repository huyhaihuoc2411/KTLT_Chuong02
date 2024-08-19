#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define MAX 100

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
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Bài 1: Liệt kê các cột có tổng nhỏ nhất trong ma trận
void lietKeCotTongNhoNhat(int a[MAX][MAX], int m, int n) {
    int minSum = INT_MAX;
    int sumCol[MAX] = { 0 };

    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        sumCol[j] = sum;
        if (sum < minSum) {
            minSum = sum;
        }
    }

    printf("Cac cot co tong nho nhat: ");
    for (int j = 0; j < n; j++) {
        if (sumCol[j] == minSum) {
            printf("%d ", j);
        }
    }
    printf("\n");
}

// Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất trong ma trận
void lietKeDongNhieuSoHoanThienNhat(int a[MAX][MAX], int m, int n) {
    int maxCount = 0;
    int countRow[MAX] = { 0 };

    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(a[i][j])) {
                count++;
            }
        }
        countRow[i] = count;
        if (count > maxCount) {
            maxCount = count;
        }
    }

    printf("Cac dong co nhieu so hoan thien nhat: ");
    for (int i = 0; i < m; i++) {
        if (countRow[i] == maxCount) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void lietKeDongToanChan(int a[MAX][MAX], int m, int n) {
    printf("Cac dong chua toan gia tri chan: ");
    for (int i = 0; i < m; i++) {
        int allEven = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                allEven = 0;
                break;
            }
        }
        if (allEven) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận
int timGiaTriXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int maxCount = 0, value;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int p = 0; p < m; p++) {
                for (int q = 0; q < n; q++) {
                    if (a[p][q] == a[i][j]) {
                        count++;
                    }
                }
            }
            if (count > maxCount) {
                maxCount = count;
                value = a[i][j];
            }
        }
    }
    return value;
}

// Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
int timSoNguyenToNhoNhat(int a[MAX][MAX], int m, int n) {
    int minPrime = INT_MAX;
    int found = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoNguyenTo(a[i][j]) && a[i][j] < minPrime) {
                minPrime = a[i][j];
                found = 1;
            }
        }
    }
    return found ? minPrime : -1;
}

// Bài 6: Tìm phần tử lớn nhất trong dòng thứ k
int timLonNhatDongK(int a[MAX][MAX], int n, int k) {
    int maxVal = a[k][0];
    for (int j = 1; j < n; j++) {
        if (a[k][j] > maxVal) {
            maxVal = a[k][j];
        }
    }
    return maxVal;
}

// Bài 6: Tìm phần tử nhỏ nhất trong dòng thứ k
int timNhoNhatDongK(int a[MAX][MAX], int n, int k) {
    int minVal = a[k][0];
    for (int j = 1; j < n; j++) {
        if (a[k][j] < minVal) {
            minVal = a[k][j];
        }
    }
    return minVal;
}

// Bài 7: Tìm phần tử lớn nhất trong cột thứ k
int timLonNhatCotK(int a[MAX][MAX], int m, int k) {
    int maxVal = a[0][k];
    for (int i = 1; i < m; i++) {
        if (a[i][k] > maxVal) {
            maxVal = a[i][k];
        }
    }
    return maxVal;
}

// Bài 7: Tìm phần tử nhỏ nhất trong cột thứ k
int timNhoNhatCotK(int a[MAX][MAX], int m, int k) {
    int minVal = a[0][k];
    for (int i = 1; i < m; i++) {
        if (a[i][k] < minVal) {
            minVal = a[i][k];
        }
    }
    return minVal;
}

int main() {
    int a[MAX][MAX], m, n, k;

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

    // Bài 1: Liệt kê các cột có tổng nhỏ nhất trong ma trận
    lietKeCotTongNhoNhat(a, m, n);

    // Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất trong ma trận
    lietKeDongNhieuSoHoanThienNhat(a, m, n);

    // Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
    lietKeDongToanChan(a, m, n);

    // Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận
    int giaTriXuatHienNhieuNhat = timGiaTriXuatHienNhieuNhat(a, m, n);
    printf("Gia tri xuat hien nhieu nhat trong ma tran: %d\n", giaTriXuatHienNhieuNhat);

    // Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
    int soNguyenToNhoNhat = timSoNguyenToNhoNhat(a, m, n);
    if (soNguyenToNhoNhat != -1) {
        printf("So nguyen to nho nhat trong ma tran: %d\n", soNguyenToNhoNhat);
    }
    else {
        printf("Khong co so nguyen to trong ma tran\n");
    }

    // Bài 6: Tìm phần tử lớn (nhỏ) nhất trong dòng thứ k
    printf("Nhap dong k: ");
    scanf("%d", &k);
    printf("Phan tu lon nhat trong dong %d: %d\n", k, timLonNhatDongK(a, n, k));
    printf("Phan tu nho nhat trong dong %d: %d\n", k, timNhoNhatDongK(a, n, k));

    // Bài 7: Tìm phần tử lớn (nhỏ) nhất trong cột thứ k
    printf("Nhap cot k: ");
    scanf("%d", &k);
    printf("Phan tu lon nhat trong cot %d: %d\n", k, timLonNhatCotK(a, m, k));
    printf("Phan tu nho nhat trong cot %d: %d\n", k, timNhoNhatCotK(a, m, k));

    return 0;
}