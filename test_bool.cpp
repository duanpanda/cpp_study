#include <iostream>
using namespace std;

const int FLAG_B = 1 << 1;

int main(int argc, char* argv[])
{
    int a(6);
    int b(a & FLAG_B);
    int c(!!b);
    bool d(b);
    cout << a
         << ' ' << b
         << ' ' << static_cast<bool>(b)
         << ' ' << c
         << ' ' << d
         << endl;
    return 0;
}
