#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class DIEM{
    int n;
    float arr[10];
public:
    //get-set
    void setN(int value){ n=value;}
    int getN()  { return n;}
    float& operator[](int index){return arr[index];}
    
    // Constructor mặc định, tham số, sao chép
    DIEM(int _n=3, float _arr[]=NULL){
        n=_n;
        if(_arr == NULL) {
            for(int i=0; i<n; i++) arr[i] = 0;
        } else {
            for(int i=0; i<n; i++) arr[i]= _arr[i];
        }
    }
    DIEM(const DIEM &d){
        n=d.n;
        for(int i=0; i<n; i++) arr[i]= d.arr[i];
    }
    
    // Toán tử gán
    DIEM& operator=(const DIEM &d){
        if (this != &d) {
            n = d.n;
            for(int i = 0; i < n; i++) arr[i] = d.arr[i];
        }
        return *this;
    }
    
    // Destructor
    ~DIEM() {}
    
    // Nhập - Xuất
    friend istream& operator>>(istream &is, DIEM &d){
        d.n=0;
        float temp;
        while(d.n < 10 && is >> temp) {
            d.arr[d.n++] = temp;
            if(is.peek() == '\n') break;
        }
        return is;
    }
    friend ostream& operator<<(ostream &os, DIEM d){
        for(int i = 0; i<d.n; i++) os << d.arr[i]<<" ";
        os<<endl;
        return os;
    }
    
    // Hàm hỗ trợ
    float DTB() const {
        if (n == 0) return 0;
        float tong=0;
        for(int i=0; i<n; i++) tong+=arr[i];
        return tong/n;
    }
};

class SV{
    DIEM d;
    string hoten, mssv;
public:
    //get-set
    string getHoten() { return hoten; }
    void setHoten(string _hoten) { hoten = _hoten; }
    string getMssv() { return mssv; }
    void setMssv(string _mssv) { mssv = _mssv; }
    DIEM getDiem() { return d; }
    void setDiem(DIEM _d) { d = _d; }
    
    // Constructor mặc định, tham số, sao chép
    SV(const SV &s){ mssv = s.mssv; hoten = s.hoten; d = s.d; }
    SV(string _hoten="hoten", string _mssv="mssv", DIEM _d= DIEM()){
        hoten=_hoten; mssv=_mssv; d= _d;
    }
    
    // Toán tử gán
    SV& operator=(const SV &s){
        if (this != &s) {
            hoten = s.hoten;
            mssv = s.mssv;
            d = s.d;
        }
        return *this;
    }
    
    // Toán tử so sánh < dựa vào DTB
    bool operator<(const SV &s) const {
        return d.DTB() < s.d.DTB();
    }
    
    // Destructor
    ~SV() {}
    
    // Nhập - Xuất
    friend istream& operator>>(istream &is, SV &s){
        getline(is, s.hoten);
        getline(is, s.mssv);
        is >> s.d;
        is.ignore(); // Consume newline after scores
        return is;
    }
    friend ostream& operator<<(ostream &os, SV s){
        os<<"Ho Ten: "<< s.hoten <<endl;
        os<<"Ma Sinh Vien: "<< s.mssv<<endl;
        os<<"DTB: "<<fixed << setprecision(1) << s.d.DTB()<<endl;
        return os;
    }
};

class MangSinhVien {
    SV arr[100]; // Mảng 1 chiều kiểu sinh viên
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
