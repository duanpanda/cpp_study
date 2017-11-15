#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
  vector<int> vec;		// empty vector
  // ok: back_inserter creates an insert iterator that adds elements to vec
  fill_n(back_inserter(vec), 10, 2); // appends 10 elements to vec
  for (int i = 0; i < 10; ++i) {
    cout << vec.at(i) << endl;
  }

  return 0;
}
