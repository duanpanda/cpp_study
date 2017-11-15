#include <iostream>
#include <cstring>
using namespace std;

struct A
{
    short count;
    short length;
    char  str[1];
};


int main()
{
    const char hello[] = "hello, world";
    size_t len = sizeof(struct A) + strlen(hello) + 1;
    cout << "sizeof(struct A) = " << sizeof(struct A) << '\n'
         << "strlen(hello) = " << strlen(hello) << '\n'
         << "len = " << len
         << endl;
    A* pa = (A*)new char[len];
    strcpy(pa->str, hello);
    cout << pa->str << endl;
    delete[] pa;
    return 0;
}
