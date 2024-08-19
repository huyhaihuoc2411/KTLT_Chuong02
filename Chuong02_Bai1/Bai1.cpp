#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Kiểm tra các chữ số của số có phải là số lẻ không
bool isAllOddDigits(int n) {
    n = abs(n);  // Xử lý số âm
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) return false;  // Nếu gặp chữ số chẵn thì return false
        n /= 10;
    }
    return true;
}

// Hàm chính
int main() {
    int a[] = { 13, 25, 18, 7, 19, 2, 5 };
    int n = sizeof(a) / sizeof(a[0]);

    // 1. Đếm số phần tử có giá trị là số nguyên tố trong mảng a
    int primeCount = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            primeCount++;
        }
    }
    printf("So phan tu la so nguyen to trong mang: %d\n", primeCount);

    // 2. Xuất các phần tử mà từng chữ số của nó là số lẻ
    printf("Cac phan tu co toan chu so le: ");
    for (int i = 0; i < n; i++) {
        if (isAllOddDigits(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");

    // 3. Tìm vị trí số lớn nhất (cuối cùng) của mảng
    int maxVal = a[0];
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] >= maxVal) {  // Tìm vị trí cuối cùng của số lớn nhất
            maxVal = a[i];
            maxIndex = i;
        }
    }
    printf("Vi tri so lon nhat cuoi cung trong mang: %d\n", maxIndex);

    // 4. Kiểm tra mảng có toàn là số chẵn không?
    bool allEven = true;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            allEven = false;
            break;
        }
    }
    if (allEven) {
        printf("Mang co toan so chan.\n");
    }
    else {
        printf("Mang khong co toan so chan.\n");
    }

    // 5. Kiểm tra mảng có phải là dãy số chẵn lẻ xen kẽ không?
    bool isAlternate = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] % 2 == a[i + 1] % 2) {  // Kiểm tra nếu 2 số liên tiếp cùng chẵn hoặc cùng lẻ
            isAlternate = false;
            break;
        }
    }
    if (isAlternate) {
        printf("Mang la day so chan le xen ke.\n");
    }
    else {
        printf("Mang khong phai la day so chan le xen ke.\n");
    }

    return 0;
}