#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int n;

public:
    // Constructor mặc định và sao chép
    Stack() { n = 0; }

    Stack(const Stack& st) {
        n = st.n;
        for (int i = 0; i < n; i++) {
            arr[i] = st.arr[i];
        }
    }

    // Getter - Setter
    int getSize() {
        return n;
    }

    int get(int index) {
        if (index >= 0 && index < n) {
            return arr[index];
        }
        return -1; // hoặc throw lỗi nếu muốn chặt chẽ hơn
    }

    void set(int index, int value) {
        if (index >= 0 && index < n) {
            arr[index] = value;
        }
    }

    // Các thao tác stack
    void push(int x) {
        if (n < 100) {
            arr[n] = x;
            n++;
        }
    }

    void pop() {
        if (n > 0) {
            n--;
        }
    }

    int top() {
        if (n > 0) {
            return arr[n - 1];
        }
        return -1;
    }

    void clear() {
        n = 0;
    }

    // Nhập - Xuất
    friend istream& operator>>(istream& is, Stack& st) {
        int count, x;
        is >> count;
        for (int i = 0; i < count; i++) {
            is >> x;
            st.push(x);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, Stack st) {
        for (int i = st.n - 1; i >= 0; i--) {
            os << st.arr[i] << " ";
        }
        return os;
    }
};

int main() {
    Stack st;
    cout << "Nhap so luong va cac phan tu: ";
    cin >> st;

    cout << "Stack: " << st << endl;
    cout << "So luong: " << st.getSize() << endl;
    cout << "Top: " << st.top() << endl;

    st.pop();
    cout << "Sau pop: " << st << endl;

    st.set(0, 999);
    cout << "Sau set(0, 999): " << st << endl;

    st.clear();
    cout << "Sau clear: size = " << st.getSize() << endl;

    return 0;
}