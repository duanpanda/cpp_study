#include <iostream>
#include <algorithm>
// #include <vector>
#include <list>
using namespace std;

int main()
{
  string n;
  string search_value;
  list<string> sv;
  int cnt;
  cin >> search_value;
  while (cin >> n) {
    sv.push_back(n);
  }
  cnt = count(sv.begin(), sv.end(), search_value);
  cout << cnt << endl;
  return 0;
}
