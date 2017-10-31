#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

template <typename T>
int WithStatic(T &v1) {
    static int i = 0;
    ++i;
    cout << v1 << endl;
    cout << "i = " << i << endl;
}

int func1();
int func2();

int main() {
    double d = 3.14, d2 = 3.1415;
    float f = 3.1;
    int i = 3;
    string str = "Hello";

    WithStatic(d);
    WithStatic(f);
    WithStatic(i);
    WithStatic(str);
    WithStatic(d2);

    func1();
    func2();
}

int func1() {
    static int i = 0;
    ++i;
    ++i;
    cout << i << "\n";
}

int func2() {
    static int i = 0;
    ++i;
    cout << i << "\n";
}


// The output is:
// 3.14
// i = 1
// 3.1
// i = 1
// 3
// i = 1
// Hello
// i = 1
// 3.1415
// i = 2
// 2
// 1

