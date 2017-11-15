#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main()
{
  list<string> roster1;
  vector<char*> roster2;

  roster1.push_back("i love you");
  roster1.push_back("I love you");
  roster1.push_back("keep in touch with");
  roster1.push_back("roster1 ends here");

  roster2.push_back("no ?");	// warning: deprecated conversion from string constant to 'char*'
  roster2.push_back("i love you");
  roster2.push_back("ok i will go");
  roster2.push_back("keep in touch with");
  roster2.push_back("roster2 ends here");

  // program for illustration purposes only:
  // there are much faster ways to solve this problem
  size_t cnt = 0;
  list<string>::iterator it = roster1.begin();
  // look in roster1 for any name also in roster2
  while ((it = find_first_of(it, roster1.end(),
			     roster2.begin(), roster2.end()))
	 != roster1.end()) {
    ++cnt;
    // we got a match, increment it to look in the rest of roster1
    ++it;
  }
  cout << "Found " << cnt << " names on both rosters" << endl;
  return 0;
}
