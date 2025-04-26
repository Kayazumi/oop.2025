#include <iostream>  // Thư viện dùng để nhập/xuất dữ liệu (cin, cout)
#include <cmath>     // Thư viện toán học (dùng cho hàm abs)
using namespace std; // Giúp tránh phải viết std:: trước các hàm như cout, cin

// Định nghĩa lớp Ngay
class Ngay {
    int ngay, thang, nam;  // Các thuộc tính riêng tư (private) đại diện cho ngày, tháng, năm

public:
    // ===== Getter và Setter ===== //
    int getNgay() { return ngay; }             // Lấy giá trị ngày
    void setNgay(int x) { ngay = x; }          // Gán giá trị cho ngày
    int getThang() { return thang; }           // Lấy giá trị tháng
    void setThang(int x) { thang = x; }        // Gán giá trị cho tháng
    int getNam() { return nam; }               // Lấy giá trị năm
    void setNam(int x) { nam = x; }            // Gán giá trị cho năm

    // ===== Constructor và Destructor ===== //
    Ngay(int _ngay = 01, int _thang = 01, int _nam = 1900) {
        // Hàm khởi tạo có tham số mặc định: nếu không truyền vào thì mặc định là 1/1/2000
        ngay = _ngay;
        thang = _thang;
        nam = _nam;
    }

    Ngay(const Ngay& n) {  // Constructor sao chép
        ngay = n.ngay;
        thang = n.thang;
        nam = n.nam;
    }

    ~Ngay() {}  // Destructor (ở đây không cần giải phóng tài nguyên gì nên để trống)

    // ===== Kiểm tra ngày hợp lệ ===== //
    bool hopLe() {
        int ngayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Kiểm tra năm nhuận: nếu đúng thì tháng 2 có 29 ngày
        if (nam % 4 == 0 && (nam % 100 != 0 || nam % 400 == 0)) {
            ngayTrongThang[1] = 29;
        }

        // Nếu tháng không hợp lệ
        if (thang < 1 || thang > 12) return false;

        // Nếu ngày không hợp lệ trong tháng đó
        if (ngay < 1 || ngay > ngayTrongThang[thang - 1]) return false;

        return true; // Ngày hợp lệ
    }

    // ===== Tìm ngày kế tiếp ===== //
    Ngay ngayKeTiep() {
        Ngay next = *this; // Tạo bản sao đối tượng hiện tại
        next.ngay++;       // Tăng ngày lên 1

        // Nếu sau khi tăng không hợp lệ thì chuyển sang tháng sau
        if (!next.hopLe()) {
            next.ngay = 1;
            next.thang++;
            // Nếu tháng tăng vượt 12 thì chuyển năm
            if (next.thang > 12) {
                next.thang = 1;
                next.nam++;
            }
        }

        return next;
    }

    // ===== Toán tử nhập (>>) ===== //
    friend istream& operator>>(istream& is, Ngay& n) {
        is >> n.ngay >> n.thang >> n.nam; // Nhập 3 số theo thứ tự ngày, tháng, năm
        return is;
    }

    // ===== Toán tử xuất (<<) ===== //
    friend ostream& operator<<(ostream& os, const Ngay& n) {
        if (n.ngay < 10) os << "0";  // Nếu ngày < 10 thì in thêm số 0 phía trước
        os << n.ngay << "/";

        if (n.thang < 10) os << "0"; // Nếu tháng < 10 thì in thêm số 0 phía trước
        os << n.thang << "/";

        os << n.nam;  // In năm
        return os;
    }

    // ===== Tìm ngày cách đó k ngày ===== //
    Ngay ngayCachKNgay(int k) const {
        Ngay kq(*this);  // Tạo bản sao từ ngày hiện tại
        while (k > 0) {
            kq = kq.ngayKeTiep();  // Mỗi vòng lặp tăng 1 ngày
            k--;
        }
        return kq;
    }

    // ===== Tính tổng số ngày kể từ 01/01/0001 ===== //
    int demNgay() const {
        int totalDays = 0;
        int ngayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Tính tổng ngày của các năm trước
        for (int y = 1; y < nam; y++) {
            totalDays += 365;
            if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
                totalDays += 1; // Năm nhuận
        }

        // Tính tổng ngày của các tháng trước trong năm hiện tại
        for (int m = 1; m < thang; m++) {
            totalDays += ngayTrongThang[m - 1];
            if (m == 2 && (nam % 4 == 0 && (nam % 100 != 0 || nam % 400 == 0)))
                totalDays += 1;
        }

        // Cộng ngày hiện tại
        totalDays += ngay;

        return totalDays;
    }

    // ===== Tính khoảng cách giữa hai ngày ===== //
    int khoangCach(const Ngay& n) const {
        return abs(this->demNgay() - n.demNgay());
    }

    // ===== Tìm ngày lớn nhất trong mảng ===== //
    Ngay timNgayLonNhat(Ngay arr[], int n) {
        if (n <= 0) return Ngay(); // Nếu mảng rỗng thì trả về mặc định

        Ngay max = arr[0];
        for (int i = 1; i < n; i++) {
            // So sánh ngày nào "lớn hơn" thông qua số ngày kể từ 1/1/0001
            if (arr[i].demNgay() > max.demNgay()) {
                max = arr[i];
            }
        }
        return max;
    }
};

// ===== Chương trình chính ===== //
int main() {
    Ngay a, b;
    cout << "Nhap ngay a (dd mm yyyy): ";
    cin >> a;  // Nhập ngày a

    cout << "Nhap ngay b (dd mm yyyy): ";
    cin >> b;  // Nhập ngày b

    cout << "Ngay a: " << a << endl;
    cout << "Ngay b: " << b << endl;

    cout << "Ngay tiep theo cua a: " << a.ngayKeTiep() << endl;
    cout << "Ngay cach a 10 ngay: " << a.ngayCachKNgay(10) << endl;
    cout << "Khoang cach giua a va b: " << a.khoangCach(b) << " ngay" << endl;

    // Mảng ngày
    Ngay dates[] = { a, b };
    int n = sizeof(dates) / sizeof(dates[0]);

    // Tìm ngày lớn nhất
    Ngay ngayMax = a.timNgayLonNhat(dates, n);
    cout << "Ngay lon nhat trong mang: " << ngayMax << endl;

    return 0;
}