#include <iostream> 
#include <iomanip>  
#include <string>    
using namespace std; 

// Lớp Người
class Nguoi {
protected:
    string hoTen;  
    int namSinh;   
    string queQuan; 

public:
    // Constructor mặc định
    Nguoi() {
        hoTen = "";
        namSinh = 0;
        queQuan = "";
    }

    // Constructor có tham số
    Nguoi(string _hoTen, int _namSinh, string _queQuan) {
        hoTen = _hoTen;
        namSinh = _namSinh;
        queQuan = _queQuan;
    }

    // Destructor (hàm hủy)
    ~Nguoi() {}

    // Các hàm get (truy xuất thông tin)
    string getHoTen() { return hoTen; }
    int getNamSinh() { return namSinh; }
    string getQueQuan() { return queQuan; }

    // Các hàm set (thay đổi thông tin)
    void setHoTen(string _hoTen) { hoTen = _hoTen; }
    void setNamSinh(int _namSinh) { namSinh = _namSinh; }
    void setQueQuan(string _queQuan) { queQuan = _queQuan; }

    // Hàm nhập thông tin từ bàn phím
    void nhap() {
        getline(cin, hoTen);  /
        cin >> namSinh;       
        cin.ignore();        
        getline(cin, queQuan); 
    }

    // Hàm xuất thông tin ra màn hình
    void xuat() {
        cout << "Ho Ten: " << hoTen << endl;
        cout << "Nam Sinh: " << namSinh << endl;
        cout << "Que quan: " << queQuan << endl;
    }

    // Quá tải toán tử nhập >>
    friend istream& operator>>(istream& is, Nguoi& nguoi) {
        getline(is, nguoi.hoTen); 
        is >> nguoi.namSinh;    
        is.ignore();              // Bỏ ký tự '\n'
        getline(is, nguoi.queQuan);
        return is; 
    }

    // Quá tải toán tử xuất <<
    friend ostream& operator<<(ostream& os, const Nguoi& nguoi) {
        os << "Ho Ten: " << nguoi.hoTen << endl;
        os << "Nam Sinh: " << nguoi.namSinh << endl;
        os << "Que quan: " << nguoi.queQuan << endl;
        return os; 
    }
};

// Lớp SinhVien kế thừa từ Nguoi
class SinhVien : public Nguoi {
private:
    string khoa;      
    float diem[100];  
    int soMon;        

public:
    // Constructor mặc định
    SinhVien() : Nguoi() {
        khoa = "";
        soMon = 0;
    }

    // Constructor có tham số
    SinhVien(string _hoTen, int _namSinh, string _queQuan, string _khoa)
        : Nguoi(_hoTen, _namSinh, _queQuan) { 
        khoa = _khoa;
        soMon = 0;
    }

    // Destructor
    ~SinhVien() {}

    // Hàm get và set cho khoa
    string getKhoa() { return khoa; }
    void setKhoa(string _khoa) { khoa = _khoa; }

    // Hàm tính điểm trung bình
    float tinhDiemTB() const {
        if (soMon == 0) return 0.0f;
        float tong = 0;
        for (int i = 0; i < soMon; i++) tong += diem[i];
        return tong / soMon; 
    }

    // Hàm nhập thông tin sinh viên
    void nhap() {
        Nguoi::nhap(); 
        getline(cin, khoa); 
        soMon = 0;
        while (cin >> diem[soMon]) { 
            soMon++;
            char c;
            if (cin.get(c) && c == '\n') break;
        }
    }

    // Hàm xuất thông tin sinh viên
    void xuat() {
        Nguoi::xuat();
        cout << "Khoa: " << khoa << endl;
        cout << "Diem cac mon:";
        for (int i = 0; i < soMon; i++) {
            cout << " " << fixed << setprecision(0) << diem[i]; 
        }
        cout << endl;
        cout << "Diem trung binh: " << fixed << setprecision(2) << tinhDiemTB() << endl; 
    }

    // Quá tải istream
    friend istream& operator>>(istream& is, SinhVien& sv) {
        // Gọi lại hàm nhập của lớp cha
        is >> sv.hoTen;
        is >> sv.namSinh;
        is.ignore(); // bỏ dòng sau năm sinh
        getline(is, sv.queQuan);

        // Nhập thông tin riêng của SinhVien
        getline(is, sv.khoa);
        sv.soMon = 0;
        while (is >> sv.diem[sv.soMon]) {
            sv.soMon++;
            char c;
            if (is.get(c) && c == '\n') break;
        }
        return is;
    }

    // Quá tải ostream
    friend ostream& operator<<(ostream& os, const SinhVien& sv) {
        // Gọi lại hàm xuất của lớp cha
        os << "Ho Ten: " << sv.hoTen << endl;
        os << "Nam Sinh: " << sv.namSinh << endl;
        os << "Que quan: " << sv.queQuan << endl;
        // Xuất thông tin riêng của SinhVien
        os << "Khoa: " << sv.khoa << endl;
        os << "Diem cac mon:";
        for (int i = 0; i < sv.soMon; i++) {
            os << " " << fixed << setprecision(0) << sv.diem[i];
        }
        os << endl;
        os << "Diem trung binh: " << fixed << setprecision(2) << sv.tinhDiemTB() << endl;
        return os;
    }
};

// Hàm main - chương trình chính
int main() {
    SinhVien sv; 
    cin >> sv;   
    cout << sv;
    return 0;   
}
