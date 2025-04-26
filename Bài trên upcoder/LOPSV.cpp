#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Lớp người
class Nguoi {
protected:
    string hoTen;
    int namSinh;
    string queQuan;

public:
    Nguoi() {
        hoTen = "";
        namSinh = 0;
        queQuan = "";
    }

    Nguoi(string _hoTen, int _namSinh, string _queQuan) {
        hoTen = _hoTen;
        namSinh = _namSinh;
        queQuan = _queQuan;
    }

    ~Nguoi() {}

    string getHoTen() { return hoTen; }
    int getNamSinh() { return namSinh; }
    string getQueQuan() { return queQuan; }

    void setHoTen(string _hoTen) { hoTen = _hoTen; }
    void setNamSinh(int _namSinh) { namSinh = _namSinh; }
    void setQueQuan(string _queQuan) { queQuan = _queQuan; }

    void nhap() {
        getline(cin, hoTen);
        cin >> namSinh;
        cin.ignore(); // bỏ dòng sau năm sinh
        getline(cin, queQuan);
    }

    void xuat() {
        cout << "Ho Ten: " << hoTen << endl;
        cout << "Nam Sinh: " << namSinh << endl;
        cout << "Que quan: " << queQuan << endl;
    }
};

// Lớp sinh viên
class SinhVien : public Nguoi {
private:
    string khoa;
    float diem[100];
    int soMon;

public:
    SinhVien() : Nguoi() {
        khoa = "";
        soMon = 0;
    }

    SinhVien(string _hoTen, int _namSinh, string _queQuan, string _khoa)
        : Nguoi(_hoTen, _namSinh, _queQuan) {
        khoa = _khoa;
        soMon = 0;
    }

    ~SinhVien() {}

    string getKhoa() { return khoa; }
    void setKhoa(string _khoa) { khoa = _khoa; }

    float tinhDiemTB() const {
        if (soMon == 0) return 0.0f;
        float tong = 0;
        for (int i = 0; i < soMon; i++) tong += diem[i];
        return tong / soMon;
    }

    void nhap() {
        Nguoi::nhap();
        getline(cin, khoa);
        soMon = 0;
        while (cin >> diem[soMon]) {
            soMon++;
            char c;
            if (cin.get(c) && c == '\n') break;
        }
    }

    void xuat() {
        Nguoi::xuat();
        cout << "Khoa: " << khoa << endl;
        cout << "Diem cac mon:";
        for (int i = 0; i < soMon; i++) {
            cout << " " << fixed << setprecision(0) << diem[i];
        }
        cout << endl;
        cout << "Diem trung binh: " << fixed << setprecision(2) << tinhDiemTB() << endl;
    }
};

int main() {
    SinhVien sv;
    sv.nhap();
    sv.xuat();
    return 0;
}