int n;      // Số lượng sinh viên
public:
    // Phương thức khởi tạo
    MangSinhVien(int _n = 0) : n(_n) {}

    // Phương thức hủy
    ~MangSinhVien() {}

    // Getter và Setter
    int getN() { return n; }
    void setN(int _n) { n = _n; }

    // Toán tử []
    SV& operator[](int index) { return arr[index]; }

    // Toán tử gán =
    MangSinhVien& operator=(const MangSinhVien& msv) {
        if (this != &msv) {
            n = msv.n;
            for (int i = 0; i < n; i++) {
                arr[i] = msv.arr[i];
            }
        }
        return *this;
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& is, MangSinhVien& msv) {
        is >> msv.n;
        is.ignore(); // Consume newline after n
        for (int i = 0; i < msv.n; i++) {
            is >> msv.arr[i];
        }
        return is;
    }

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& os, MangSinhVien msv) {
        for (int i = 0; i < msv.n; i++) {
            os << msv.arr[i];
        }
        return os;
    }

    // Phương thức tính điểm trung bình của mảng
    float DTB() {
        if (n == 0) return 0;
        float sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i].getDiem().DTB();
        }
        return sum / n;
    }

    // Phương thức trả về vị trí sinh viên có điểm trung bình lớn nhất
    int viTriMax() {
        if (n == 0) return -1;
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i].getDiem().DTB() > arr[maxIndex].getDiem().DTB()) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};

int main() {
    MangSinhVien msv;
    cin >> msv;
    cout << msv[msv.viTriMax()];
    return 0;
}