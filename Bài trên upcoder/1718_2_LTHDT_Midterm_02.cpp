#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
    int id;
    string firstName, lastName;
    double salary;
public:
    int getID() { return id; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    string getName() { return firstName + " " + lastName; }
    double getSalary() { return salary; }
    void setSalary(double salary) { salary = salary; }
    double getAnnualSalary() { return salary * 12; }
    double raiseSalary(double percent) {
        salary *= (1.0 + percent / 100);
        return salary;
    }

    Employee(int _id = 1, string _firstName = "f", string _lastName = "l", double _salary = 1) {
        id = _id; firstName = _firstName; lastName = _lastName;
        salary = _salary;
    }
    Employee(const Employee& em) {
        id = em.id; firstName = em.firstName; lastName = em.lastName;
        salary = em.salary;
    }
    ~Employee() {}

    friend istream& operator >> (istream& is, Employee& em) {
        is >> em.id;
        is >> em.firstName >> em.lastName;
        is >> em.salary;
        return is;
    }

    friend ostream& operator << (ostream& os, Employee em) {
        os << "Employee[id= " << em.id << ",name= " << em.getName() << ",salary= $";
        cout << fixed << setprecision(2);
        os << em.salary;
        os << "]" << endl;
        return os;
    }

    string toString() {
        //“Employee[id=?,name=firstName lastName,salary=?]”;
        string s = "Employee[id= " + to_string(id) + ",name= "
            + getName() + ",salary= $";
        cout << fixed << setprecision(2);
        s += to_string(salary);
        return s;
    }
    //Doc lai code bai PhanSo trong giao trinh: ++ , -- 
    Employee operator ++() { //++a
        salary *= 1.1;
        return *this;
    }
    //++ => a = a + 1 => a+=1 => a++
    Employee operator ++(int) { //a++
        Employee tmp = *this;  //tao ban sao 
        salary *= 1.1;         //ban goc tang    
        return tmp;            //tra ve ban sao chua tang    
    }

    Employee operator --() {
        salary *= 0.9;
        return *this;
    }
    Employee operator --(int) {
        Employee tmp = *this;
        salary *= 0.9;
        return tmp;
    }
    Employee operator +(double k) {
        salary += k;
        return *this;
    }
    Employee operator -(double k) {
        salary -= k;
        return *this;
    }

    bool operator > (Employee em1) {
        return (getAnnualSalary() > em1.getAnnualSalary());
    }
    bool operator < (Employee em1) {
        return (getAnnualSalary() < em1.getAnnualSalary());
    }
    bool operator == (Employee em1) {
        return (getAnnualSalary() == em1.getAnnualSalary());
    }
    bool operator != (Employee em1) {
        return (getAnnualSalary() != em1.getAnnualSalary());
    }
};
int main() {
    Employee em1, em2;
    //cout<<em;
    cin >> em1 >> em2;
    cout << em1 << em2;
    double a, b; cin >> a >> b;

    if (em1 > em2) cout << "LON HON" << endl;
    else if (em1 == em2) cout << "BANG NHAU" << endl;
    else cout << "NHO HON" << endl;

    cout << "$" << (em1++ - a).getSalary() << endl;
    cout << "$" << (--em2 + b).getSalary() << endl;//bổ sung thêm trên đề thiếu!

    return 0;
}