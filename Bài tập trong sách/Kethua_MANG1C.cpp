#include <iostream>
using namespace std;

// Lớp MANG1C
class MANG1C {
protected:
    int sopt;       // Số phần tử
    int data[100];  // Mảng tối đa 100 số nguyên
public:
    int getSopt() { return sopt; };
    void setSopt(int x) { sopt = x; };
    int getData(int idx) { return data[idx]; };
    void setData(int idx, int value) { data[idx] = value; };

    MANG1C(int _sopt = -1) { sopt = _sopt; };
    MANG1C(const MANG1C& m) {
        sopt = m.sopt;
        for (int i = 0; i <= sopt; i++) {
            data[i] = m.data[i];
        }
    };
    ~MANG1C() {}

    friend istream& operator>>(istream& in, MANG1C& m) {
        in >> m.sopt;
        for (int i = 0; i < m.sopt; i++) {
            in >> m.data[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, MANG1C m) {
        for (int i = 0; i < m.sopt; i++) {
            out << m.data[i] << " ";
        }
        out << endl;
        return out;
    }
};

// Lớp STACK kế thừa MANGIC
class STACK : public MANG1C {
public:
    STACK() : MANG1C() {}
    STACK(const STACK& s) : MANG1C(s) {}
    ~STACK() {
        cout << endl;
    }

    int isEmpty() { return (sopt == -1); }

    void push(int value) {
        if (sopt < 99) {
            sopt++;
            data[sopt - 1] = value;
        }
        else {
            cout << "STACK day!" << endl;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "STACK rong!" << endl;
            return -1;
        }
        else {
            int value = data[sopt - 1];
            sopt--;
            return value;
        }
    }

    friend istream& operator>>(istream& in, STACK& s) {
        in >> (MANG1C&)s;
        return in;
    }

    friend ostream& operator<<(ostream& out, STACK s) {
        out << (MANG1C&)s;
        return out;
    }
};

// Lớp BINARY kế thừa STACK
class BINARY : public STACK {
public:
    BINARY() : STACK() {}
    BINARY(const BINARY& b) : STACK(b) {}
    ~BINARY() {
        cout << endl;
    }

    void doiNhiPhan(int n) {
        cout << "Chuyen doi " << n << " sang nhi phan: ";
        while (n > 0) {
            push(n % 2);
            n /= 2;
        }
        while (!isEmpty()) {
            cout << pop();
        }
        cout << endl;
    }
};

// Hàm main có cả STACK và BINARY
int main() {
    // Nhập và xuất STACK
    STACK s;
    cin >> s;
    cout << s;

    // Thêm phần tử vào STACK
    s.push(88);
    s.push(1);
    s.push(12);

    cout << "STACK sau khi push: " << s;

    // Lấy phần tử ra khỏi STACK
    int popped = s.pop();
    cout << "Gia tri pop: " << popped << endl;
    cout << "STACK sau khi pop: " << s;

    // Nhập số và chuyển sang nhị phân
    BINARY b;
    int so;
    cin >> so;
    b.doiNhiPhan(so);

    return 0;
}
