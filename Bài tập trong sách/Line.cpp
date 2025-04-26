/*
Câu 4: Xây dựng lớp Line để biểu diễn các đối tượng đường thẳng với thành phần dữ liệu và các hàm sau:

a) Thành phần dữ liệu: A (điểm A) và B (điểm B) là hai Point.

b) Các hàm:
Phương thức thiết lập và phương thức hủy bỏ.

Hàm void set(int, int, int, int) để xác định đoạn thẳng.

Hàm float tinhDoDai() để tính độ dài đoạn thẳng.

Hàm void print() để xuất thông tin đường thẳng.

Hàm void xuatPhuongTrinh() để xuất phương trình đường thẳng.
*/


#include <iostream>
#include <cmath>
using namespace std;

class Line {
    float Ax, Ay;  // Tọa độ điểm A
    float Bx, By;  // Tọa độ điểm B

public:
    // Hàm khởi tạo mặc định và có tham số
    Line(float x1 = 0, float y1 = 0, float x2 = 0, float y2 = 0) {
        Ax = x1; Ay = y1;
        Bx = x2; By = y2;
    }

    // Hàm khởi tạo sao chép
    Line(const Line& line) {
        Ax = line.Ax; Ay = line.Ay;
        Bx = line.Bx; By = line.By;
    }

    // Hàm hủy
    ~Line() {}

    // Hàm set để thiết lập tọa độ của đoạn thẳng
    void set(int x1, int y1, int x2, int y2) {
        Ax = x1; Ay = y1;
        Bx = x2; By = y2;
    }

    // Hàm tính độ dài đoạn thẳng
    float tinhDoDai() const {
        float dx = Bx - Ax;
        float dy = By - Ay;
        return sqrt(dx * dx + dy * dy);
    }

    // Hàm xuất phương trình đường thẳng
    void xuatPhuongTrinh() const {
        if (Ax == Bx) {
            cout << "x = " << Ax;  // Đường thẳng đứng
        }
        else if (Ay == By) {
            cout << "y = " << Ay;  // Đường thẳng ngang
        }
        else {
            float m = (By - Ay) / (Bx - Ax);  // Hệ số góc
            float c = Ay - m * Ax;  // Hằng số c trong y = mx + c
            cout << "y = " << m << "x ";
            if (c > 0) cout << "+ " << c;
            else if (c < 0) cout << "- " << abs(c);
            cout << endl;
        }
    }

    // Hàm print để xuất thông tin đoạn thẳng
    void print() const {
        cout << "Toa do diem A: (" << Ax << ", " << Ay << ")" << endl;
        cout << "Toa do diem B: (" << Bx << ", " << By << ")" << endl;
        cout << "Do dai doan thang: " << tinhDoDai() << endl;
        cout << "Phuong trinh duong thang: ";
        xuatPhuongTrinh();
    }

    // Toán tử nhập
    friend istream& operator>>(istream& in, Line& line) {
        in >> line.Ax >> line.Ay;
        in >> line.Bx >> line.By;
        return in;
    }

    // Toán tử xuất
    friend ostream& operator<<(ostream& out, const Line& line) {
        out << "Diem A: (" << line.Ax << ", " << line.Ay << ")" << endl;
        out << "Diem B: (" << line.Bx << ", " << line.By << ")" << endl;
        out << "Do dai: " << line.tinhDoDai() << endl;
        out << "Phuong trinh: ";
        line.xuatPhuongTrinh();
        return out;
    }
};
int main() {
    Line line;
    cin >> line;  // Nhập dữ liệu
    cout << line; // Xuất dữ liệu
    return 0;
}