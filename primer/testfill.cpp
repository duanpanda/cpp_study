#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  vector<int> iv(10);
  for (int i = 0; i < 10; ++i) {
    cout << iv.at(i) << endl;
  }

  fill(iv.begin(), iv.begin() + iv.size() / 2, 10);
  cout << '\n';
  for (int i = 0; i < 10; ++i) {
    cout << iv.at(i) << endl;
  }
  
  return 0;
}
