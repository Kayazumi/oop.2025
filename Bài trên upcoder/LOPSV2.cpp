#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Diem {
    int n;
    float arr[100];
public:
    void setN(int value) { n = value; }
    int getN() { return n; }
    float& operator[](int index) { return arr[index]; }

    Diem(int _n = 3, float _arr[] = new float[3] {1, 2, 3}) {
        n = _n;
        for (int i = 0; i < n; i++) arr[i] = _arr[i];
    }
    Diem(const Diem& d) {
        n = d.n;
        for (int i = 0; i < n; i++) arr[i] = d.arr[i];
    }

    // Toán tử gán
    Diem& operator=(const Diem& d) {
        if (this != &d) {
            n = d.n;
            for (int i = 0; i < n; i++) arr[i] = d.arr[i];
        }
        return *this;
    }

    ~Diem() {}

    friend istream& operator>>(istream& is, Diem& d) {
        d.n = 0;
        while (is >> d.arr[d.n] && d.n < 10) d.n++;
        return is;
    }
    friend ostream& operator<<(ostream& os, Diem d) {
        for (int i = 0; i < d.n; i++) os << d.arr[i] << " ";
        os << endl;
        return os;
    }

    // Hàm hỗ trợ
    float DTB() const {
        if (n == 0) return 0;
        float tong = 0;
        for (int i = 0; i < n; i++) tong += arr[i];
        return tong / n;
    }
};

class SinhVien {
    Diem d;
    string hoten, mssv;
public:
    string getHoten() { return hoten; }
    void setHoten(string _hoten) { hoten = _hoten; }
    string getMssv() { return mssv; }
    void setMssv(string _mssv) { mssv = _mssv; }
    Diem getDiem() { return d; }
    void setDiem(Diem _d) { d = _d; }

    SinhVien(const SinhVien& s) { mssv = s.mssv; hoten = s.hoten; d = s.d; }
    SinhVien(string _hoten = "hoten", string _mssv = "mssv", Diem _d = Diem()) {
        hoten = _hoten; mssv = _mssv;   d = _d;
    }

    // Toán tử gán
    SinhVien& operator=(const SinhVien& s) {
        if (this != &s) {
            hoten = s.hoten;
            mssv = s.mssv;
            d = s.d;
        }
        return *this;
    }

    // Toán tử so sánh < dựa vào DTB
    bool operator<(const SinhVien& s) const {
        return d.DTB() < s.d.DTB();
    }

    // Destructor
    ~SinhVien() {}

    // Nhập - Xuất
    friend istream& operator >>(istream& is, SinhVien& s) {
        getline(is, s.hoten);
        is >> s.mssv;
        is >> s.d;
        return is;
    }
    friend ostream& operator <<(ostream& os, SinhVien s) {
        os << "Ho Ten: " << s.hoten << endl;
        os << "Ma Sinh Vien: " << s.mssv << endl;
        os << "DTB: " << fixed << setprecision(1) << s.d.DTB() << endl;
        return os;
    }
};

int main() {
    SinhVien s;
    cin >> s;
    cout << s;
    return 0;
}
