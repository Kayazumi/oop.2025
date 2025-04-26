#include <iostream>
using namespace std;

// Lớp PhanSo
class PS {
    int tu, mau;
public:
    int getTu() { return tu; };
    void setTu(int x) { tu = x; };
    int getMau() { return mau; };
    void setMau(int x) { mau = x; };

    PS(int _tu = 0, int _mau = 1) { tu = _tu; mau = _mau; };
    PS(const PS& p) { tu = p.tu; mau = p.mau; };
    ~PS() {};

    friend istream& operator>>(istream& in, PS& p) {
        in >> p.tu >> p.mau;
        return in;
    };
    friend ostream& operator<<(ostream& out, PS p) {
        out << p.tu << "/" << p.mau << endl;
        return out;
    };

    PS operator+(PS p) {
        return PS(tu * p.mau + p.tu * mau, mau * p.mau);
    };
};

// Lớp HonSo kế thừa PhanSo
class HS : public PS {
    int nguyen;
public:
    int getNguyen() { return nguyen; };
    void setNguyen(int x) { nguyen = x; };

    HS(int _nguyen = 0, int _tu = 0, int _mau = 1) : PS(_tu, _mau) {
        nguyen = _nguyen;
    }
    HS(const HS& h) : PS(h) {
        nguyen = h.nguyen;
    }

    ~HS() {};

    friend istream& operator>>(istream& in, HS& h) {
        int nguyen, tu, mau;
        in >> nguyen >> tu >> mau;
        h = HS(nguyen, tu, mau);
        return in;
    };
    friend ostream& operator<<(ostream& out, HS h) {
        out << h.nguyen << " " << h.getTu() << "/" << h.getMau() << endl;
        return out;
    };

    HS operator+(HS h) {
        return HS(nguyen + h.nguyen, getTu() * h.getMau() + h.getTu() * getMau(), getMau() * h.getMau());
    };
};

int main() {
    HS h1, h2;
    cin >> h1 >> h2;
    cout << (h1 + h2);

    return 0;
}