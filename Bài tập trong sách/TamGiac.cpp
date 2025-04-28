#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Lớp Point biểu diễn điểm trong mặt phẳng
class Point {
public:
    int x, y;
    // Constructor với tham số mặc định là 0
    Point(int x_tam = 0, int y_tam = 0) {
        x = x_tam;
        y = y_tam;
    }
};


class TamGiac {
private:
    Point A, B, C;
    double canh1, canh2, canh3;
public:
    // Constructor mặc định
    TamGiac() {
        cout << "Đối tượng được tạo ra ở đây" << endl;
    }
    // Destructor (hàm hủy) khi đối tượng bị xóa
    ~TamGiac() {
        cout << "Đối tượng bị hủy ở đây";
    }

    // Hàm thiết lập 3 điểm của tam giác
    void set(int xA, int yA, int xB, int yB, int xC, int yC) {
        A.x = xA; A.y = yA;
        B.x = xB; B.y = yB;
        C.x = xC; C.y = yC;
        // Tính độ dài các cạnh theo công thức khoảng cách 2 điểm
        canh1 = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
        canh2 = sqrt(pow(B.x - C.x, 2) + pow(B.y - C.y, 2));
        canh3 = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));
    }

    // Hàm tính chu vi tam giác
    float tinhChuVi() {
        float Chu_Vi = canh1 + canh2 + canh3;
        return Chu_Vi;
    }

    // Hàm tính diện tích tam giác bằng công thức Heron
    float tinhDienTich() {
        double p = (canh1 + canh2 + canh3) / 2;
        double S = sqrt(p * (p - canh1) * (p - canh2) * (p - canh3)); 
        return S;
    }

    // Hàm in ra thông tin tam giác
    void print() {
        cout << "A" << "(" << A.x << ";" << A.y << ")" << endl;
        cout << "B" << "(" << B.x << ";" << B.y << ")" << endl;
        cout << "C" << "(" << C.x << ";" << C.y << ")" << endl;

        // Kiểm tra xem có phải tam giác hợp lệ không
        if (canh1 + canh2 <= canh3 || canh1 + canh3 <= canh2 || canh2 + canh3 <= canh1) {
            cout << "Không phải tam giác" << endl;
            cout << "Chu vi = 0" << endl;
            cout << "Diện tích = 0" << endl;
        }
        else {
           
            cout << "Chu vi = " << fixed << setprecision(2) << tinhChuVi() << endl;
            cout << "Diện tích = " << fixed << setprecision(2) << tinhDienTich() << endl;
        }
    };

    // Toán tử nhập (dùng để nhập tam giác từ bàn phím)
    friend istream& operator>>(istream& is, TamGiac& tg) {
        int xA, yA, xB, yB, xC, yC;
        cout << "Nhap toa do A (x y): ";
        is >> xA >> yA;
        cout << "Nhap toa do B (x y): ";
        is >> xB >> yB;
        cout << "Nhap toa do C (x y): ";
        is >> xC >> yC;
        tg.set(xA, yA, xB, yB, xC, yC); 
        return is;
    }

    // Toán tử xuất (dùng để in tam giác ra màn hình)
    friend ostream& operator<<(ostream& os, TamGiac tg) {
        os << "A(" << tg.A.x << "," << tg.A.y << "), "
            << "B(" << tg.B.x << "," << tg.B.y << "), "
            << "C(" << tg.C.x << "," << tg.C.y << ")";
        return os;
    }

    int phanLoai() {

        /*Tạo 1 biến tạm để gán giá trị là một số thập phân gần bằng 0
        nhằm kiểm tra các điều kiện bởi lẽ các canh1, canh2, canh3 ở đây
        đang là kiểu dữ liệu double đi đôi với sự tính toán của sqrt
        thế nên làm độ dài 3 cạnh bị sai số vậy nên không dùng được
        kiểu kiểm tra ==*/
        const double min_ThapPhan = 1e-9;//10^-9 0,00000001

        //Không phải tam giác
        if (canh1 + canh2 <= canh3 || canh1 + canh3 <= canh2 || canh2 + canh3 <= canh1) {
            return -1;
        }

        // Kiểm tra tam giác vuông cân
        else if (fabs(pow(canh1, 2) - (pow(canh2, 2) + pow(canh3, 2))) < min_ThapPhan && canh2 == canh3 ||
            fabs(pow(canh2, 2) - (pow(canh1, 2) + pow(canh3, 2))) < min_ThapPhan && canh1 == canh3 ||
            fabs(pow(canh3, 2) - (pow(canh1, 2) + pow(canh2, 2))) < min_ThapPhan && canh1 == canh2) {
            return 3; // Tam giác vuông cân
        }
        
        else if (fabs(pow(canh1, 2) - (pow(canh2, 2) + pow(canh3, 2))) < min_ThapPhan ||
            fabs(pow(canh2, 2) - (pow(canh1, 2) + pow(canh3, 2))) < min_ThapPhan ||
            fabs(pow(canh3, 2) - (pow(canh1, 2) + pow(canh2, 2))) < min_ThapPhan) {
            return 1; // Tam giác vuông
        }
        
        else if (canh1 == canh2 && canh2 == canh3) {
            return 4; // Tam giác đều
        }
      
        else if (canh1 == canh2 || canh2 == canh3 || canh1 == canh3) {
            return 2; // Tam giác cân
        }
        else {
            return 0; // Tam giác thường
        }
    }

};

int main() {
    TamGiac tg1;
    /*tg1.set(1, 1, 4, 1, 2.5, 1 + 1.5 * sqrt(3)); Đây là tọa độ của tam giác đều nhưng do tham số
    của hàm set đang là kiểu dữ liệu int(đề yêu cầu) thế nên tọa độ: 1 + 1.5 * sqrt(3) lúc đi vào hàm
    sẽ bị sai số dẫn tới kết quả phân loại sai*/
    tg1.set(0, 0, 2, 0, 0, 2); //Vuông cân 
    //tg1.set(0,0,3,0,0,2); //Vuông
    //tg1.set(0,0,2,3,4,0); //Cân
    //tg1.set(0,0,2,3,0,1); //Thường
    //tg1.set(0,0,1,1,2,2); // Tam giác không hợp lệ 
    tg1.print();
    cout << "Phân loại: " << tg1.phanLoai() << endl;

    return 0;
}
