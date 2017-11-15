#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
  vector<double> iv;
  vector<string> sv;
  for (double i = 1.0; i <= 100.0; i += 1.0) {
    iv.push_back(i);
  }
  sv.push_back("i");
  sv.push_back(" love");
  sv.push_back(" you");
  double sum = accumulate(iv.begin(), iv.end(), 0);
  string str_sum = accumulate(sv.begin(), sv.end(), string(""));
  cout << sum << '\n' << str_sum << endl;
  return 0;
}
