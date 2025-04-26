#include <iostream>
#include <iomanip>
using namespace std;

class Mang {
    int a[100]; // mảng tối đa 100 phần tử
    int n;      // số lượng phần tử hiện có
public:
    // Constructor
    Mang(int _n = 0, int _a[] = new int[100] {}) {
        n = _n;
        for (int i = 0; i < n; i++)
            a[i] = _a[i];
    }

    // Copy constructor
    Mang(const Mang& m) {
        n = m.n;
        for (int i = 0; i < n; i++)
            a[i] = m.a[i];
    }

    // Nhập mảng
    friend istream& operator>>(istream& is, Mang& m) {
        cout << "Nhap so phan tu: ";
        is >> m.n;
        cout << "Nhap " << m.n << " phan tu: ";
        for (int i = 0; i < m.n; i++)
            is >> m.a[i];
        return is;
    }

    // Xuất mảng
    friend ostream& operator<<(ostream& os, Mang m) {
        for (int i = 0; i < m.n; i++)
            os << m.a[i] << " ";
        os << endl;
        return os;
    }

    // Lấy số phần tử
    int getSize() { return n; }

    // Lấy giá trị phần tử thứ i
    int getAt(int i) {
        if (i >= 0 && i < n)
            return a[i];
        return -1; // lỗi nếu vượt chỉ số
    }

    // Thêm vào cuối
    void them(int x) {
        if (n < 100)
            a[n++] = x;
    }

    // Thêm vào vị trí i
    void themTai(int i, int x) {
        if (n >= 100 || i < 0 || i > n) {
            cout << "Vi tri chen khong hop le!" << endl;
            return;
        }
        for (int j = n; j > i; j--)
            a[j] = a[j - 1];
        a[i] = x;
        n++;
    }

    // Xóa tại vị trí i
    void xoa(int i) {
        if (i < 0 || i >= n) {
            cout << "Vi tri xoa khong hop le!" << endl;
            return;
        }
        for (int j = i; j < n - 1; j++)
            a[j] = a[j + 1];
        n--;
    }

    // Hủy mảng
    void huy() {
        n = 0;
    }

    // Sắp xếp tăng dần
    void sapXep() {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j])
                    swap(a[i], a[j]);
    }

    // Tìm phần tử nhỏ nhất
    int timMin() {
        if (n == 0) return -1;
        int min = a[0];
        for (int i = 1; i < n; i++)
            if (a[i] < min) min = a[i];
        return min;
    }

    // Tính tổng các phần tử
    int tinhTong() {
        int tong = 0;
        for (int i = 0; i < n; i++)
            tong += a[i];
        return tong;
    }
};

// Hàm main để test
int main() {
    Mang m;
    cin >> m;

    cout << "\nMang vua nhap: ";
    cout << m;

    cout << "So phan tu: " << m.getSize() << endl;

    int x, i;
    cout << "\nNhap gia tri x can them: ";
    cin >> x;
    cout << "Nhap vi tri i muon them vao: ";
    cin >> i;
    m.themTai(i, x);
    cout << "Mang sau khi them " << x << " vao vi tri " << i << ": ";
    cout << m;

    cout << "\nNhap vi tri can xoa: ";
    cin >> i;
    m.xoa(i);
    cout << "Mang sau khi xoa vi tri " << i << ": ";
    cout << m;

    cout << "\nTong cac phan tu: " << m.tinhTong() << endl;
    cout << "Phan tu nho nhat: " << m.timMin() << endl;

    m.sapXep();
    cout << "Mang sau khi sap xep tang dan: ";
    cout << m;

    m.huy();
    cout << "Mang sau khi huy: ";
    cout << m;

    return 0;
}