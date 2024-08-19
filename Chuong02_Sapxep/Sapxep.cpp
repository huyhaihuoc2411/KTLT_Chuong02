#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100

// Hàm hoán đổi hai số nguyên
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp một mảng theo thứ tự tăng dần
void sapXepTangDan(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Hàm sắp xếp một mảng theo thứ tự giảm dần
void sapXepGiamDan(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Bài 1: Sắp xếp các phần tử trong ma trận sao cho dòng chẵn tăng, dòng lẻ giảm
void sapXepDongChanTangLeGiam(int a[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sapXepTangDan(a[i], m);
        }
        else {
            sapXepGiamDan(a[i], m);
        }
    }
}

// Bài 2: Sắp xếp các phần tử trong ma trận sao cho cột chẵn tăng, cột lẻ giảm
void sapXepCotChanTangLeGiam(int a[MAX][MAX], int n, int m) {
    for (int j = 0; j < m; j++) {
        int col[MAX];
        for (int i = 0; i < n; i++) {
            col[i] = a[i][j];
        }

        if (j % 2 == 0) {
            sapXepTangDan(col, n);
        }
        else {
            sapXepGiamDan(col, n);
        }

        for (int i = 0; i < n; i++) {
            a[i][j] = col[i];
        }
    }
}

// Bài 3: Sắp xếp ma trận tăng dần/giảm dần theo zic-zac
void sapXepZicZac(int a[MAX][MAX], int n, int m) {
    int arr[MAX * MAX];
    int index = 0;

    // Chuyển tất cả các phần tử của ma trận vào mảng 1 chiều
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[index++] = a[i][j];
        }
    }

    // Sắp xếp mảng 1 chiều theo thứ tự tăng dần
    sapXepTangDan(arr, index);

    // Chuyển các phần tử đã sắp xếp trở lại vào ma trận theo kiểu zic-zac
    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {  // Dòng chẵn: từ trái qua phải
            for (int j = 0; j < m; j++) {
                a[i][j] = arr[index++];
            }
        }
        else {  // Dòng lẻ: từ phải qua trái
            for (int j = m - 1; j >= 0; j--) {
                a[i][j] = arr[index++];
            }
        }
    }
}

int main() {
    int a[MAX][MAX], n, m;

    // Nhập kích thước mảng
    printf("Nhap so hang n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);

    // Nhập các phần tử của mảng
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap phan tu a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Bài 1: Sắp xếp các phần tử trong ma trận sao cho dòng chẵn tăng, dòng lẻ giảm
    sapXepDongChanTangLeGiam(a, n, m);
    printf("Ma tran sau khi sap xep dong chan tang, dong le giam:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Bài 2: Sắp xếp các phần tử trong ma trận sao cho cột chẵn tăng, cột lẻ giảm
    sapXepCotChanTangLeGiam(a, n, m);
    printf("Ma tran sau khi sap xep cot chan tang, cot le giam:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Bài 3: Sắp xếp ma trận tăng dần theo zic-zac
    sapXepZicZac(a, n, m);
    printf("Ma tran sau khi sap xep zic-zac:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}