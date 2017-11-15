#include <iostream>
#include <memory>
using namespace std;

void func2(auto_ptr<int> v)
{
}

int main()
{
    auto_ptr<int> pv(new int(5));
    // Passed the ownership to the local scope of func2().
    // func2(pv);
    cout << *pv << ' ' << pv.get() << endl;
    return 0;
}
