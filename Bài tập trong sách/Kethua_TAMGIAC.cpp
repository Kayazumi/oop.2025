#include <iostream>
#include <cmath>
using namespace std;


class TamGiac {

private:
    double a, b, c; // Ba cạnh của tam giác

public:
    //Hàm khởi tạo

    TamGiac(double x_tam = 0, double y_tam = 0, double z_tam = 0) : a(x_tam), b(y_tam), c(z_tam) {
    }

    //Hàm lấy cạnh
    double getA() const {
        return a;
    }
    double getB() const {
        return b;
    }
    double getC() const {
        return c;
    }

    //Hàm thiết lập độ dài cạnh
    void setA(double value) {
        a = value;
    }
    void setB(double value) {
        b = value;
    }
    void setC(double value) {
        c = value;
    }


    double tinhChuVi() {
        return a + b + c;
    }

    double tinhDienTich() {
        double p = tinhChuVi() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

};

//TamGiacDeu kế thừa các thuộc tính và phương thức của lớp TamGiac
class TamGiacDeu : public TamGiac {
public:

    TamGiacDeu(double canh = 0) : TamGiac(canh, canh, canh) {}

    void setCanh(double canh_tam) {
        setA(canh_tam);
        setB(canh_tam);
        setC(canh_tam);
    }

};

int main() {
    TamGiacDeu tg;
    tg.setCanh(5);
    cout << "Thông tin tam giác đều" << endl;
    cout << "Độ dài cạnh tam giác đều: " << tg.getA() << endl;
    cout << "Chu vi: " << tg.tinhChuVi() << endl;
    cout << "Diện tích: " << tg.tinhDienTich() << endl;
    return 0;
}