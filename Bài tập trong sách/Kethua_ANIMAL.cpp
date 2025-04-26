 /*
Câu 2: Xây dựng các lớp đối tượng sau theo yêu cầu.
Lớp ANIMAL để biểu diễn các đối tượng là một con vật với thành phần dữ liệu và các phương thức sau:

Thành phần dữ liệu:

age (tuổi – số nguyên)

weight (cân nặng – số thực)

sex (giới tính – số nguyên, với 0 là male hoặc 1 là female)

Các phương thức:

Phương thức thiết lập và phương thức hủy bỏ.

Phương thức void set(int, float, int) để xác định các thông tin về con vật.

Phương thức void an() hiện câu "Con vat dang an".

Phương thức void print() hiện thông tin con vật.

Lớp ELEPHANT để biểu diễn các đối tượng là một con voi được kế thừa từ lớp ANIMAL với thành phần dữ liệu và các phương thức bổ sung sau:

Thành phần dữ liệu:

root (xuất xứ của voi – số nguyên; 0: châu Á, 1: châu Phi)

Các phương thức:

Phương thức thiết lập và phương thức hủy bỏ.

Phương thức void set(int, float, int, int) để xác định các thông tin về con voi.

Phương thức void print() hiện thông tin về con voi.

Phương thức void an() hiện câu "Voi dang an co".
*/


#include <iostream>
using namespace std;

// Lớp ANIMAL
class ANIMAL {
    int age;
    float weight;
    int sex; // 0: male, 1: female
public:
    int getAge() { return age; };
    void setAge(int a) { age = a; };
    float getWeight() { return weight; };
    void setWeight(float w) { weight = w; };
    int getSex() { return sex; };
    void setSex(int s) { sex = s; };

    ANIMAL(int _age = 0, float _weight = 0.0, int _sex = 0) {
        age = _age;
        weight = _weight;
        sex = _sex;
    };
    ANIMAL(const ANIMAL& a) {
        age = a.age;
        weight = a.weight;
        sex = a.sex;
    };
    ~ANIMAL() {};

    void set(int a, float w, int s) {
        age = a;
        weight = w;
        sex = s;
    };

    void an() {
        cout << "Con vat dang an" << endl;
    };

    void print() {
        cout << "Tuoi: " << age << endl;
        cout << "Can nang: " << weight << " kg" << endl;
        cout << "Gioi tinh: ";
        if (sex == 0) {
            cout << "Male" << endl;
        }
        else {
            cout << "Female" << endl;
        }
    };

    friend istream& operator>>(istream& in, ANIMAL& a) {
        in >> a.age >> a.weight >> a.sex;
        return in;
    };

    friend ostream& operator<<(ostream& out, ANIMAL a) {
        out << "Tuoi: " << a.age << endl;
        out << "Can nang: " << a.weight << " kg" << endl;
        out << "Gioi tinh: ";
        if (a.sex == 0) {
            out << "Male" << endl;
        }
        else {
            out << "Female" << endl;
        }
        return out;
    };
};

// Lớp ELEPHANT kế thừa ANIMAL
class ELEPHANT : public ANIMAL {
    int root; // 0: Châu Á, 1: Châu Phi
public:
    int getRoot() { return root; };
    void setRoot(int r) { root = r; };

    ELEPHANT(int _age = 0, float _weight = 0.0, int _sex = 0, int _root = 0)
        : ANIMAL(_age, _weight, _sex) {
        root = _root;
    };
    ELEPHANT(const ELEPHANT& e) : ANIMAL(e) {
        root = e.root;
    };
    ~ELEPHANT() {};

    void set(int a, float w, int s, int r) {
        ANIMAL::set(a, w, s);
        root = r;
    };

    void an() {
        cout << "Voi dang an co" << endl;
    };

    void print() {
        ANIMAL::print();
        cout << "Xuat xu: ";
        if (root == 0) {
            cout << "Chau A" << endl;
        }
        else {
            cout << "Chau Phi" << endl;
        }
    };

    friend istream& operator>>(istream& in, ELEPHANT& e) {
        int age, sex, root;
        float weight;
        in >> age >> weight >> sex >> root;
        e = ELEPHANT(age, weight, sex, root);
        return in;
    };

    friend ostream& operator<<(ostream& out, ELEPHANT e) {
        out << "Thong tin voi: " << endl;
        e.print();
        return out;
    };
};

int main() {
    ELEPHANT e1, e2;
    cin >> e1;
    cin >> e2;

    cout << "Thong tin voi 1:\n" << e1;
    e1.an();
    cout << endl;
    cout << "Thong tin voi 2:\n" << e2;
    e2.an();

    return 0;
}