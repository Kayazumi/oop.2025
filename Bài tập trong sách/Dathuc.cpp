#include <iostream>
#include <cmath>
using namespace std;

class DaThuc {
    int n;      // Bậc cao nhất của đa thức
    int* data;  // Mảng chứa các hệ số của đa thức (data[k] là hệ số của x^k)

public:
    // Hàm khởi tạo
    DaThuc(int deg = 0) : n(deg) {
        data = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            data[i] = 0;
        }
    }

    // Hàm sao chép
    DaThuc(const DaThuc& dt) : n(dt.n) {
        data = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            data[i] = dt.data[i];
        }
    }

    // Hàm hủy
    ~DaThuc() {
        delete[] data;
    }

    // Phương thức nhập
    void input() {
        cout << "Nhap bac cao nhat cua da thuc: ";
        cin >> n;
        delete[] data;  // Xóa mảng cũ nếu tồn tại
        data = new int[n + 1];
        for (int i = n; i >= 0; i--) {
            cin >> data[i];
        }
    }

    // Phương thức xuất
    void print() const {
        bool firstTerm = true;
        for (int i = n; i >= 0; i--) {
            if (data[i] != 0) {
                if (!firstTerm) {
                    if (data[i] > 0) {
                        cout << " + ";
                    }
                    else {
                        cout << " - ";
                    }
                }
                else {
                    if (data[i] < 0) {
                        cout << "-";
                    }
                }

                if (abs(data[i]) != 1 || i == 0) {
                    cout << abs(data[i]);
                }

                if (i > 0) {
                    cout << "x";
                    if (i > 1) {
                        cout << "^" << i;
                    }
                }

                firstTerm = false;
            }
        }

        if (firstTerm) {
            cout << "0";
        }
    }


    // Toán tử nhập
    friend istream& operator>>(istream& is, DaThuc& dt) {
        dt.input();
        return is;
    }

    // Toán tử xuất
    friend ostream& operator<<(ostream& os, const DaThuc& dt) {
        dt.print();
        return os;
    }

    // Tính giá trị đa thức tại x = val
    double tinhGiaTri(double x) const {
        double result = 0;
        for (int i = 0; i <= n; i++) {
            result += data[i] * pow(x, i);
        }
        return result;
    }

    // Tính đạo hàm
    DaThuc tinhDaoHam() const {
        if (n == 0) {
            return DaThuc(0);
        }
        DaThuc result(n - 1);
        for (int i = 1; i <= n; i++) {
            result.data[i - 1] = data[i] * i;
        }
        return result;
    }

    // Tính tích phân
    DaThuc tinhTichPhan() const {
        DaThuc result(n + 1);
        for (int i = 0; i <= n; i++) {
            result.data[i + 1] = data[i] / (i + 1);
        }
        result.data[0] = 0;  // Hằng số tích phân
        return result;
    }

    // Cộng hai đa thức
    DaThuc operator+(const DaThuc& dt) const {
        int maxDeg;
        if (n > dt.n) {
            maxDeg = n;
        }
        else {
            maxDeg = dt.n;
        }

        DaThuc result(maxDeg);
        for (int i = 0; i <= maxDeg; i++) {
            int a = 0, b = 0;
            if (i <= n) {
                a = data[i];
            }
            if (i <= dt.n) {
                b = dt.data[i];
            }
            result.data[i] = a + b;
        }
        return result;
    }
    // Trừ 
    DaThuc operator-(const DaThuc& dt) const {
        int maxDeg;
        if (n > dt.n) {
            maxDeg = n;
        }
        else {
            maxDeg = dt.n;
        }

        DaThuc result(maxDeg);
        for (int i = 0; i <= maxDeg; i++) {
            int a = 0, b = 0;
            if (i <= n) {
                a = data[i];
            }
            if (i <= dt.n) {
                b = dt.data[i];
            }
            result.data[i] = a - b;
        }
        return result;
    }


    // Nhân hai đa thức
    DaThuc operator*(const DaThuc& dt) const {
        DaThuc result(n + dt.n);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= dt.n; j++) {
                result.data[i + j] += data[i] * dt.data[j];
            }
        }
        return result;
    }

    // Truy cập hệ số theo chỉ số
    int& operator[](int i) {
        static int dummy = 0;
        if (i < 0 || i > n) {
            cout << "Chi so khong hop le!" << endl;
            return dummy;
        }
        return data[i];
    }

    // Tiền tố ++
    DaThuc& operator++() {
        for (int i = 0; i <= n; i++) {
            data[i]++;
        }
        return *this;
    }

    // Hậu tố ++
    DaThuc operator++(int) {
        DaThuc temp = *this;
        ++(*this);
        return temp;
    }

    // Tiền tố --
    DaThuc& operator--() {
        for (int i = 0; i <= n; i++) {
            data[i]--;
        }
        return *this;
    }

    // Hậu tố --
    DaThuc operator--(int) {
        DaThuc temp = *this;
        --(*this);
        return temp;
    }
};

// Chương trình chính
int main() {
    DaThuc dt1, dt2;
    cin >> dt1;
    cin >> dt2;

    cout << "Da thuc thu nhat: " << dt1 << endl;
    cout << "Da thuc thu hai: " << dt2 << endl;

    cout << "Tong hai da thuc: " << dt1 + dt2 << endl;
    cout << "Hieu hai da thuc: " << dt1 - dt2 << endl;
    cout << "Tich hai da thuc: " << dt1 * dt2 << endl;

    double x;
    cout << "Nhap gia tri x de tinh gia tri da thuc thu nhat: ";
    cin >> x;
    cout << "Gia tri cua da thuc thu nhat tai x = " << x << " la: " << dt1.tinhGiaTri(x) << endl;

    cout << "Dao ham cua da thuc thu nhat: " << dt1.tinhDaoHam() << endl;
    cout << "Tich phan cua da thuc thu nhat: " << dt1.tinhTichPhan() << endl;

    cout << "He so cua x^2 trong da thuc thu nhat: " << dt1[1] << endl;
    cout << endl;

    return 0;
}