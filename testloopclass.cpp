#include <iostream>

class A
{
public:
    A() : p(this) {}
    ~A() {
        if (p != 0) {
            delete p;
            // p = 0;
        }
    }
private:
    A * p;
};

int main()
{
    A a;
    std::cout << "done" << std::endl;
    // This program will cause "Segmentation fault".
    return 0;
}
