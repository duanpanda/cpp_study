#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
using namespace std;

int main()
{
  vector<int> vec;		// empty vector
  vec.reserve(40);
  cout << "vector size: " << vec.size()
       << " vector capacity: " << vec.capacity() << endl;
  // disaster: attempts to write to 10 (nonexistent) elements in vec
  fill_n(vec.begin(), 10, 0);	// If not used reserve(),
				//     then segmentation fault on Linux.
				// else no segmentation fault, but
				//     the vector size is still 0!
  try {
    for (int i = 0; i < 10; ++i) {
      cout << vec.at(i) << endl;
    }
  }
  catch (const out_of_range& e) {
    cout << "vector size: " << vec.size() << '\n'
	 << e.what() << endl;
  }

  return 0;
}
