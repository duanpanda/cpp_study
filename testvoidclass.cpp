#include <iostream>

class X {};
class Y : public virtual X {};
class Z : public virtual X {};
class A : public Y, public Z {};

int main()
{
    std::cout << "sizeof X yielded " << sizeof(X) << '\n'
              << "sizeof Y yielded " << sizeof(Y) << '\n'
              << "sizeof Z yielded " << sizeof(Z) << '\n'
              << "sizeof A yielded " << sizeof(A)
              << std::endl;
    return 0;
}
