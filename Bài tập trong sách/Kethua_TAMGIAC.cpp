#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra ba cạnh có tạo thành tam giác hợp lệ không
bool kiemTraHopLe(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

class TamGiac {
private:
    double a, b, c;

public:
    TamGiac(double x_tam = 0, double y_tam = 0, double z_tam = 0) : a(x_tam), b(y_tam), c(z_tam) {}

    TamGiac(const TamGiac& tg) : a(tg.a), b(tg.b), c(tg.c) {}

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    void setA(double value) { a = value; }
    void setB(double value) { b = value; }
    void setC(double value) { c = value; }

    double tinhChuVi() const {
        return a + b + c;
    }

    double tinhDienTich() const {
        double p = tinhChuVi() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void input() {
        do {
            cout << "Nhap do dai 3 canh cua tam giac:" << endl;
            cout << "Nhap canh a: "; cin >> a;
            cout << "Nhap canh b: "; cin >> b;
            cout << "Nhap canh c: "; cin >> c;
            if (!kiemTraHopLe(a, b, c)) {
                cout << "Ba canh nhap vao khong tao thanh tam giac. Vui long nhap lai." << endl;
            }
        } while (!kiemTraHopLe(a, b, c));
    }

    void print() const {
        cout << "Tam giac voi cac canh: a = " << a << ", b = " << b << ", c = " << c << endl;
        cout << "Chu vi: " << tinhChuVi() << endl;
        cout << "Dien tich: " << tinhDienTich() << endl;
    }

    friend istream& operator>>(istream& is, TamGiac& tg) {
        tg.input();
        return is;
    }

    friend ostream& operator<<(ostream& os, const TamGiac& tg) {
        tg.print();
        return os;
    }
};

class TamGiacDeu : public TamGiac {
public:
    TamGiacDeu(double canh = 0) : TamGiac(canh, canh, canh) {}

    TamGiacDeu(const TamGiacDeu& tg) : TamGiac(tg) {}

    void setCanh(double canh_tam) {
        setA(canh_tam);
        setB(canh_tam);
        setC(canh_tam);
    }

    void input() {
        double canh;
        cout << "Nhap do dai canh cua tam giac deu: ";
        cin >> canh;
        setCanh(canh);
    }

    void print() const {
        cout << "Tam giac deu voi canh: " << getA() << endl;
        cout << "Chu vi: " << tinhChuVi() << endl;
        cout << "Dien tich: " << tinhDienTich() << endl;
    }

    friend istream& operator>>(istream& is, TamGiacDeu& tg) {
        tg.input();
        return is;
    }

    friend ostream& operator<<(ostream& os, const TamGiacDeu& tg) {
        tg.print();
        return os;
    }
};

int main() {
    TamGiacDeu tg;
    tg.input();
    cout << tg;
    return 0;
}
