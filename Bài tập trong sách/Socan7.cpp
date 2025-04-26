#include <iostream>
using namespace std;
//Mabai: SoCan7

class SoCan7 {
    int a, b; // dai dien cho a + b√7
public:
    //get-set
    void setA(int _a) { a = _a; }
    void setB(int _b) { b = _b; }
    int getA() { return a; }
    int getB() { return b; }

    //ktao
    SoCan7(int _a = 0, int _b = 0) {
        a = _a; b = _b;
    }
    SoCan7(const SoCan7& x) {
        a = x.a; b = x.b;
    }

    //nhap - xuat
    friend istream& operator>>(istream& is, SoCan7& x) {
        is >> x.a >> x.b;
        return is;
    }
    friend ostream& operator<<(ostream& os, SoCan7 x) {
        os << x.a << " + " << x.b << "√7";
        return os;
    }

    //cac phep toan
    SoCan7 operator+(SoCan7 x) {
        return SoCan7(a + x.a, b + x.b);
    }
    SoCan7 operator-(SoCan7 x) {
        return SoCan7(a - x.a, b - x.b);
    }
    SoCan7 operator-() {
        return SoCan7(-a, -b);
    }
    SoCan7 operator*(SoCan7 x) {
        int m = a * x.a + 7 * b * x.b;
        int n = a * x.b + b * x.a;
        return SoCan7(m, n);
    }
};

int main() {
    SoCan7 x, y;
    cin >> x >> y;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << "x + y = " << x + y << endl;
    cout << "x - y = " << x - y << endl;
    cout << "-x = " << -x << endl;
    cout << "x * y = " << x * y << endl;

    return 0;
}