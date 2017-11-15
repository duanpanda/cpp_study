// fillzero.cpp
// Exercise 11.6 (page 401, C++ Primer, 4e)
// Using fill_n, write a program to set a sequence of int values to 0.
// @author: Ryan Duan <duanpanda@gmail.com>
// @date: Oct 3, 2009

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> iv;

  for (int i = 0; i < 5; i++) {
    iv.push_back(i);
  }

  fill_n(back_inserter(iv), 3, 0);

  for (int j = 0; j < iv.size(); j++) {
    cout << iv.at(j) << ' ';
  }
  cout << endl;

  return 0;
}
