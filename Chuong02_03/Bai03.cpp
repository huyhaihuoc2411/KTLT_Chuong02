#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 100

// Cấu trúc thông tin sinh viên
typedef struct {
    int stt;                    // Số thứ tự
    char mssv[20];              // Mã số sinh viên
    char hoTen[50];             // Họ tên sinh viên
    float diemTieuLuan;         // Điểm tiểu luận
    float diemThiKetThucMon;    // Điểm thi kết thúc môn
    float diemTongKet;          // Điểm tổng kết
    float diemHe4;              // Điểm hệ 4
} SinhVien;

// 1. Hàm nhập thông tin sinh viên
void nhapSinhVien(SinhVien* sv, int stt) {
    sv->stt = stt;
    printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->mssv);
    getchar();  // Xử lý ký tự newline
    printf("Nhap ho ten sinh vien: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = '\0';  // Xóa ký tự newline cuối chuỗi
    printf("Nhap diem tieu luan: ");
    scanf("%f", &sv->diemTieuLuan);
    printf("Nhap diem thi ket thuc mon: ");
    scanf("%f", &sv->diemThiKetThucMon);
}

// 1. Hàm xuất thông tin sinh viên
void xuatSinhVien(SinhVien sv) {
    printf("%-5d %-15s %-30s %-15.2f %-15.2f %-15.2f %-10.2f\n",
        sv.stt, sv.mssv, sv.hoTen, sv.diemTieuLuan, sv.diemThiKetThucMon, sv.diemTongKet, sv.diemHe4);
}

// 2. Tính điểm tổng kết
void tinhDiemTongKet(SinhVien* sv) {
    sv->diemTongKet = 0.3 * sv->diemTieuLuan + 0.7 * sv->diemThiKetThucMon;
}

// 3. Tìm sinh viên có điểm cao nhất và thấp nhất
void timSinhVienMaxMin(SinhVien sv[], int n) {
    SinhVien svMax = sv[0], svMin = sv[0];
    for (int i = 1; i < n; i++) {
        if (sv[i].diemTongKet > svMax.diemTongKet) {
            svMax = sv[i];
        }
        if (sv[i].diemTongKet < svMin.diemTongKet) {
            svMin = sv[i];
        }
    }
    printf("\nSinh vien co diem tong ket cao nhat:\n");
    xuatSinhVien(svMax);
    printf("\nSinh vien co diem tong ket thap nhat:\n");
    xuatSinhVien(svMin);
}

// 4. Đếm số sinh viên đạt và không đạt
void demSinhVienDatKhongDat(SinhVien sv[], int n) {
    int dat = 0, khongDat = 0;
    for (int i = 0; i < n; i++) {
        if (sv[i].diemTongKet >= 5.0) {
            dat++;
        }
        else {
            khongDat++;
        }
    }
    printf("\nSo sinh vien dat: %d\n", dat);
    printf("So sinh vien khong dat: %d\n", khongDat);
}

// 5. Qui đổi điểm từ hệ 10 sang hệ 4
void quiDoiDiemHe4(SinhVien* sv) {
    float diem = sv->diemTongKet;
    if (diem >= 8.5) {
        sv->diemHe4 = 4.0;
    }
    else if (diem >= 7.0) {
        sv->diemHe4 = 3.0;
    }
    else if (diem >= 5.5) {
        sv->diemHe4 = 2.0;
    }
    else if (diem >= 4.0) {
        sv->diemHe4 = 1.0;
    }
    else {
        sv->diemHe4 = 0.0;
    }
}

// 6. Sắp xếp danh sách sinh viên tăng/giảm dần theo điểm tổng kết
void sapXepTangDan(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diemTongKet > sv[j].diemTongKet) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

void sapXepGiamDan(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diemTongKet < sv[j].diemTongKet) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

// 7. Tính điểm trung bình của tất cả sinh viên
float tinhDiemTrungBinh(SinhVien sv[], int n) {
    float tongDiem = 0;
    for (int i = 0; i < n; i++) {
        tongDiem += sv[i].diemTongKet;
    }
    return tongDiem / n;
}

// 8. Nhập xuất dữ liệu từ file txt
void ghiFile(SinhVien sv[], int n, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong mo duoc file de ghi.\n");
        return;
    }
    fprintf(file, "%-5s %-15s %-30s %-15s %-15s %-15s %-10s\n",
        "STT", "Ma SV", "Ho ten", "Diem TL", "Diem KT", "Diem TK", "Diem He 4");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%-5d %-15s %-30s %-15.2f %-15.2f %-15.2f %-10.2f\n",
            sv[i].stt, sv[i].mssv, sv[i].hoTen, sv[i].diemTieuLuan,
            sv[i].diemThiKetThucMon, sv[i].diemTongKet, sv[i].diemHe4);
    }
    fclose(file);
    printf("Da ghi du lieu vao file %s.\n", filename);
}

void docFile(SinhVien sv[], int* n, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong mo duoc file de doc.\n");
        return;
    }
    *n = 0;
    char buffer[200];
    fgets(buffer, sizeof(buffer), file);  // Đọc bỏ dòng tiêu đề
    while (fscanf(file, "%d %s %[^\n]%*c %f %f %f %f",
        &sv[*n].stt, sv[*n].mssv, sv[*n].hoTen,
        &sv[*n].diemTieuLuan, &sv[*n].diemThiKetThucMon,
        &sv[*n].diemTongKet, &sv[*n].diemHe4) != EOF) {
        (*n)++;
    }
    fclose(file);
    printf("Da doc du lieu tu file %s.\n", filename);
}

// Hàm hiển thị menu và xử lý lựa chọn
void menu() {
    SinhVien sv[MAX];
    int n = 0;
    int choice;
    do {
        printf("\n==== MENU ====\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tinh diem tong ket cho tung sinh vien\n");
        printf("4. Tim sinh vien co diem cao nhat va thap nhat\n");
        printf("5. Dem so sinh vien dat va khong dat\n");
        printf("6. Qui doi diem tu he 10 sang he 4\n");
        printf("7. Sap xep danh sach sinh vien tang dan theo diem tong ket\n");
        printf("8. Sap xep danh sach sinh vien giam dan theo diem tong ket\n");
        printf("9. Tinh diem trung binh cua tat ca sinh vien\n");
        printf("10. Ghi du lieu vao file\n");
        printf("11. Doc du lieu tu file\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so luong sinh vien: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
                nhapSinhVien(&sv[i], i + 1);
            }
            break;
        case 2:
            printf("\nDanh sach sinh vien:\n");
            printf("%-5s %-15s %-30s %-15s %-15s %-15s %-10s\n",
                "STT", "Ma SV", "Ho ten", "Diem TL", "Diem KT", "Diem TK", "Diem He 4");
            for (int i = 0; i < n; i++) {
                xuatSinhVien(sv[i]);
            }
            break;
        case 3:
            for (int i = 0; i < n; i++) {
                tinhDiemTongKet(&sv[i]);
            }
            printf("Da tinh diem tong ket cho tat ca sinh vien.\n");
            break;
        case 4:
            timSinhVienMaxMin(sv, n);
            break;
        case 5:
            demSinhVienDatKhongDat(sv, n);
            break;
        case 6:
            for (int i = 0; i < n; i++) {
                quiDoiDiemHe4(&sv[i]);
            }
            printf("Da qui doi diem sang he 4 cho tat ca sinh vien.\n");
            break;
        case 7:
            sapXepTangDan(sv, n);
            printf("Da sap xep danh sach sinh vien tang dan theo diem tong ket.\n");
            break;
        case 8:
            sapXepGiamDan(sv, n);
            printf("Da sap xep danh sach sinh vien giam dan theo diem tong ket.\n");
            break;
        case 9:
            printf("Diem trung binh cua tat ca sinh vien: %.2f\n", tinhDiemTrungBinh(sv, n));
            break;
        case 10:
            ghiFile(sv, n, "sinhvien.txt");
            break;
        case 11:
            docFile(sv, &n, "sinhvien.txt");
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}