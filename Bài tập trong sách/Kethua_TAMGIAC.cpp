#include <iostream> 
#include <cmath>   
using namespace std; 

// Lớp TamGiac biểu diễn một tam giác với ba cạnh
class TamGiac {
private:
    double a, b, c; 

public:
    // Hàm khởi tạo: Khởi tạo tam giác với các cạnh (mặc định là 0)
    TamGiac(double x_tam = 0, double y_tam = 0, double z_tam = 0) : a(x_tam), b(y_tam), c(z_tam) {}

    // Hàm sao chép (copy constructor)
    TamGiac(const TamGiac& tg) : a(tg.a), b(tg.b), c(tg.c) {}

    // Hàm lấy giá trị các cạnh
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    // Hàm thiết lập giá trị cho các cạnh
    void setA(double value) { a = value; }
    void setB(double value) { b = value; }
    void setC(double value) { c = value; }

    // Phương thức tính chu vi tam giác
    double tinhChuVi() const {
        return a + b + c; 
    }

    // Phương thức tính diện tích tam giác theo công thức Heron
    double tinhDienTich() const {
        double p = tinhChuVi() / 2; 
        return sqrt(p * (p - a) * (p - b) * (p - c)); 
    }

    // Phương thức nhập tam giác
    void input() {
        cout << "Nhap do dai 3 canh cua tam giac:" << endl;
        cout << "Nhap canh a: ";
        cin >> a;
        cout << "Nhap canh b: ";
        cin >> b;
        cout << "Nhap canh c: ";
        cin >> c;
    }

    // Phương thức xuất thông tin tam giác
    void print() const {
        cout << "Tam giac voi cac canh: " << endl;
        cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
        cout << "Chu vi: " << tinhChuVi() << endl;
        cout << "Dien tich: " << tinhDienTich() << endl;
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& is, TamGiac& tg) {
        tg.input();
        return is;
    }

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& os, const TamGiac& tg) {
        tg.print();
        return os;
    }
};

// Lớp TamGiacDeu kế thừa từ lớp TamGiac
class TamGiacDeu : public TamGiac {
public:
    // Hàm khởi tạo: Khởi tạo tam giác đều với một cạnh (mặc định là 0)
    TamGiacDeu(double canh = 0) : TamGiac(canh, canh, canh) {}

    // Hàm sao chép (copy constructor)
    TamGiacDeu(const TamGiacDeu& tg) : TamGiac(tg) {}

    // Hàm thiết lập cạnh tam giác đều
    void setCanh(double canh_tam) {
        setA(canh_tam); 
        setB(canh_tam); 
        setC(canh_tam); 
    }

    // Phương thức nhập tam giác đều
    void input() {
        double canh; 
        cout << "Nhap do dai canh cua tam giac deu: ";
        cin >> canh;
        setCanh(canh); 
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& is, TamGiacDeu& tg) {
        tg.input();
        return is;
    }

    // Phương thức xuất thông tin tam giác đều
    void print() const {
        cout << "Tam giac deu voi canh: " << getA() << endl;
        cout << "Chu vi: " << tinhChuVi() << endl;
        cout << "Dien tich: " << tinhDienTich() << endl;
    }

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& os, const TamGiacDeu& tg) {
        tg.print();
        return os;
    }
};


int main() {
    TamGiacDeu tg; 
    cin >> tg; 
    cout << tg; 
    return 0;
}
