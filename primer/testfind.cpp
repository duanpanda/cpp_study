#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // value we'll look for
  int search_value = 42;

  int vals[] = { 1, 2, 3, 80, 42, 42, 24 };
  vector<int> vec(vals, vals + 7);

  // call find to see if that value is present
  vector<int>::const_iterator result =
    find(vec.begin(), vec.end(), search_value);

  // report the result
  cout << "The value " << search_value
       << (result == vec.end() ? " is not present" : " is present")
       << endl;

  return 0;
}
